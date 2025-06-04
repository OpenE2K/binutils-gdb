#include <alloca.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

void
sort_cds (unsigned short *arr, size_t sz)
{
  size_t i;

  for (i = 0; i < sz - 1; i++)
    {
      size_t j;
      unsigned short swp;
      unsigned short min = i;
      
      for (j = i + 1; j < sz; j++)
        {
          if (arr[j] < arr[min])
            min = j;
        }

      if (min != i)
        {
          swp = arr[min];
          arr[min] = arr[i];
          arr[i] = swp;
        }
          
    }
}

int
compare_cds (unsigned short *lhs, unsigned short *rhs, size_t sz)
{
  size_t i;
  unsigned short l[6], r[6];

  for (i = 0; i < sz; i++)
    {
      l[i] = lhs[i];
      r[i] = rhs[i];
    }

  sort_cds (l, sz);
  sort_cds (r, sz);

  for (i = 0; i < sz; i++)
    {
      if (l[i] != r[i])
        return 1;
    }

  return 0;
}

int
get_long_lit (unsigned int *syll,
              size_t off,
              size_t lts0,
              long long *val)
{
  unsigned int src2 = (syll[off] & 0x0000ff00) >> 8;

  if ((src2 & 0xfc) == 0xdc)
    {
      /* This should be a 64-bit literal.  */
      size_t idx = src2 & 0x3;
      unsigned int *ptr;

      if (idx == 3)
        {
          printf ("Invalid encoding for a 64-bit literal.\n");
          return 1;
        }

      ptr = &syll[lts0 - idx];

      ((unsigned int *) val)[0] = ptr[0];
      ((unsigned int *) val)[1] = ptr[-1];

      ptr[0] = 0;
      ptr[-1] = 0;
      return 0;
    }
  else if ((src2 & 0xfc) == 0xd8)
    {
      /* This is a 32-bit literal.  */
      int *ptr = (int *) (syll + lts0 - (src2 & 0x3));
      *val = (long long) *ptr;
      *ptr = 0;
      return 0;
    }
  else if ((src2 & 0xf8) == 0xd0)
    {
      /* A 16-bit literal.  */
      size_t idx = src2 & 0x3;
      size_t half;
      short *ptr;

      if (idx >= 2)
        {
          printf ("Invalid encoding for a 16-bit literal.\n");
          return 1;
        }


      half = (src2 & 0x4) == 0 ? 0 : 1;
      ptr = (short *) (syll + lts0 - idx) + half;
      *val = (long long) *ptr;

      /* Zero out an already compared LTS so that we can compare it in the most
         primitive way along with other syllables. FIXME: this could potentially
         mask other errors if other ALSes were to refer to it . . .  */
      *ptr = 0;
      return 0;
    }

  return 1;
}

int
compare_alses (unsigned int *l, unsigned int *r, size_t off, size_t lts0)
{
  unsigned long long lsrc2;
  unsigned long long rsrc2;
  
  /* Compare everything except for SRC2 which may be different.  */
  if ((l[off] & 0xffff00ff) != (r[off] & 0xffff00ff))
    return 1;

  if (get_long_lit (l, off, lts0, &lsrc2) != 0
      || get_long_lit (r, off, lts0, &rsrc2) != 0
      || lsrc2 != rsrc2)
    return 1;

  return 0;
}

typedef struct
{
  unsigned mdl : 4;
  unsigned lng : 3;
  unsigned nop : 3;
  unsigned lm : 1;
  unsigned x : 1;
  unsigned s : 1;
  unsigned sw : 1;
  unsigned c : 2;
  unsigned cd : 2;
  unsigned pl : 2;
  unsigned ale : 6;
  unsigned al : 6;
} hs_t;

