/*
** main.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:54:03 2017 Adrien ZEMMA
** Last update	Wed Apr 12 20:05:19 2017 Hugo MARTIN
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
  int nb;
  char buff[8046];
  t_my_var	*p;

  nb = read(0, buff, 8046);
  buff[nb] = '\0';
  my_printf("%s\n", buff);
  p = malloc(sizeof(*p));
  ac = ac;
  av = av;
  p->return_value = 0;
  p->env = env;
  my_start(p);
  //my_echo("echo $PATH", env);
  return (0);
}
