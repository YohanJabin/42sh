/*
** my_unsetalias.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Sun Mar 26 11:23:31 2017 Yohan.Jabin
** Last update Sat May  6 19:55:07 2017 Yohan.Jabin
*/

#include "my.h"

void	parse_delete_alias(t_my_var *data, char **cpy_alias, int index)
{
  int	i;
  int	j;
  int	len;

  j = -1;
  i = 0;
  while (cpy_alias[++j] != NULL)
    {
      if (j == index)
	j++;
      if (cpy_alias[j] == NULL)
	return;
      len = my_strlen(cpy_alias[j]);
      data->alias[i] = malloc(sizeof(char) * (len + 1));
      my_memset(data->alias[i], 0, len + 1);
      my_strncpy(data->alias[i], cpy_alias[j], len);
      i++;
    }
}

void	delete_alias(t_my_var *data, char *to_delete)
{
  int	index;
  char	**cpy_alias;
  int	len;

  if ((index = get_index_alias(data->alias, to_delete)) == -1)
    return;
  cpy_alias = cpy_arr_alias(data->alias);
  free_double_tab(data->alias);
  len = hm_many_alias(cpy_alias);
  data->alias = malloc(sizeof(char*) * (len));
  data->alias[len - 1] = NULL;
  parse_delete_alias(data, cpy_alias, index);
}

void	my_unsetalias(t_my_var *data, char **imp)
{
  int	i;

  i = 0;
  while (imp[++i] != NULL)
    delete_alias(data, imp[i]);
}
