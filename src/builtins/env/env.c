/*
** env.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 17:49:13 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:23 2017 Adrien ZEMMA
*/

#include "my.h"

void	update_env(t_my_var *data)
{
  char	pwd[100];
  int	index;

  my_memset(pwd, 0, 100);
  getcwd(pwd, 99);
  if ((index = get_index_env(data->env, "PWD")) == -1)
    add_env(data, "PWD", pwd);
  else
    change_env(data, "PWD", pwd, index);
}

void	my_error_unsetenv(t_my_var *data, char **imp)
{
  if (imp[1] == NULL)
    {
      my_fprintf(2, "unsetenv: Too few arguments.\n");
      data->return_value = 1;
    }
  else
    my_unsetenv(data, imp);
}

int	my_error_setenv2(t_my_var *data, char **imp)
{
  if (imp[1][0] < 'A'
      || (imp[1][0] > 'Z' && imp[1][0] < 'a')
      || imp[1][0] > 'z')
    {
      my_fprintf(2, "setenv: Variable name must ");
      my_fprintf(2, "begin with a letter.\n");
      data->return_value = 1;
      return (84);
    }
  if (is_it_num_alpha(imp[1]) == 0)
    {
      my_fprintf(2, "setenv: Variable name must ");
      my_fprintf(2, "contain alphanumeric characters.\n");
      data->return_value = 1;
      return (84);
    }
  return (0);
}

void	my_error_setenv(t_my_var *data, char **imp)
{
  if (imp[1] == NULL)
    aff_double_tab(data->env);
  else if (imp[1] != NULL && imp[2] != NULL && imp[3] != NULL)
    {
      my_fprintf(2, "setenv: Too many arguments.\n");
      data->return_value = 1;
    }
  else if (my_error_setenv2(data, imp) == 0)
    my_setenv(data, imp);
}

int	test_cmd_env(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "env", 4) == 1)
    {
      aff_double_tab(data->env);
      return (0);
    }
  else if (my_strncmp(imp[0], "setenv", 7) == 1)
    {
      my_error_setenv(data, imp);
      return (0);
    }
  else if (my_strncmp(imp[0], "unsetenv", 9) == 1)
    {
      my_error_unsetenv(data, imp);
      return (0);
    }
  return (1);
}
