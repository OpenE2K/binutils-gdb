#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct row
{
  char mnemo[3][32];
};

struct table
{
  struct row r[128];
};

int
read_file (const char *name, struct table *tab)
{
  int i;

  FILE *stream = fopen (name, "r");
  if (stream == NULL)
    return 0;

  for (i = 0; i < 64;)
    {
      int res;
      int op1, op2;
      static char s[18][32];
      const char *src;
      char *tmp = NULL, *line;
      int len;
      size_t n;
      int idx, nitems;
      int j;

      getline (&tmp, &n, stream);
      if (tmp[0] != '|')
        {
          free (tmp);
          continue;
        }

      len = strlen (tmp);
      line = (char *) malloc (len + 48);

      for (j = idx = 0; j < len; j++)
        {
          if (tmp[j] == '|')
            {
              line[idx++] = ' ';
              line[idx++] = '|';
              line[idx++] = ' ';
            }
          else if (tmp[j] == ')')
            {
              line[idx++] = ')';
              line[idx++] = ' ';
              line[idx++] = '|';
              line[idx++] = ' ';
            }
          else
            line[idx++] = tmp[j];

        }

      line[idx] = '\0';

      free (tmp);
      nitems = sscanf (line,
                       "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                       s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8],
                       s[9], s[10], s[11], s[12], s[13], s[14], s[15], s[16],
                       s[17]);

      free (line);

      if (nitems < 12)
        abort ();

      for (j = 0, idx = 0; j < 2; j++)
        {
          int k;

          if (strcmp (s[idx], "|") != 0 || strcmp (s[idx + 2], "|") != 0)
            abort ();

          if (strtol (s[idx + 1], NULL, 16) != i + j * 64)
            abort ();

          idx += 3;

          for (k = 0; k < 3; k++)
            {
              if (strcmp (s[idx], "|") != 0)
                src = s[idx++];
              else
                src = "";

              strncpy (tab->r[i + j * 64].mnemo[k], src, 32);

              if (strcmp (s[idx++], "|") != 0)
                abort ();
            }
        }

      if (idx != nitems)
        abort ();

      i++;
    }

  fclose (stream);

  return i == 64;
}

#define NUM_TABLES 17

struct table tables[NUM_TABLES];
const char *table_names[NUM_TABLES] =
  {
    "short-v1",
    "short-v2",
    "short-v3",
    "short-v4",
    "short-v5",
    "short-v6",
    "long-v1",
    "long-v2",
    "long-v3",
    "long-v4",
    "long-v5",
    "long-v6",
    "long-ext1-v3",
    "long-ext1-v4",
    "long-ext1-v5",
    "long-ext1-v6",
    "long-ext2-v6"
  };

struct cookie
{
  int n;
  struct {
    struct table *tab;
    const char *desc;
  } items[];
};

struct cookie short_cookie =
  {
    6,
    {{&tables[0], "elbrus_v1_short_opers"},
     {&tables[1], "elbrus_v2_short_opers"},
     {&tables[2], "elbrus_v3_short_opers"},
     {&tables[3], "elbrus_v4_short_opers"},
     {&tables[4], "elbrus_v5_short_opers"},
     {&tables[5], "elbrus_v6_short_opers"}
    }
  };

struct cookie long_cookie =
  {
    6,
    {{&tables[6], "elbrus_v1_long_opers"},
     {&tables[7], "elbrus_v2_long_opers"},
     {&tables[8], "elbrus_v3_long_opers"},
     {&tables[9], "elbrus_v4_long_opers"},
     {&tables[10], "elbrus_v5_long_opers"},
     {&tables[11], "elbrus_v6_long_opers"}
    }
  };


struct cookie long_ext1_cookie =
  {
    4,
    {{&tables[12], "elbrus_v3_long_ext1_opers"},
     {&tables[13], "elbrus_v4_long_ext1_opers"},
     {&tables[14], "elbrus_v5_long_ext1_opers"},
     {&tables[15], "elbrus_v6_long_ext1_opers"}
    }
  };

struct cookie long_ext2_cookie =
  {
    1,
    {
      {&tables[16], "elbrus_v6_long_ext2_opers"}
    }
  };

