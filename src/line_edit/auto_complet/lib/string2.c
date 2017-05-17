/*
** string2.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Thu May  4 10:53:37 2017 Camille Gouneau
** Last update Fri May  5 10:39:02 2017 Camille Gouneau
*/

#include  <stdlib.h>
#include  "auto_complet.h"

void  free_path(char **path)
{
  int i;

  i = 0;
  while (path[i])
    {
      free(path[i]);
      i++;
    }
  free(path);
}

int   my_free_struct_2(t_my_auto *p)
{
  free(p->auto_list);
  free (p);
  return (0);
}

void  my_free_struct(t_my_auto *p)
{
  int i;

  i = 0;
  while (p->auto_list[i])
    {
      free(p->auto_list[i]);
      i++;
    }
  free(p->auto_list);
  free(p);
}

char  **my_memset(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    {
      tab[i] = NULL;
      i++;
    }
  return (tab);
}

char  *my_put_in_char(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
