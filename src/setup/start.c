/*
** start.c for  in /home/adrien/Epitech/Semestre2/Systeme_Unix/PSU_2016_42sh
**
** Made by adrien
** Login   <adrien.zemma@epitech.eu>
**
** Started on  Tue Apr 25 15:20:22 2017 adrien
** Last update	Fri Apr 28 15:19:41 2017 Hugo MARTIN
*/

#include "my.h"
#include "my_prompt.h"

int	my_start(t_my_var *p, t_my_data *data)
{
  t_my_list_data	*command;

  my_read_rc(data);
  while (42)
  {
    data->exit = -1;
    my_command(p, data);
    //my_separator(p);
    command = p->list_command->begin;
    while (command)
    {
      my_histori(command->data, data);
      if (parse_pipe(data, command->data) == 84)
	     return (84);
      command = command->next;
    }
    if (data->exit != -1)
      exit(data->ret);
  }
  return (0);
}
