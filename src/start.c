/*
** start.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 17:51:07 2017 Hugo MARTIN
** Last update	Fri Apr 21 11:51:32 2017 Hugo MARTIN
*/

#include "my.h"

int	my_start(t_my_var *p)
{
  t_my_list_data	*command;

  //exec de .42shrc?
  while (42)
  {
    //prompt perso
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
