/*
** auto_complet_command.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Fri May  5 11:38:42 2017 Camille Gouneau
** Last update Fri May  5 14:18:44 2017 Camille Gouneau
*/

#include  <dirent.h>
#include  <sys/types.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "auto_complet.h"

void  auto_complet_command(char *str, t_my_auto *p, char **path)
{
  int i;

  i = 0;
  auto_dir(str, ".", p);
  while (path[i])
    {
      auto_dir(str, path[i], p);
      i++;
    }
  if (p->nothing == 0)
      if (my_free_struct_2(p) == 0)
        return ;
  aff_auto_list(p);
  my_fput("\n", 1);
  my_free_struct(p);
}
