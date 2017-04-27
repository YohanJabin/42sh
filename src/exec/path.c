/*
** env.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 20 15:07:28 2017 Yohan.Jabin
** Last update Fri Apr 28 00:03:05 2017 Yohan.Jabin
*/

#include "my.h"

int	get_path_index(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH=", 5) == 1)
	return (i);
      i++;
    }
  return (-1);
}

int	hm_path(char *path)
{
  int	i;
  int	hm;

  hm = 1;
  i = -1;
  while (path[++i] != 0)
    if (path[i] == ':')
      hm++;
  return (hm);
}

int	my_strlen_path(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0 && str[i] != ':');
  return (i);
}

void	parse_path(char **arr, char *path)
{
  int	i;
  int	j;
  int	len;

  j = 0;
  i = 4;
  while (++i < my_strlen(path))
    {
      len = my_strlen_path(&path[i]);
      arr[j] = malloc(sizeof(char) * (len + 1));
      my_memset(arr[j], 0, len + 1);
      my_strncpy(arr[j], &path[i], len);
      i = i + len;
      j++;
    }
}

char	**get_arr_path(char **env)
{
  char	**arr_path;
  int	path_index;
  int	len;

  if ((path_index = get_path_index(env)) == -1)
    return (NULL);
  len = hm_path(env[path_index]);
  arr_path = malloc(sizeof(char*) * (len + 1));
  arr_path[len] = NULL;
  parse_path(arr_path, env[path_index]);
  len = -1;
  return (arr_path);
}
