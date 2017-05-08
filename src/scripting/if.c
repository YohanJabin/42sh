/*
** if.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 15:13:36 2017 Yohan.Jabin
** Last update Mon May  8 13:50:01 2017 Yohan.Jabin
*/

#include "my.h"

void	start_if(t_my_var *data)
{
  char	*str;
  char	**arr;

  if (isatty(0) && data->flag_prompt == 1)
    my_printf("if? ");
  while ((str = get_next_line(0)) != NULL)
    {
      arr = my_str_to_wordtab(str);
      if (my_strncmp(arr[0], "endif", 6) == 1)
	return ;
      if (isatty(0) && data->flag_prompt == 1)
	my_printf("if? ");
    }
  my_fprintf(2, "then: then/endif not found.\n");
  data->return_value = 1;
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

void	parse_if(t_my_var *data, char **imp)
{
  if (test_if(data, imp) == 1)
    {
      my_fprintf(2, "if: Expression Syntax.\n");
      data->return_value = 1;
    }
}
