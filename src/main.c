/*
** main.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:54:03 2017 Adrien ZEMMA
** Last update	Fri Apr 28 15:27:47 2017 Adrien ZEMMA
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
  t_my_var	*p;
  t_my_prompt	*promt;

  p = malloc(sizeof(*p));
  data = malloc(sizeof(t_my_data));
  ac = ac;
  av = av;
  p->return_value = 0;
  p->env = env;
  data->env = cpy_arr_env(env);
  change_pwd(prompt);
  my_start(p, prompt);
  //my_echo("echo $PATH", env);
  return (0);
}
