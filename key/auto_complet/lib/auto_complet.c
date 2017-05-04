/*
** auto_complet.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Tue May  2 13:39:23 2017 Camille Gouneau
** Last update Wed May  3 18:04:59 2017 Camille Gouneau
*/

#include  <dirent.h>
#include  <sys/types.h>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  "auto_complet.h"

void  auto_dir(char *str, char *dir, t_my_auto  *p)
{
  DIR* rep;
  struct dirent *t_dirent;

  rep = opendir(dir);
  while ((t_dirent = readdir(rep)) != 0)
  {
    if (my_strncmp(str, t_dirent->d_name, my_strlen(str)) == 1)
    {
      p->auto_list[p->i] = my_malloc(sizeof(char) *
        (my_strlen(t_dirent->d_name) + 1));
      p->auto_list[p->i][my_strlen(t_dirent->d_name)] = '\0';
      p->auto_list[p->i] = t_dirent->d_name;
      p->i++;
      my_realloc_star(p->auto_list);
    }
  }
  closedir(rep);
}

void  layout(char *str)
{
  int i;
  int j;

  i = 18 - my_strlen(str);
  j = 0;
  while (i > j)
    {
      my_fput(" ", 1);
      i--;
    }
}

int   count_size(char **tab)
{
  int i;
  int j;
  int max;
  int actual;

  i = 0;
  j = 0;
  max = 0;
  actual = 0;
  while (tab[i])
    {
      while (tab[i][j])
        {
          j++;
          actual++;
        }
      if (actual > max)
        max = actual;
      actual = 0;
      j = 0;
      i++;
    }
  return (max);
}

void  aff_auto_list(t_my_auto *p)
{
  int total_space;
  int j;
  int count;

  p->i = 0;
  count = 0;
  j = my_strlen(p->auto_list[p->i]);
  total_space = count_size(p->auto_list);
  while (p->auto_list[p->i])
    {
      my_fput(p->auto_list[p->i], 1);
      while (j < total_space)
        {
          my_fput(" ", 1);
          j++;
        }
      count++;
      if (count == 10)
        {
          my_fput("\n", 1);
          count = 0;
        }
      p->i++;
      j = my_strlen(p->auto_list[p->i]);
    }
}

void  auto_complet(char *str)
{
  t_my_auto *p;
  char  **path;
  int   i;

  i = 0;
  p = my_malloc(sizeof(t_my_auto));
  p->i = 0;
  p->auto_list = my_malloc(sizeof(char * ) * 2);
  p->auto_list[1] = NULL;
  auto_dir(str, ".", p);
  path = create_path();
  while (path[i])
    {
      auto_dir(str, path[i], p);
      i++;
    }
  free (path);
  aff_auto_list(p);
  my_fput("\n", 1);
  free (p);
}