int
compare_insns (const unsigned int *li, const unsigned int *ri)
{
  size_t i;
  hs_t *hs;
  unsigned int *l;
  unsigned int *r;
  size_t first_als = 0;
  size_t last_als = 0;

#if 0
  /* This one corresponds to LTS{max} in fact.  */
  unsigned int *first_lts = NULL;
#endif /* 0  */

  /* This one points to LTS0.  */
  size_t lts0 = 0;

  size_t len;

  /* For now "identical" instructions are allowed to differ in distribution of
     ALSes only. The number of ALSes as well as of other syllables should be the
     same. Therefore I require them to have identical HS syllables.  */

  if (li[0] != ri[0])
    return 1;

  hs = (hs_t *) li;
  len = ((hs->lng + 1) << 1) - hs->cd;
  lts0 = len - (hs->pl + 1);

  for (i = 0; i < 6; i++)
    {
      if ((hs->al & (1 << i)) != 0)
        {
          if (first_als == 0)
            {
              first_als = hs->s ? 2 : 1;
              last_als = first_als;
            }
          else
            last_als++;
        }
    }

  l = (unsigned int *) alloca (len * sizeof (unsigned int));
  r = (unsigned int *) alloca (len * sizeof (unsigned int));

  for (i = 0; i < len; i++)
    {
      l[i] = li[i];
      r[i] = ri[i];
    }

  for (i = 0; i < len; i++)
    {
      if (l[i] != r[i]
          && (i < first_als
              || i > last_als
              || compare_alses (l, r, i, lts0) != 0))
        break;
    }

  if (i < len)
    return 1;

  return 0;
}

int
diffcode (void *lhs, size_t lsz, void *rhs, size_t rsz)
{
  int res = 0;
  size_t i;
  /* Count instructions starting with 1.  */
  int insn = 1;
  size_t msz = (lsz < rsz ? lsz : rsz) >> 2;
  unsigned int *l = (unsigned int *) lhs;
  unsigned int *r = (unsigned int *) rhs;

  if (lsz != rsz)
    {
      puts ("Text segments under comparison have different sizes");
      res = 1;
    }

  for (i = 0; i < msz;)
    {
      size_t j;
      size_t llng = (size_t) ((((l[i] >> 4) & 0x7) + 1) << 1);
      size_t rlng = (size_t) ((((r[i] >> 4) & 0x7) + 1) << 1);
      size_t cd = (size_t) ((l[i] >> 16) & 0x3);

      if (cd >= llng)
        {
          printf (("Invalid combination of HS.{lng,cd} in instruction #%d "
                   "at offset 0x%lx. Stopping comparison\n"),
                  insn, (long) (i << 2));
          res = 1;
          break;
        }

      if (llng != rlng)
        {
          printf (("Length of instructions #%d at offset 0x%lx differ. "
                   "Further comparison doesn't make any sense.\n"),
                  insn, (long) (i << 2));
          res = 1;
          break;                   
        }

      for (j = i; j < i + llng - cd; j++)
        {
          if (l[j] != r[j])
            {
              res = compare_insns (&l[i], &r[i]);

              if (res)
                printf ("Instructions #%d at offset 0x%lx differ\n",
                        insn, (long) (i << 2));

              /* Adjust J appropriately so as not to disturb the subsequent
                 comparison of CDS syllables.  */
              j = i + llng - cd;
              break;
            }
        }

      if (cd != 0 && compare_cds ((unsigned short *) &l[j],
                                  (unsigned short *) &r[j], cd << 1) != 0)
        {
          printf ("CDS of instructions #%d at offset 0x%lx differ\n",
                  insn, (long) (i << 2));
          res = 1;
        }

      /* Advance offset to the start of the next instruction.  */
      i += llng;

      /* Increase instruction number.  */
      insn++;
    }

  return res;
}

int
main (int argc, char **argv)
{
  int res = 0;
  int i;
  int fd[2] = {-1, -1};
  struct stat fs[2];
  void *code[2] = {NULL, NULL};

  for (i = 0; i < 2; i++)
    {
      if ((fd[i] = open (argv[i + 1], O_RDONLY)) == -1
          || fstat (fd[i], &fs[i]) == -1)
        break;
    }
  
  if (i < 2)
    {
      res = 1;
      goto close_files;
    }

  for (i = 0; i < 2; i++)
    {
      if ((code[i] = mmap (NULL, fs[i].st_size, PROT_READ, MAP_PRIVATE, fd[i],
                           0)) == MAP_FAILED)
        break;
    }

  if (i < 2)
    {
      res = 2;
      goto unmap_files;
    }

  if (diffcode (code[0], (size_t) fs[0].st_size,
                code[1], (size_t) fs[1].st_size) != 0)
    res = 3;


 unmap_files:
  for (i = 0; i < 2; i++)
    {
      if (code[i] != NULL)
        munmap (code[i], fs[i].st_size);
    }
  
 close_files:
  for (i = 0; i < 2; i++)
    {
      if (fd[i] != -1)
        close (fd[i]);
    }

  return res;
}
