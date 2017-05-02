/*
** separator.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Fri Apr 28 09:52:43 2017 Hugo MARTIN
** Last update	Fri Apr 28 14:11:09 2017 Hugo MARTIN
*/

#include "my.h"

void	my_double_end(t_my_var *p, char *command)
{
  char	*tmp;
  int	i;
  int	j;

  i = -1;
  j = -1;
  my_printf("DOUBLE END\n");
  my_malloc(&tmp, '\0', my_strlen(command));
  while (command[++i] != '&');
  my_printf("%d\n", i);
  while (++j < i)
    tmp[j] = command[j];
  j = -1;
  while (++j <= i)
    command++;
  my_printf("%s\n%s\n", command, tmp);
}

void	my_separator(t_my_var *p)
{
  t_my_list_data *command;
  int	i;
  int	j;
  char	*str;
  char	*s;

  p->separator = NULL;
  command = p->list_command->begin;
  while (command)
  {
    my_malloc(&str, '\0', my_strlen(command->data) + 1);
    i = -1;
    j = -1;
    s = (char *)command->data;
    while (s[++i])
    {
      str[++j] = s[i];
      if (s[i] == '&' && my_check_char(command->data, '&') == 2)
        my_double_end(p, str);
    }
    command = command->next;
  }
  exit (0);
}
