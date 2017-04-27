/*
** command.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 19:43:08 2017 Hugo MARTIN
** Last update	Tue Apr 25 15:23:46 2017 Adrien ZEMMA
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
  t_my_args	b;

  b.i = -1;
  b.j = -1;
  b.n = 0;
  v->list_command = NULL;
  while (++b.i != my_count_vigp(v->full_command) && (b.k = 0) == 0)
  {
    my_malloc(&str, '\0', my_strlen(v->full_command) + 1);
    while (v->full_command[++b.j] != ';' && v->full_command[b.j] != '\0')
    {
      str[b.k] = v->full_command[b.j];
      b.k++;
    }
    if (my_strcmp(my_pure(str), "exit") != 1)
      add_end_list(&v->list_command, my_pure(str));
    else
      b.n = 1;
  }
  if (b.n == 1)
    add_end_list(&v->list_command, "exit");
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
