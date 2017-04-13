/*
** main.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:54:03 2017 Adrien ZEMMA
** Last update	Thu Apr 13 20:46:52 2017 Adrien ZEMMA
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
  int nb;
  char buff[4096];
  t_my_var	*p;

  p = malloc(sizeof(*p));
  nb = read(0, buff, 4095);
  buff[nb] = '\0';
  my_printf("%s", buff);
  ac = ac;
  av = av;
  p->return_value = 0;
  p->env = env;
  my_start(p);
  //my_echo("echo $PATH", env);
  return (0);
}
