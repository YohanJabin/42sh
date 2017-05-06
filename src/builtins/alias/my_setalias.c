/*
** my_setalias.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 18:24:53 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:34 2017 Adrien ZEMMA
*/

#include "my.h"

void	add_alias(t_my_var *data, char *alias, char *var)
{
  char	**cpy_alias;
  int	len;
  int	len2;
  char	*tmp;

  cpy_alias = cpy_arr_alias(data->alias);
  free_double_tab(data->alias);
  len = hm_many_alias(cpy_alias);
  data->alias = malloc(sizeof(char*) * (len + 2));
  data->alias[len + 1] = NULL;
  parse_alias(data->alias, cpy_alias);
  tmp = my_strcat(my_strcat(alias, "="), var);
  len2 = my_strlen(tmp);
  data->alias[len] = malloc(sizeof(char) * (len2 + 1));
  my_memset(data->alias[len], 0, len2 + 1);
  my_strncpy(data->alias[len], tmp, len2);
  free_double_tab(cpy_alias);
}

void	change_alias(t_my_var *data,
		     char *alias,
		     char *var,
		     int index)
{
  int	len;
  char	*tmp;

  free(data->alias[index]);
  tmp = my_strcat(my_strcat(alias, "="), var);
  len = my_strlen(tmp);
  data->alias[index] = malloc(sizeof(char) * (len + 1));
  my_memset(data->alias[index], 0, len + 1);
  my_strncpy(data->alias[index], tmp, len);
}

char	*get_string_to_add_alias(char **imp)
{
  char	*ret;
  int	len;
  int	len2;
  int	i;
  int	j;

  i = 1;
  len = my_strlen(imp[2]);
  while (imp[++i] != NULL)
    len += my_strlen(imp[i]);
  ret = malloc(sizeof(char) * (len + 1));
  my_memset(ret, 0, len + 1);
  my_memset(ret, ' ', len);
  i = 1;
  j = -1;
  while (++j < len && imp[++i] != NULL)
    {
      len2 = my_strlen(imp[i]);
      my_strncpy(&ret[j], imp[i], len2);
      j += len2;
    }
  ret[j - 1] = 0;
  return (ret);
}

void	my_setalias(t_my_var *data, char **imp)
{
  int	index;
  char	*to_add;

  to_add = get_string_to_add_alias(imp);
  if ((index = get_index_alias(data->alias, imp[1])) == -1)
    add_alias(data, imp[1], to_add);
  else
    change_alias(data, imp[1], to_add, index);
}
