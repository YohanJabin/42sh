/*
** globbing_manip.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/formatting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Mon May 15 11:44:52 2017 Yohan.Jabin
** Last update Sat May 20 13:38:18 2017 Yohan.Jabin
*/

#include "my.h"

int		hm_many_files(char *filename)
{
  DIR		*dir;
  struct dirent	*s;
  int		len;

  if ((dir = opendir(filename)) == NULL)
    return (-1);
  len = 0;
  while ((s = readdir(dir)) != NULL)
    len++;
  closedir(dir);
  return (len);
}

int		parse_file_to_arr(char **arr, char *filename)
{
  DIR           *dir;
  struct dirent *s;
  int		i;

  if ((dir = opendir(filename)) == NULL)
    return (84);
  i = 0;
  while ((s = readdir(dir)) != NULL)
    {
      if ((arr[i] = my_strdup(s->d_name)) == NULL)
	return (84);
      i++;
    }
  closedir(dir);
  return (0);
}

char	**get_file_arr(char *filename)
{
  char	**arr;
  int	len;

  if ((len = hm_many_files(filename)) == -1)
    return (NULL);
  if ((arr = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  arr[len] = NULL;
  if (parse_file_to_arr(arr, filename) == 84)
    return (NULL);
  return (arr);
}

int     get_last_slash(char *imp)
{
  int   i;

  i = my_strlen(imp);
  while (--i >= 0 && imp[i] != '/');
  return (i);
}

char    *get_globbing_filename(char *to_process)
{
  char  *filename;
  int   j;

  j = get_last_slash(to_process);
  j++;
  if (j <= 0)
    {
      if ((filename = malloc(sizeof(char) * (2))) == NULL)
	return (NULL);
      my_memset(filename, 0, 2);
      filename[0] = '.';
    }
  else
    {
      if ((filename = malloc(sizeof(char) * (j + 1))) == NULL)
	return (NULL);
      my_memset(filename, 0, j + 1);
      my_strncpy(filename, to_process, j);
    }
  return (filename);
}
