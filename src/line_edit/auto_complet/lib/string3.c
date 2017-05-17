/*
** string3.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Thu May 11 19:58:37 2017 Camille Gouneau
** Last update Sun May 14 16:38:12 2017 Camille Gouneau
*/

#include  <stdlib.h>
#include  "auto_complet.h"

char  *get_space(char *str)
{
  int i;
  int j;
  char *new_str;

  i = 0;
  j = 0;
  new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  new_str[my_strlen(str)] = '\0';
  while (str[i] != 32 || str[i])
    i++;
  i++;
  while (str[i])
    {
      new_str[j] = str[i];
      i++;
      j++;
    }
  return (new_str);
}

int   my_strncmp_pos(char *str1, char *str2, int size, int pos)
{
  int i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (1);
  if (pos > my_strlen(str1) || pos > my_strlen(str2))
    return (1);
  if (my_strlen(str1) < size || my_strlen(str2) < size)
    return (1);
  while (pos < size + 2)
    {
      if (str1[pos] != str2[i])
        return (1);
      pos++;
      i++;
    }
  return (0);
}
