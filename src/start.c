/*
** start.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 17:51:07 2017 Hugo MARTIN
** Last update	Mon Apr 24 17:28:48 2017 Hugo MARTIN
*/

#include "my.h"
#include "my_prompt.h"

int	my_start(t_my_var *p, t_my_data *data)
{
  t_my_list_data	*command;

  //my_read_rc(data);
  while (42)
  {
    //my_prompt(data);
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
