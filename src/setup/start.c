/*
** start.c for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Fri Apr 28 16:11:10 2017 Hugo
** Last update Sat Apr 29 17:57:22 2017 Yohan.Jabin
*/

#include "my.h"
#include "my_prompt.h"

int	my_start(t_my_var *p, t_my_prompt *prompt)
{
  t_my_list_data	*command;

  my_read_rc(prompt);
  while (42)
  {
    p->exit = -1;
    my_command(p, prompt);
    command = p->list_command->begin;
    p->return_value = 0;
    while (command)
    {
      //my_printf("%s\n", command->data);
      my_histori(command->data, prompt);
      if (parse_pipe(p, command->data) == 84)
	     return (84);
      command = command->next;
    }
    if (p->exit != -1)
      exit(p->return_value);
  }
  return (0);
}
