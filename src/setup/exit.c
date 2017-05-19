/*
** exit.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 19:47:06 2017 Hugo MARTIN
** Last update	Fri May 19 17:37:18 2017 Hugo MARTIN
*/

#include "my.h"

void	my_exit(t_my_var *data)
{
  int	tmp;

  tmp = data->return_value;
  free_list(data->separator);
  free_list(data->list_command);
  free_double_tab(data->env);
  free_double_tab(data->var);
  free_double_tab(data->alias);
  free(data);
  exit (tmp);
}
