/*
** exit.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 19:47:06 2017 Hugo MARTIN
** Last update	Tue Apr 25 15:24:09 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_exit(t_my_var *v)
{
  int	i;

  i = v->return_value;
  free (v);
  exit (i);
}
