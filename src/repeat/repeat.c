/*
** repeat.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed May 10 15:35:26 2017 Hugo MARTIN
** Last update	Fri May 19 15:15:29 2017 Hugo MARTIN
*/

#include "my.h"

void	my_full_repeat(t_my_var *v, t_my_separator	*s, t_my_repeat d)
{
  int	i;

  i = -1;
  while (++i < d.hm)
  {
    s->command = d.command;
    add_end_list(&v->separator, s);
  }
}

int	my_repeat(t_my_var *v, t_my_separator	*s, char *c)
{
  t_my_repeat	data;

  if (my_check_char(c, ' ') >= 2 &&
      my_strncmp(my_pure(s->command), "repeat", 6) == 1)
    {
	    data.hm = my_getnbr(get_arg(c, 1, " "));
	    data.command = get_full(c, 2, " ");
      my_full_repeat(v, s, data);
    }
  else
    {
	    my_fprintf(2, "repeat: Too few arguments.\n");
	    v->return_value = 1;
	    return (-1);
    }
  return (0);
}
