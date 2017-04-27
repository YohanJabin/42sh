/*
** arr_env.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 11:39:31 2017 Yohan.Jabin
** Last update Thu Apr 27 23:57:22 2017 Yohan.Jabin
*/

#include "my.h"

int	get_index_env(char **env, char *to_search)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    {
      if (my_strncmp(env[i], to_search, my_strlen(to_search)) == 1)
	return (i);
    }
  return (-1);
}

int	hm_many_env(char **env)
{
  int	i;
  int	hm;

  hm = 0;
  i = -1;
  while (env[++i] != NULL)
    hm++;
  return (hm);
}

void	parse_env(char **arr_env, char **env)
{
  int	i;
  int	len;

  i = -1;
  while (env[++i] != NULL)
    {
      len = my_strlen(env[i]);
      arr_env[i] = malloc(sizeof(char) * (len + 1));
      my_memset(arr_env[i], 0, len + 1);
      my_strncpy(arr_env[i], env[i], len);
    }
}

char	**cpy_arr_env(char **env)
{
  char	**arr_env;
  int	len;

  len = hm_many_env(env);
  arr_env = malloc(sizeof(char*) * (len + 1));
  arr_env[len] = NULL;
  parse_env(arr_env, env);
  return (arr_env);
}
