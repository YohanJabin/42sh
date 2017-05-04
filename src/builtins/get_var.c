/*
** get_var.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 13:38:45 2017 Yohan.Jabin
** Last update Thu May  4 21:06:16 2017 Yohan.Jabin
*/

#include "my.h"

char	*get_var_str(char **arr, int index)
{
  char	*ret;
  int	first_equal;
  int	len;

  if ((first_equal = get_first_equal(arr[index]) + 1) == 0
      || arr[index][first_equal] == 0)
    {
      if ((ret = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      my_memset(ret, 0, 1);
    }
  else
    {
      len = my_strlen(arr[index]) - first_equal;
      if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      my_memset(ret, 0, len + 1);
      my_strncpy(ret, &arr[index][first_equal], len);
    }
  return (ret);
}

char	*get_var(t_my_var *data, char *to_search)
{
  char	*ret;
  int	index;

  if ((index = get_index_var(data->var, to_search)) != -1)
    {
      ret = get_var_str(data->var, index);
      return (ret);
    }
  if ((index = get_index_env(data->env, to_search)) != -1)
    {
      ret = get_var_str(data->env, index);
      return (ret);
    }
  my_fprintf(2, "%s: Undefined variable.\n", to_search);
  data->return_value = 1;
  return (NULL);
}

int	check_var(t_my_var *data, char **imp)
{
  int	i;
  int	j;

  i = -1;
  while (imp[++i] != NULL)
    {
      j = -1;
      while (imp[i][++j] != 0)
	{
	  if (imp[i][j] == '$')
	    {
	      if ((imp[i] = get_var(data, &imp[i][j + 1])) == NULL)
		return (0);
	      if (check_var(data, imp) == 0)
		return (0);
	      return (1);
	    }
	}
    }
  return (1);
}
