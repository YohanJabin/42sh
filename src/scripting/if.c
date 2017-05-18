/*
** if.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 15:13:36 2017 Yohan.Jabin
** Last update Thu May 18 21:57:54 2017 Yohan.Jabin
*/

#include "my.h"

int	check_if_parenthesis(char **imp, int len)
{
  if (my_strncmp(imp[len - 1], "then", 5) == 0)
    return (1);
  return (0);
}

int	test_if(t_my_var *data, char **imp)
{
  int	len;

  len = hm_many_env(imp);
  if (len >= 5 && check_if_parenthesis(imp, len) == 0)
    {
      if (my_strncmp(imp[2], "==", 3) == 1)
	{
	  if (my_strcmp(imp[1], imp[3]) != 1)
	    data->script.if_status = -1;
	}
      else if (my_strncmp(imp[2], "!=", 3) == 1)
	{
	  if (my_strcmp(imp[1], imp[3]) == 1)
	    data->script.if_status = -1;
	}
    }
  else
    return (1);
  return (0);
}

int	parse_if(t_my_var *data, char **imp, int flag)
{
  if (test_if(data, imp) == 1)
    {
      if (flag == 1)
	my_fprintf(2, "if: Expression Syntax.\n");
      else if (flag == 2)
	my_fprintf(2, "else: Expression Syntax.\n");
      data->return_value = 1;
      return (1);
    }
  return (0);
}
