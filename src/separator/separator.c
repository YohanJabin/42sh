/*
** separator.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Fri Apr 28 09:52:43 2017 Hugo MARTIN
** Last update	Sun May 21 17:24:58 2017 Hugo MARTIN
*/

#include "my.h"

int	send_double(t_my_var *v, char *command, int flag)
{
  t_my_separator	*s;
  static int f = 0;

  if ((s = malloc(sizeof(*s))) == NULL)
    return (-1);
  s->flag = f;
  f = flag;
  s->command = my_pure(command);
  if (my_strncmp(my_pure(s->command), "repeat", 6) == 1)
  {
    my_repeat(v, s, my_pure(command));
    return (0);
  }
  add_end_list(&v->separator, s);
  return (0);
}

void	init_separator(int *i, int *j, char **str, char *command)
{
  *i = -1;
  *j = -1;
  my_malloc(str, '\0', my_strlen(command) + 1);
}

int	my_check_separator(t_my_var *v, char *command)
{
  t_my_data	d;

  init_separator(&d.i, &d.j, &d.str, command);
  while (command[++d.i])
    {
      if (command[d.i] == '`')
	while (command[++d.i] && command[d.i] != '`');
      if (command[d.i] == '&' && command[d.i + 1] &&
	  command[d.i + 1] == '&' && (d.i += 2))
	{
	  send_double(v, d.str, 1);
	  my_malloc(&d.str, '\0', my_strlen(command) + 1);
	  d.j = -1;
	}
      else if (command[d.i] == '|' && command[d.i + 1] &&
	       command[d.i + 1] == '|' && (d.i += 2))
	{
	  send_double(v, d.str, 2);
	  my_malloc(&d.str, '\0', my_strlen(command) + 1);
	  d.j = -1;
	}
      d.str[++d.j] = command[d.i];
    }
  send_double(v, d.str, 0);
  return (0);
}

void	debug_separator(t_my_list_cont *c)
{
  t_my_list_data	*d;
  t_my_separator	*s;

  d = c->begin;
  while (d)
  {
    s = (t_my_separator *)d->data;
    my_printf("Command: [%s]\nFlag: %d\n\n", s->command, s->flag);
    d = d->next;
  }
}

void	separator(t_my_var *v)
{
  t_my_list_data	*command;

  command = v->list_command->begin;
  v->separator = NULL;
  while (command)
  {
    my_check_separator(v, (char *)command->data);
    command = command->next;
  }
}
