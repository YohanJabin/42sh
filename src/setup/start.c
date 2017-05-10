/*
** start.c for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
**
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
**
** Started on  Fri Apr 28 16:11:10 2017 Hugo
** Last update	Wed May 10 15:20:12 2017 Hugo MARTIN
*/

#include "my.h"
#include "my_prompt.h"
//TODO
int	my_control(t_my_var *p, t_my_separator *s)
{
  //my_printf("Command: %s\nFlag: %d\nReturn Value: %d\n\n", s->command, s->flag, p->return_value);
  if (p->return_value != 0 && s->flag == 1)
    return (-1);
  else if (p->return_value != 0 && s->flag == 2)
    return (0);
  else if (p->return_value == 0 && s->flag == 2)
    return (-1);
  return (0);
}

int	my_start(t_my_var *p, t_my_prompt *prompt)
{
  t_my_list_data	*separator;
  t_my_separator	*tmp;

  p->prompt = prompt;
  my_read_rc(prompt);
  while (42)
    {
      update_env(p);
      p->exit = -1;
      if ((my_command(p, prompt)) == -1)
	    {
	      if (p->fd_to_read != 0 && close(p->fd_to_read));
	      my_exit(p);
	    }
      separator = p->separator->begin;
      p->return_value = 0;
      while (separator && (tmp = (t_my_separator *) separator->data) &&
              my_control(p, tmp) == 0)
      {
        my_histori(tmp->command, prompt);
        if (parse_pipe(p, tmp->command) == 84)
          return (84);
        separator = separator->next;
      }
      if (p->exit != -1)
	     exit(p->return_value);
    }
    return (0);
}
