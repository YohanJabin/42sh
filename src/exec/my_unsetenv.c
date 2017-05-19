/*
** my_unsetenv.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Sun Mar 26 11:23:31 2017 Yohan.Jabin
** Last update Thu Apr 27 23:39:37 2017 Yohan.Jabin
*/

#include "my.h"

void	parse_delete_env(t_my_data *data, char **cpy_env, int index)
{
  int	i;
  int	j;
  int	len;

  j = -1;
  i = 0;
  while (cpy_env[++j] != NULL)
    {
      if (j == index)
	j++;
      if (cpy_env[j] == NULL)
	return;
      len = my_strlen(cpy_env[j]);
      data->env[i] = malloc(sizeof(char) * (len + 1));
      my_memset(data->env[i], 0, len + 1);
      my_strncpy(data->env[i], cpy_env[j], len);
      i++;
    }
}

void	delete_env(t_my_data *data, char *to_delete)
{
  int	index;
  char	**cpy_env;
  int	len;

  if ((index = get_index_env(data->env, to_delete)) == -1)
    return;
  cpy_env = cpy_arr_env(data->env);
  free_double_tab(data->env);
  len = hm_many_env(cpy_env);
  data->env = malloc(sizeof(char*) * (len));
  data->env[len - 1] = NULL;
  parse_delete_env(data, cpy_env, index);
}

void	my_unsetenv(t_my_data *data, char **imp)
{
  int	i;

  i = -1;
  while (imp[++i] != NULL)
    delete_env(data, imp[i]);
}
