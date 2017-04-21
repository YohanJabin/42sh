/*
** main.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:54:03 2017 Adrien ZEMMA
** Last update	Fri Apr 21 14:25:56 2017 Adrien ZEMMA
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
  t_my_var	*p;
  t_my_data	*data;

  p = malloc(sizeof(*p));
  data = malloc(sizeof(t_my_data));
  ac = ac;
  av = av;
  p->return_value = 0;
  p->env = env;
  my_start(p, data);
  //my_echo("echo $PATH", env);
  return (0);
}
