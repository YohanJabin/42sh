/*
** start.c for  in /home/adrien/Epitech/Semestre2/Systeme_Unix/PSU_2016_42sh
**
** Made by adrien
** Login   <adrien.zemma@epitech.eu>
**
** Started on  Tue Apr 25 15:20:22 2017 adrien
** Last update	Fri Apr 28 15:29:33 2017 Adrien ZEMMA
*/

#include "my.h"
#include "my_prompt.h"

int	my_start(t_my_var *p, t_my_prompt *prompt)
{
  t_my_list_data	*command;

  my_read_rc(prompt);
  while (42)
  {
    data->exit = -1;
    my_command(p, prompt);
    command = p->list_command->begin;
    while (command)
    {
      //my_printf("%s\n", command->data);
      my_histori(command->data, prompt);
      if (parse_pipe(data, command->data) == 84)
	return (84);
      command = command->next;
    }
    if (data->exit != -1)
      exit(data->ret);
  }
  return (0);
}
