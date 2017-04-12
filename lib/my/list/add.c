/*
** add.c for list_chained
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Mar 13 22:17:02 2017 Hugo MARTIN
** Last update	Wed Apr 12 20:03:54 2017 Hugo MARTIN
*/

#include "my.h"

void	add_end_list(t_my_list_cont **list, void *str)
{
  t_my_list_data	*element;

  element = malloc(sizeof(*element));
  element->data = str;
  element->next = NULL;
  element->prev = NULL;
  if ((*list) == NULL)
  {
    *list = malloc(sizeof(**list));
    (*list)->length = 0;
    (*list)->begin = element;
    (*list)->end = element;
  }
  else
  {
    (*list)->end->next = element;
    element->prev = (*list)->end;
    (*list)->end = element;
  }
  (*list)->length++;
}

void	add_start_list(t_my_list_cont **list, void *str)
{
  t_my_list_data	*element;

  element = malloc(sizeof(*element));
  element->data = str;
  element->next = NULL;
  element->prev = NULL;
  if (*list == NULL)
  {
    (*list) = malloc(sizeof(**list));
    (*list)->length = 0;
    (*list)->begin = element;
    (*list)->end = element;
  }
  else
  {
    (*list)->begin->prev = element;
    element->next = (*list)->begin;
    (*list)->begin = element;
  }
  (*list)->length++;
}

void	link_end_list(t_my_list_cont **list, t_my_list_data *data)
{
  if (*list == NULL)
  {
    (*list) = malloc(sizeof(**list));
    (*list)->length = 0;
    (*list)->begin = data;
    (*list)->end = data;
  }
  else if (data != NULL)
  {
    (*list)->end->next = data;
    data->prev = (*list)->end;
    (*list)->end = data;
  }
}
