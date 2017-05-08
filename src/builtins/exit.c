/*
** exit.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 10:29:31 2017 Yohan.Jabin
** Last update Mon May  8 15:46:45 2017 Yohan.Jabin
*/

#include "my.h"

int	test_cmd_exit(t_my_var *data, char **imp)
{
  if (my_strncmp(&imp[0][0], "exit", 5))
    {
      data->exit = 0;
      if (imp[1] != NULL)
	data->return_value = my_getnbr(imp[1]);
      return (0);
    }
  return (1);
}
