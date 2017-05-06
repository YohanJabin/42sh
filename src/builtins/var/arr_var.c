/*
** arr_var.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 11:39:31 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:27:29 2017 Adrien ZEMMA
*/

#include "my.h"

int	get_index_var(char **var, char *to_search)
{
  int	i;

  i = -1;
  while (var[++i] != NULL)
    {
      if (my_strncmp(var[i], to_search, my_strlen(to_search)) == 1)
	return (i);
    }
  return (-1);
}

int	hm_many_var(char **var)
{
  int	i;
  int	hm;

  hm = 0;
  i = -1;
  while (var[++i] != NULL)
    hm++;
  return (hm);
}

void	parse_var(char **arr_var, char **var)
{
  int	i;
  int	len;

  i = -1;
  while (var[++i] != NULL)
    {
      len = my_strlen(var[i]);
      arr_var[i] = malloc(sizeof(char) * (len + 1));
      my_memset(arr_var[i], 0, len + 1);
      my_strncpy(arr_var[i], var[i], len);
    }
}

char	**cpy_arr_var(char **var)
{
  char	**arr_var;
  int	len;

  len = hm_many_var(var);
  arr_var = malloc(sizeof(char*) * (len + 1));
  arr_var[len] = NULL;
  parse_var(arr_var, var);
  return (arr_var);
}
