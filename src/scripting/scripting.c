/*
** scripting.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 10:45:30 2017 Yohan.Jabin
** Last update Thu May  4 18:51:54 2017 Yohan.Jabin
*/

#include "my.h"

int	test_cmd_scripting(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "if", 3) == 1)
    {
      my_if(data, imp);
      if (data->script.if_status == -1)
	{
	  start_if(data);
	  data->script.if_status = 0;
	  data->flag_prompt = 1;
	}
      return (0);
    }
  else if (my_strncmp(imp[0], "foreach", 8) == 1)
    {
      parse_foreach(data, imp);
      return (0);
    }
  return (1);
}

void	init_scripting(t_my_var *data)
{
  data->script.if_status = 0;
  data->script.foreach_status = 0;
  data->script.foreach_var = NULL;
  data->script.foreach_words = NULL;
  data->flag_prompt = 0;
}
