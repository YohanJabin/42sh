/*
** start.c for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Fri Apr 28 16:11:10 2017 Hugo
** Last update Fri Apr 28 16:11:32 2017 Hugo
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
