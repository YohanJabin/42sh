/*
** if.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 15:13:36 2017 Yohan.Jabin
** Last update Sun May 21 15:04:17 2017 Yohan.Jabin
*/

#include "my.h"

void	test_cmd_scripting_else(t_my_var *data, char **imp, char **arr)
{
  if (imp[1] != NULL && my_strncmp(imp[1], "if", 3) == 1)
    {
      parse_if(data, &imp[1], 2);
      data->script.foreach_if_status = data->script.if_status;
      if (data->script.if_status == -1)
	{
	  start_if(data, "else", arr);
	  data->script.if_status = 0;
	}
      return ;
    }
  else
    start_if(data, "else", arr);
  return ;
}

int     test_cmd_scripting_if(t_my_var *data, char **imp, char **arr)
{
  data->script.foreach_if_status = 0;
  if (my_strncmp(imp[0], "if", 3) == 1)
    {
      parse_if(data, imp, 1);
      data->script.foreach_if_status = data->script.if_status;
      if (data->script.if_status == -1)
	{
	  start_if(data, "if", arr);
	  data->script.if_status = 0;
	}
      return (0);
    }
  else if (my_strncmp(imp[0], "else", 5) == 1)
    {
      test_cmd_scripting_else(data, imp, arr);
      return (0);
    }
  return (1);
}

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
