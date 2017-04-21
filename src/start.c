/*
** start.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 17:51:07 2017 Hugo MARTIN
** Last update	Fri Apr 21 14:32:59 2017 Adrien ZEMMA
*/

#include "my.h"
#include "my_prompt.h"

int	my_start(t_my_var *p, t_my_data *data)
{
  t_my_list_data	*command;

  my_read_rc(data);
  exit(0);
  while (42)
  {
    my_prompt(data);
    //command/list:
    my_command(p);
    command = p->list_command->begin;
    while (command)
    {
      my_printf("%s\n", command->data);
      //SET REDIR
      //BUILTINS
      //path
      //EXEC
      command = command->next;
    }
  }
}
