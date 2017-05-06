/*
** arr_alias.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 11:39:31 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:27:29 2017 Adrien ZEMMA
*/

#include "my.h"

int	get_index_alias(char **alias, char *to_search)
{
  int	i;

  i = -1;
  while (alias[++i] != NULL)
    {
      if (my_strncmp(alias[i], to_search, my_strlen(to_search)) == 1)
	return (i);
    }
  return (-1);
}

int	hm_many_alias(char **alias)
{
  int	i;
  int	hm;

  hm = 0;
  i = -1;
  while (alias[++i] != NULL)
    hm++;
  return (hm);
}

void	parse_alias(char **arr_alias, char **alias)
{
  int	i;
  int	len;

  i = -1;
  while (alias[++i] != NULL)
    {
      len = my_strlen(alias[i]);
      arr_alias[i] = malloc(sizeof(char) * (len + 1));
      my_memset(arr_alias[i], 0, len + 1);
      my_strncpy(arr_alias[i], alias[i], len);
    }
}

char	**cpy_arr_alias(char **alias)
{
  char	**arr_alias;
  int	len;

  len = hm_many_alias(alias);
  arr_alias = malloc(sizeof(char*) * (len + 1));
  arr_alias[len] = NULL;
  parse_alias(arr_alias, alias);
  return (arr_alias);
}
