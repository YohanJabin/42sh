/*
** my_setvar.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 18:24:53 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:34 2017 Adrien ZEMMA
*/

#include "my.h"

void	add_var(t_my_var *data, char *var)
{
  char	**cpy_var;
  int	len;
  int	len2;

  cpy_var = cpy_arr_var(data->var);
  free_double_tab(data->var);
  len = hm_many_var(cpy_var);
  data->var = malloc(sizeof(char*) * (len + 2));
  data->var[len + 1] = NULL;
  parse_var(data->var, cpy_var);
  len2 = my_strlen(var);
  data->var[len] = malloc(sizeof(char) * (len2 + 1));
  my_memset(data->var[len], 0, len2 + 1);
  my_strncpy(data->var[len], var, len2);
  free_double_tab(cpy_var);
}

void	change_var(t_my_var *data, char *var, int index)
{
  int	len;

  free(data->var[index]);
  len = my_strlen(var);
  data->var[index] = malloc(sizeof(char) * (len + 1));
  my_memset(data->var[index], 0, len + 1);
  my_strncpy(data->var[index], var, len);
}

int	get_first_equal(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    {
      if (str[i] == '=')
	return (i);
    }
  return (-1);
}

void	my_setvar(t_my_var *data, char **imp)
{
  int	i;
  int	index;
  int	first_equal;
  char	*tmp;

  i = 0;
  while (imp[++i] != NULL)
    {
      if ((first_equal = get_first_equal(imp[i])) == -1)
	first_equal = my_strlen(imp[i]);
      tmp = malloc(sizeof(char) * (first_equal + 1));
      my_memset(tmp, 0, first_equal + 1);
      my_strncpy(tmp, imp[i], first_equal);
      if ((index = get_index_var(data->var, tmp)) == -1)
	add_var(data, imp[i]);
      else
	change_var(data, imp[i], index);
      free(tmp);
    }
}
