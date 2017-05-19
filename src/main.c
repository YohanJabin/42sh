/*
** main.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:54:03 2017 Adrien ZEMMA
** Last update	Fri May 19 17:33:13 2017 Hugo MARTIN
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
  t_my_var	*p;
  t_my_prompt	*prompt;

  p = malloc(sizeof(*p));
  prompt = malloc(sizeof(t_my_prompt));
  prompt->prompt_compteur = -1;
  prompt->prompt_prompt = malloc(sizeof(char *) * 1);
  prompt->histori_tab = malloc(sizeof(char *) * 1);
  prompt->prompt_prompt[0] = NULL;
  prompt->histori_nb = 2;
  p->separator = NULL;
  p->list_command = NULL;
  p->return_value = 0;
  p->var = init_var();
  if (env[0] == NULL)
    setvar(p, "path=/usr/bin /bin");
  p->alias = init_alias();
  p->env = cpy_arr_env(env);
  change_pwd(p);
  init_scripting(p, ac, av);
  my_start(p, prompt);
  //my_echo("echo $PATH", env);
  return (p->return_value);
}
