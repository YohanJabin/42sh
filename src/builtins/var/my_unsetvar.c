/*
** my_unsetvar.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Sun Mar 26 11:23:31 2017 Yohan.Jabin
** Last update Thu May  4 11:34:57 2017 Yohan.Jabin
*/

#include "my.h"

void	parse_delete_var(t_my_var *data, char **cpy_var, int index)
{
  int	i;
  int	j;
  int	len;

  j = -1;
  i = 0;
  while (cpy_var[++j] != NULL)
    {
      if (j == index)
	j++;
      if (cpy_var[j] == NULL)
	return;
      len = my_strlen(cpy_var[j]);
      data->var[i] = malloc(sizeof(char) * (len + 1));
      my_memset(data->var[i], 0, len + 1);
      my_strncpy(data->var[i], cpy_var[j], len);
      i++;
    }
}

void	delete_var(t_my_var *data, char *to_delete)
{
  int	index;
  char	**cpy_var;
  int	len;

  if ((index = get_index_var(data->var, to_delete)) == -1)
    return;
  cpy_var = cpy_arr_var(data->var);
  free_double_tab(data->var);
  len = hm_many_var(cpy_var);
  data->var = malloc(sizeof(char *) * (len));
  data->var[len - 1] = NULL;
  parse_delete_var(data, cpy_var, index);
}

void	my_unsetvar(t_my_var *data, char **imp)
{
  int	i;

  i = 0;
  while (imp[++i] != NULL)
    delete_var(data, imp[i]);
}
