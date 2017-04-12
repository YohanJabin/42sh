/*
** start.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Wed Apr 12 17:51:07 2017 Hugo MARTIN
** Last update	Wed Apr 12 20:10:10 2017 Hugo MARTIN
*/

#include "my.h"

int	my_start(t_my_var *p)
{
  //exec de .42shrc ?
  while (42)
  {
    //prompt
    //command/list:
    my_command(p);
    /*FIXME*/aff_list(p->list_command);
    //PATH
    //exec
  }
}
