/*
** var.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 17:49:13 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:23 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_error_unsetvar(t_my_var *data, char **imp)
{
  if (imp[1] == NULL)
    {
      my_fprintf(2, "unset: Too few arguments.\n");
      data->return_value = 1;
    }
  else
    my_unsetvar(data, imp);
}

int	is_it_valid_var(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    {
      if ((str[i] < '0'
	   || (str[i] > '9' && str[i] < 'A')
	   || (str[i] > 'Z' && str[i] < 'a')
	   || str[i] > 'z') && str[i] != '=')
	return (0);
    }
  return (1);
}

int	my_error_setvar2(t_my_var *data, char **imp)
{
  if (imp[1][0] < 'A'
      || (imp[1][0] > 'Z' && imp[1][0] < 'a')
      || imp[1][0] > 'z')
    {
      my_fprintf(2, "set: Variable name must ");
      my_fprintf(2, "begin with a letter.\n");
      data->return_value = 1;
      return (84);
    }
  if (is_it_valid_var(imp[1]) == 0)
    {
      my_fprintf(2, "set: Variable name must ");
      my_fprintf(2, "contain alphanumeric characters.\n");
      data->return_value = 1;
      return (84);
    }
  return (0);
}

void	my_error_setvar(t_my_var *data, char **imp)
{
  if (imp[1] == NULL)
    aff_var_alias(data->var);
  else if (my_error_setvar2(data, imp) == 0)
    my_setvar(data, imp);
}

int	test_cmd_var(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "set", 4) == 1)
    {
      my_error_setvar(data, imp);
      return (0);
    }
  else if (my_strncmp(imp[0], "unset", 6) == 1)
    {
      my_error_unsetvar(data, imp);
      return (0);
    }
  return (1);
}
