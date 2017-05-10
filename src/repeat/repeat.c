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

void	my_full_repeat(t_script *s, char *c)
{
  if (my_strcmp(c, "repeat") == 1)
  {
    if (my_check_char(c, ' ') == 2)
    {
      s->repeat_f = 1;
      s->repeat_n = my_getnbr(get_arg(c, 1, " "));
      s->repeat_n = get_arg(c, 2, " ");
    }
    else
      my_fprintf(2, "repeat: Too few arguments.\n");
  }
}
