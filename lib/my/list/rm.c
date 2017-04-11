/*
** rm.c for list_chained
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Mar 13 22:17:14 2017 Hugo MARTIN
** Last update	Sat Apr 08 18:14:23 2017 Hugo MARTIN
*/

#include "my.h"

void	rm_end_list(t_my_list_cont **list)
{
  t_my_list_data	*tmp;

  if ((*list) == NULL)
    return ;
  if ((*list)->length == 1 && (*list)->begin == (*list)->end)
    free((*list));
  else
  {
    tmp = (*list)->end;
    (*list)->end = (*list)->end->prev;
    (*list)->end->next = NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    free(tmp);
    tmp = NULL;
  }
  (*list)->length--;
}

void	rm_start_list(t_my_list_cont **list)
{
  t_my_list_data	*tmp;

  if ((*list) == NULL)
    return ;
  if ((*list)->length == 1 && (*list)->begin == (*list)->end)
    free((*list));
  else
  {
    tmp = (*list)->begin;
    (*list)->begin = (*list)->begin->next;
    (*list)->begin->prev = NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    free(tmp);
    tmp = NULL;
  }
  (*list)->length--;
}