#define NUM_COOKIES 4
struct cookie *cookies[4] = {&short_cookie, &long_cookie, &long_ext1_cookie,
			     &long_ext2_cookie};

void
intersect (struct table *a, const struct table *b)
{
  int i;
  for (i = 0; i < 128; i++)
    {
      int j;
      for (j = 0; j < 3; j++)
        {
          if (a->r[i].mnemo[j][0] != '\0'
              && strcmp (a->r[i].mnemo[j], b->r[i].mnemo[j]) != 0)
            a->r[i].mnemo[j][0] = '\0';
        }
    }
}

void
subtract (struct table *a, const struct table *b)
{
  int i;
  for (i = 0; i < 128; i++)
    {
      int j;
      for (j = 0; j < 3; j++)
        {
          if (a->r[i].mnemo[j][0] != '\0')
            {
              if( strcmp (a->r[i].mnemo[j], b->r[i].mnemo[j]) == 0)
                {
                  a->r[i].mnemo[j][0] = '\0';
                  continue;
                }
            }

          if (b->r[i].mnemo[j][0] != '\0')
            abort ();
        }
    }

}

/* For each instruction in row R verify that it's the only row per two tables
   in which it's present. Otherwise I'll generate a defective table.  */
void
verify_uniqueness (const struct table **tabs, const struct row *r)
{
  int i;
 
  if (r->mnemo[0][0] == '\0' && r->mnemo[1][0] == '\0'
      && r->mnemo[2][0] == '\0')
    abort ();

  for (i = 0; i < 3; i++)
    {
      int j;
      const char *mnemo;
      int cntr = 0;

      if ((mnemo =r->mnemo[i])[0] == '\0')
        continue;

      for (j = 0; j < 2; j++)
        {
          int k;
          for (k = 0; k < 128; k++)
            {
              int l;
              const struct row *r1 = &tabs[j]->r[k];
              for (l = 0; l < 3; l++)
                {
                  if (r1->mnemo[l][0] == '\0'
                      || strcmp (r1->mnemo[l], r->mnemo[i]) != 0)
                    continue;

                  break;
                }

              /* See if there was a hit.  */
              if (l < 3)
                cntr++;
            }
        }

      if (cntr != 1)
        abort ();
    }
}

void
output (const char *arr_name, const struct table *a, const struct table *b)
{
  int i;
  const struct table *tabs[] = {a, b};
  printf ("e2k_oper %s [] =\n{\n", arr_name);
  for (i = 0; i < 2; i++)
    {
      int j;
      for (j = 0; j < 128; j++)
        {
          int k;
          static const char spaces[] = "                        ";
          const char *align[3];
          const struct row *r = &tabs[i]->r[j];
          if (r->mnemo[0][0] == '\0' && r->mnemo[1][0] == '\0'
              && r->mnemo[2][0] == '\0')
            continue;

          verify_uniqueness (tabs, r);

          for (k = 0; k < 3; k++)
            {
              size_t len;
              if ((len = strlen (r->mnemo[k])) > 24)
                abort ();

              align[k] = &spaces[len];
            }

          printf ("{0x%02x, {{\"%s\", 0},%s{\"%s\", 0},%s{\"%s\", 0}%s}, %d},\n", j,
                  r->mnemo[0], align[0], r->mnemo[1], align[1], r->mnemo[2],
                  align[2], i);
        }
    }
  printf ("};\n\n");
}

int
main ()
{
  int i;
  for (i = 0; i < NUM_TABLES; i++)
    {
      if (read_file (table_names[i], &tables[i]) != 1)
        return 1;
    }

  for (i = 0; i < NUM_COOKIES; i++)
    {
      int j, n = cookies[i]->n;
      for (j = 0; j < n; j++)
        {
          int k;
          struct table tmp = *cookies[i]->items[j].tab;

          for (k = j + 1; k < n; k++)
            intersect (&tmp, cookies[i]->items[k].tab);

          for (k = j; k < n; k++)
            subtract (cookies[i]->items[k].tab, &tmp);

          output (cookies[i]->items[j].desc, &tmp, cookies[i]->items[j].tab);
        }
    }

  return 0;
}
