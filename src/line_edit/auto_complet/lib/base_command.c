/*
** base_command.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/lib/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Fri May  5 13:39:00 2017 Camille Gouneau
** Last update Sun May 14 16:30:54 2017 Camille Gouneau
*/

#include  <dirent.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "auto_complet.h"

int   check_make_param(char *make_line, char *str)
{
  int i;
  char  *new_make_line;

  i = 0;
  new_make_line = get_space(make_line);
  if (make_line[0] == '#' && make_line[1] == '#')
    return (0);
  while (make_line[i])
    {
      if (make_line[i] == ' ')
        return (0);
      if (make_line[i] == ':' && my_strncmp(str, make_line, i) == 1)
        return (1);
      i++;
    }
  return (0);
}

char  *get_make_param(char *str)
{
  int i;
  char  *to_return;

  i = 0;
  while (str[i] != ':')
    i++;
  to_return = my_malloc(sizeof(char) * (i + 1));
  to_return[i] = '\0';
  i = 0;
  while (str[i] != ':')
    {
      to_return[i] = str[i];
      i++;
    }
  return (to_return);
}

void  my_parse_makefile(char **tab, t_my_auto *p, char *str)
{
  int i;
  char *make_param;

  i = 0;
  while (tab[i])
    {
      if (check_make_param(tab[i], str) == 1)
        {
          make_param = get_make_param(tab[i]);
          p->auto_list[p->i] = my_malloc(sizeof(char) *
            (my_strlen(make_param) + 1));
          p->auto_list[p->i][my_strlen(make_param)] = '\0';
          my_put_in_char(p->auto_list[p->i], make_param);
          p->i++;
          p->auto_list = my_realloc_star(p->auto_list);
          free (make_param);
        }
      i++;
    }
}

void  make_param(char *str, t_my_auto *p)
{
  int dir;
  char  *parsing;
  char  **makefile_tab;

  dir = open("Makefile", O_RDONLY);
  parsing = get_next_line_2(dir);
  makefile_tab = str_to_word_tab(parsing, '\n');
  free (parsing);
  my_parse_makefile(makefile_tab, p, str);
  p->nothing++;
}

void  cd_param(char *str, char *dir, t_my_auto  *p)
{
  DIR* rep;
  struct dirent *t_dirent;

  rep = opendir(dir);
  str = remove_space(str);
  while ((t_dirent = readdir(rep)) != 0)
  {
    if (t_dirent->d_type == DT_DIR &&
    my_strncmp(str, t_dirent->d_name, my_strlen(str)) == 1)
    {
      p->nothing++;
      p->auto_list[p->i] = my_malloc(sizeof(char) *
        (my_strlen(t_dirent->d_name) + 1));
      p->auto_list[p->i][my_strlen(t_dirent->d_name)] = '\0';
      my_put_in_char(p->auto_list[p->i], t_dirent->d_name);
      p->i++;
      p->auto_list = my_realloc_star(p->auto_list);
    }
  }
  closedir(rep);
}
