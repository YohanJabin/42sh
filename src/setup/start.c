/*
** start.c for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Fri Apr 28 16:11:10 2017 Hugo
** Last update Sat May  6 13:58:27 2017 Yohan.Jabin
*/

#include "my.h"
#include "my_prompt.h"

int	my_start(t_my_var *p, t_my_prompt *prompt)
{
  t_my_list_data	*command;

  p->prompt = prompt;
  my_read_rc(prompt);
  while (42)
  {
    p->exit = -1;
    if ((my_command(p, prompt)) == -1)
      {
	if (p->fd_to_read != 0)
	  close(p->fd_to_read);
	my_exit(p);
      }
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
