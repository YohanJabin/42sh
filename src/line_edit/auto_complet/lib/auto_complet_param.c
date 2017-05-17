/*
** auto_complet_param.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Fri May  5 11:47:18 2017 Camille Gouneau
** Last update Sun May 14 16:00:54 2017 Camille Gouneau
*/

#include  <dirent.h>
#include  <sys/types.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "auto_complet.h"

int find_space(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 32)
        return (1);
      i++;
    }
  return (0);
}

char  *remove_space(char *str)
{
  int i;
  int j;
  char *new_str;

  i = 0;
  j = 0;
  while (str[i] != 32)
    i++;
  i++;
  new_str = my_malloc(sizeof(char) * ((my_strlen(str) - i) + 1));
  new_str[my_strlen(str) - i] = '\0';
  while (str[i])
    {
      new_str[j] = str[i];
      i++;
      j++;
    }
  free (str);
  return (new_str);
}

void  auto_complet_param(char *str, t_my_auto *p)
{
  if (my_strncmp(str, "cd", 2) == 1 || my_strncmp(str, "ls", 2) == 1)
    cd_param(str, ".", p);
  else if (my_strncmp(str, "make", 4) == 1)
    make_param(str, p);
  else
    {
      str = remove_space(str);
      auto_dir(str, ".", p);
    }
  if (p->nothing == 0)
      if (my_free_struct_2(p) == 0)
        return ;
  aff_auto_list(p);
  my_fput("\n", 1);
  my_free_struct(p);
}
