/*
** start.c for  in /home/adrien/Epitech/Semestre2/Systeme_Unix/PSU_2016_42sh
** 
** Made by adrien
** Login   <adrien.zemma@epitech.eu>
** 
** Started on  Tue Apr 25 15:20:22 2017 adrien
** Last update Tue Apr 25 15:20:22 2017 adrien
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
      my_histori(command->data, data);
      //SET REDIR
      //BUILTINS
      //path
      //EXEC
      command = command->next;
    }
  }
}
