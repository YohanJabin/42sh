/*
** path_handle.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B1/PSU/PSU_2016_minishell1/lib/my/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Mon Mar 20 19:52:26 2017 Camille Gouneau
** Last update Thu May  4 12:02:00 2017 Camille Gouneau
*/

#include  <stdlib.h>
#include  <unistd.h>
#include  <stdio.h>
#include  <auto_complet.h>

char    *remove_path(char *str, char *to_remove)
{
  char  *str2;
  int   len;
  int   i;
  int   j;

  i = my_strlen(to_remove);
  j = 0;
  len = my_strlen(str) - i;
  str2 = my_malloc((sizeof(char) * len) + 1);
  str2[len] = '\0';
  while (str[i])
    {
      str2[j] = str[i];
      i++;
      j++;
    }
  return (str2);
}

char    **create_path()
{
  int   i;
  char  **path_list;
  char  *path_str;

  i = 0;
  while (environ[i] && my_strncmp(environ[i], "PATH", 4) != 1)
    i++;
  if (!environ[i])
      return (NULL);
  path_str = remove_path(environ[i], "PATH=");
  path_list = str_to_word_tab(path_str, ':');
  free (path_str);
  return (path_list);
}
