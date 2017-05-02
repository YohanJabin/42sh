/*
** my_setenv.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 18:24:53 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:34 2017 Adrien ZEMMA
*/

#include "my.h"

char	*get_string_to_add(char *name, char *var)
{
  char	*return_value;
  int	len;

  if (var != NULL)
    {
      len = my_strlen(name) + my_strlen(var) + 1;
      return_value = malloc(sizeof(char) * (len + 1));
      my_memset(return_value, 0, len + 1);
      len = my_strlen(name);
      my_strncpy(return_value, name, len);
      return_value[len] = '=';
      my_strncpy(&return_value[len + 1], var, my_strlen(var));
    }
  else
    {
      len = my_strlen(name) + 1;
      return_value = malloc(sizeof(char) * (len + 1));
      my_memset(return_value, 0, len + 1);
      my_strncpy(return_value, name, len - 1);
      return_value[len - 1] = '=';
    }
  return (return_value);
}

void	add_env(t_my_var *data, char *name, char *var)
{
  char	**cpy_env;
  char	*tmp;
  int	len;
  int	len2;

  cpy_env = cpy_arr_env(data->env);
  free_double_tab(data->env);
  len = hm_many_env(cpy_env);
  data->env = malloc(sizeof(char*) * (len + 2));
  data->env[len + 1] = NULL;
  parse_env(data->env, cpy_env);
  tmp = get_string_to_add(name, var);
  len2 = my_strlen(tmp);
  data->env[len] = malloc(sizeof(char) * (len2 + 1));
  my_memset(data->env[len], 0, len2 + 1);
  my_strncpy(data->env[len], tmp, len2);
  free(tmp);
  free_double_tab(cpy_env);
}

void	change_env(t_my_var *data, char *name,
		   char *var, int index)
{
  char	*tmp;
  int	len;

  free(data->env[index]);
  tmp = get_string_to_add(name, var);
  len = my_strlen(tmp);
  data->env[index] = malloc(sizeof(char) * (len + 1));
  my_memset(data->env[index], 0, len + 1);
  my_strncpy(data->env[index], tmp, len);
  free(tmp);
}

void	my_setenv(t_my_var *data, char **imp)
{
  int	index;

  if ((index = get_index_env(data->env, imp[1])) == -1)
    add_env(data, imp[1], imp[2]);
  else
    change_env(data, imp[1], imp[2], index);
}
