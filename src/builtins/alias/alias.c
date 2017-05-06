/*
** alias.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 17:49:13 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:23 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_error_unsetalias(t_my_var *data, char **imp)
{
  if (imp[1] == NULL)
    {
      my_fprintf(2, "unalias: Too few arguments.\n");
      data->return_value = 1;
    }
  else
    my_unsetalias(data, imp);
}

void	my_error_setalias(t_my_var *data, char **imp)
{
  if (imp[1] == NULL)
    aff_double_tab(data->alias);
  else if (imp[2] != NULL)
    my_setalias(data, imp);
}

int	test_cmd_alias(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "alias", 6) == 1)
    {
      my_error_setalias(data, imp);
      return (0);
    }
  else if (my_strncmp(imp[0], "unalias", 8) == 1)
    {
      my_error_unsetalias(data, imp);
      return (0);
    }
  return (1);
}
