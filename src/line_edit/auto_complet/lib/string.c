/*
** string.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Tue May  2 13:37:09 2017 Camille Gouneau
** Last update Thu May  4 12:00:37 2017 Camille Gouneau
*/

#include  <string.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  "auto_complet.h"

int   my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int   vs(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int   my_strncmp(char *src, char *comp, int nbr)
{
  int i;

  i = 0;
  if (nbr > my_strlen(src) || nbr > my_strlen(comp))
    return (-1);
  while (i < nbr)
    {
      if (src[i] != comp[i])
        return (0);
      i++;
    }
  return (1);
}

char  **my_realloc_star(char **tab)
{
  int i;
  char **str_real;

  i = 0;
  str_real = my_malloc(sizeof(char *) * (vs(tab) + 2));
  str_real[vs(tab) + 1] = NULL;
  str_real[vs(tab)] = NULL;
  while (tab[i])
    {
      str_real[i] = my_malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
      str_real[i][my_strlen(tab[i])] = '\0';
      str_real[i] = my_put_in_char(str_real[i], tab[i]);
      i++;
    }
  i = 0;
  while (tab[i])
    {
      free (tab[i]);
      i++;
    }
  free (tab);
  return (str_real);
}

void  my_fput(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}
