/*
** scripting.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 10:45:30 2017 Yohan.Jabin
** Last update Mon May  8 15:27:02 2017 Yohan.Jabin
*/

#include "my.h"

int	test_cmd_scripting(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "if", 3) == 1)
    {
      parse_if(data, imp);
      if (data->script.if_status == -1)
	{
	  start_if(data);
	  data->script.if_status = 0;
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

void	parse_scripting_arg(t_my_var *data, int ac, char **av)
{
  char	tmp[100];
  int	i;

  i = 0;
  while (++i < ac)
    {
      my_memset(tmp, 0, 100);
      sprintf(tmp, "%i=%s", i - 1, av[i]);
      setvar(data, tmp);
    }
}

void	parse_scripting(t_my_var *data, int ac, char **av)
{
  int	fd;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    exit (84);
  parse_scripting_arg(data, ac, av);
  data->fd_to_read = fd;
  data->flag_prompt = 0;
}

void	init_scripting(t_my_var *data, int ac, char **av)
{
  data->fd_to_read = 0;
  data->script.if_status = 0;
  data->script.foreach_status = 0;
  data->script.foreach_var = NULL;
  data->script.foreach_words = NULL;
  data->flag_prompt = 1;
  if (ac > 1)
    parse_scripting(data, ac, av);
}
