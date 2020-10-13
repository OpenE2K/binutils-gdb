#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void
sort (unsigned short *arr, size_t n)
{
  size_t i;

  for (i = 0; i < n - 1; i++)
    {
      size_t j;

      for (j = i + 1; j < n; j++)
        if (arr[i] > arr[j])
          {
            unsigned short tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
          }
    }
}

static unsigned short
get_cds (const char *str)
{
  int i;
  unsigned short res = 0;
  for (i = 0; i < 4; i++)
    {
      res <<= 4;

      if (str[i] >= '0' && str[i] <= '9')
        res += str[i] - '0';
      else if (str[i] >= 'a' && str[i] <= 'f')
        res += 10 + str[i] - 'a';
      else
        abort ();
    }

  return res;
}

int
main ()
{
  char *buf = NULL;
  size_t n = 0;
  size_t len;
  int cds_num = -1;
  size_t lineno = 0;
  unsigned short cds[6];
  int prior_api = 0;

  // sleep (20);

  while ((len = getline (&buf,  &n, stdin)) != -1 )
    {
      int i;
      size_t syll_start;
      size_t code_end;
      char *open_bracket;
      char *syll;

      ++lineno;

      open_bracket = strchr (buf, '<');
      if (open_bracket != NULL)
        {
          char *close_bracket = strchr (buf, '>');
          size_t addr_len;

          if (close_bracket == NULL)
            abort ();

          addr_len = (close_bracket - buf) - (open_bracket - buf) + 1;
          printf ("%.*s\n", addr_len, open_bracket);
        }

      if ((syll = strstr (buf, " HS ")) != NULL
          || (syll = strstr (buf, " SS")) != NULL
          || (syll = strstr (buf, " ALS")) != NULL
          || (syll = strstr (buf, " CS")) != NULL
          || (syll = strstr (buf, " ALES")) != NULL
          || (syll = strstr (buf, " AAS")) != NULL
          || (syll = strstr (buf, " LTS")) != NULL
          || (syll = strstr (buf, " PLS")) != NULL
          || (syll = strstr (buf, " CDS")) != NULL
          || ((syll = strstr (buf, " API_")) != NULL && (prior_api = 2))
          || (prior_api == 1 && (syll = buf)))
        {
          syll_start = code_end = syll - buf + 1;

          while (code_end < len && buf[code_end] != ' ')
            code_end++;

          while (code_end < len && buf[code_end] == ' ')
            code_end++;

          /* By now I've found the start of a code, advance to its end.  */
          for (i = 0; i < 8; i++)
            {
              if (code_end >= len
                  || ! isxdigit (buf[code_end++]))
                {
                  if (prior_api != 1)
                    abort ();
                  else
                    break;
                }
            }

          if (i < 8 && prior_api == 1)
            continue;

          if (prior_api > 0)
            prior_api--;

        }
      else
        continue;

      if (strncmp (&buf[syll_start], "CDS", 3) != 0
          || (buf[syll_start + 3] != '0'
              && buf[syll_start + 3] != '1'
              && buf[syll_start + 3] != '2' ))
        {
          buf[code_end + 1] = '\0';
          printf ("%09d %s\n", lineno, &buf[syll_start]);
          continue;
        }


      /* FIXME(?): below I make use of the fact that CDS syllable unlike HS
         should always start at 19.  */
      
      i = buf[syll_start + 3] - '0';
      if (cds_num < i)
        cds_num = i;

      cds[2 * i] = get_cds (&buf[code_end - 4]);
      cds[2 * i + 1] = get_cds (&buf[code_end - 8]);

      if (i == 0)
        {
          sort (cds, 2 * (cds_num + 1));

          /* REMINDER: beware that calculated line numbers for CDSx except for
             the last CDS0 may turn out to be incorrect because of the gaps
             between them in the original disassembly. A gap may be required in
             order to output the second instruction encoded in CDS.  */
          for (i = cds_num; i >= 0; i--)
            printf ("%09d CDS%d  %04x%04x\n", lineno - i, i, cds[2 * i + 1],
                    cds[2 * i]);

          cds_num = -1;
        }   
    }

  free (buf);
  return 0;
}
