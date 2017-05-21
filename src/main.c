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

char	**init_var()
{
  char  **var;

  if ((var = malloc(sizeof(char *))) == NULL)
    return (NULL);
  var[0] = NULL;
  return (var);
}

void	init_builtins(t_my_var *data)
{
  data->hm_builtins = 9;
  data->f_builtins[0] = &test_cmd_scripting;
  data->f_builtins[1] = &test_cmd_echo;
  data->f_builtins[2] = &test_cmd_cd;
  data->f_builtins[3] = &test_cmd_exit;
  data->f_builtins[4] = &test_cmd_env;
  data->f_builtins[5] = &test_cmd_var;
  data->f_builtins[6] = &test_cmd_alias;
  data->f_builtins[7] = &test_cmd_which;
  data->f_builtins[8] = &test_cmd_path;
}

int	init_shell(t_my_var *data, t_my_prompt *prompt, char **env)
{
  prompt->prompt_compteur = -1;
  prompt->prompt_prompt = malloc(sizeof(char *) * 1);
  prompt->histori_tab = malloc(sizeof(char *) * 1);
  prompt->prompt_prompt[0] = NULL;
  prompt->histori_nb = 2;
  data->separator = NULL;
  data->list_command = NULL;
  data->return_value = 0;
  data->var = init_var();
  data->alias = init_var();
  data->env = cpy_arr_env(env);
  data->return_value = 0;
  change_pwd(data);
  init_builtins(data);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_my_var	*data;
  t_my_prompt	*prompt;

  if ((data = malloc(sizeof(t_my_var))) == NULL)
    return (84);
  if ((prompt = malloc(sizeof(t_my_prompt))) == NULL)
    return (84);
  init_shell(data, prompt, env);
  init_scripting(data, ac, av);
  my_start(data, prompt);
  return (data->return_value);
}
