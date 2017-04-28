/*
** command.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 19:43:08 2017 Hugo MARTIN
** Last update	Fri Apr 28 15:15:49 2017 Hugo MARTIN
*/

#include "my.h"

int	my_malloc_list(char *command)
{
  int	i;

  i = 0;
  while (command[i] != ';' && command[i] != '\0')
    i++;
  return (i);
}

int	my_count_vigp(char *command)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (command[++i])
    if (command[i] == ';' || command[i] == '\0')
      nb++;
  return (nb + 1);
}

void	my_list_command(t_my_var *v)
{
  char	*str;
  int	i;

  i = -1;
  v->list_command = NULL;
  while ((str = get_arg(v->full_command, ++i, ";"))[0] != '\0')
    add_end_list(&v->list_command, my_pure(str));
  if (v->list_command == NULL)
    add_end_list(&v->list_command, my_pure(v->full_command));
}

void	my_command(t_my_var *v, t_my_data *data)
{
  if (isatty(0))
    my_prompt(data);
  if (v->return_value != 0 && isatty(0) == 0)
    my_exit(v);
  if ((v->full_command = get_next_line(0)) == NULL)
    my_exit(v);
  else if (v->full_command[0] == '\0')
      my_command(v, data);
  my_list_command(v);
}
