/*
** echo.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Wed May 17 12:45:22 2017 Yohan.Jabin
** Last update Sun May 21 19:15:30 2017 Yohan.Jabin
*/

#include "my.h"

void	process_echo(char **imp, int flag_return)
{
  int	size;
  int	i;

  size = hm_line_on_tab(imp);
  i = -1;
  while (++i < size - 1)
    my_printf("%s ", imp[i]);
  my_printf("%s", imp[i]);
  if (flag_return == 0)
    my_printf("\n");
}

int	test_cmd_echo(char **imp)
{
  if (my_strncmp(imp[0], "echo", 5))
    {
      if (imp[1] == NULL)
	{
	  my_printf("\n");
	  return (0);
	}
      if (my_strncmp(imp[1], "-n", 3))
	process_echo(&imp[2], 1);
      else
	process_echo(&imp[1], 0);
      return (0);
    }
  return (1);
}
