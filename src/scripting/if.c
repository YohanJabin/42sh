/*
** if.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 15:13:36 2017 Yohan.Jabin
** Last update Thu May  4 19:54:08 2017 Yohan.Jabin
*/

#include "my.h"

void	start_if(t_my_var *data)
{
  char	*str;
  char	**arr;

  if (isatty(0))
    my_printf("if? ");
  while ((str = get_next_line(0)) != NULL)
    {
      arr = my_str_to_wordtab(str);
      if (my_strncmp(arr[0], "endif", 6) == 1)
	return ;
      if (isatty(0))
	my_printf("if? ");
    }
  my_fprintf(2, "then: then/endif not found.\n");
  data->return_value = 1;
}

int	check_if_parenthesis(char **imp, int len)
{
  if (imp[1][0] != '(' || imp[len - 2][0] != ')')
    return (1);
  if (my_strncmp(imp[len - 1], "then", 5) == 0)
    return (1);
  return (0);
}

int	test_if(t_my_var *data, char **imp)
{
  int	len;

  len = hm_many_env(imp);
  if (len >= 7 && check_if_parenthesis(imp, len) == 0)
    {
      if (my_strncmp(imp[3], "==", 3) == 1)
	{
	  if (my_strcmp(imp[2], imp[4]) != 1)
	    data->script.if_status = -1;
	}
      else if (my_strncmp(imp[3], "!=", 3) == 1)
	{
	  if (my_strcmp(imp[2], imp[4]) == 1)
	    data->script.if_status = -1;
	}
    }
  else
    return (1);
  return (0);
}

void	parse_if(t_my_var *data, char **imp)
{
  if (test_if(data, imp) == 1)
    {
      my_fprintf(2, "if: Expression Syntax.\n");
      data->return_value = 1;
    }
}
