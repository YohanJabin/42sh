/*
** repeat.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed May 10 15:35:26 2017 Hugo MARTIN
** Last update	Wed May 10 15:41:05 2017 Hugo MARTIN
*/

#include "my.h"

int	my_full_repeat(t_my_var *data, char *c)
{
  if (my_strcmp(c, "repeat") == 1)
  {
    if (my_check_char(c, ' ') == 2)
      {
	data->script.repeat_f = 1;
	data->script.repeat_n = my_getnbr(get_arg(c, 1, " "));
	data->script.repeat_n = get_arg(c, 2, " ");
      }
    else
      {
	my_fprintf(2, "repeat: Too few arguments.\n");
	data->return_value = 1;
	return (-1);
      }
  }
  return (0);
}
