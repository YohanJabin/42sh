/*
** start.c for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
**
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
**
** Started on  Fri Apr 28 16:11:10 2017 Hugo
** Last update	Fri May 19 17:55:36 2017 Hugo MARTIN
*/

#include "my.h"

int	my_control(t_my_var *p, t_my_separator *s, t_my_list_data	*separator)
{
  if (s->flag == 1)
  {
    if (p->return_value != 0)
    {
      if (separator->next != NULL)
        p->return_value = 1;
      return (-1);
    }
  }
  else if (s->flag == 2)
  {
    if (p->return_value == 0)
    {
      if (separator->next != NULL)
        p->return_value = 1;
      return (-1);
    }
  }
  return (0);
}

int	my_send_to_exec(t_my_var *p, t_my_separator *tmp, t_my_prompt *prompt)
{
  p->return_value = 0;
  update_env(p);
  my_histori(tmp->command, prompt);
  if (parse_pipe(p, tmp->command) == 84)
    return (84);
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
      if ((p->exit = -1) == -1 && (my_command(p, prompt)) == -1)
	     {
	        if (p->fd_to_read != 0)
            close(p->fd_to_read);
	        my_exit(p);
	     }
       if (p->separator != NULL)
       {
        separator = p->separator->begin;
        while (separator && (tmp = (t_my_separator *) separator->data))
        {
          if (my_control(p, tmp, separator) == 0)
            if (my_send_to_exec(p, tmp, prompt) == 84)
              return (84);
        separator = separator->next;
        }
        if (p->exit != -1)
        	my_exit(p);
       }
    }
  return (0);
}
