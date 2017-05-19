/*
** exit.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 19:47:06 2017 Hugo MARTIN
** Last update	Wed Apr 12 19:47:10 2017 Hugo MARTIN
*/

#include "my.h"

void	my_exit(t_my_var *v)
{
  int	i;

  i = v->return_value;
  free (v);
  exit (i);
}
