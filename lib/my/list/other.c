/*
** main.c for list_chained
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Mar 13 21:30:40 2017 Hugo MARTIN
** Last update	Sat Apr 08 18:40:47 2017 Hugo MARTIN
*/

#include "list.h"
#include "my_printf.h"

void	aff_list(t_my_list_cont *list)
{
  t_my_list_data	*tmp;

  if (list == NULL)
    return ;
  tmp = list->begin;
  while (tmp != NULL)
  {
    my_printf("%s\n", tmp->data);
    tmp = tmp->next;
  }
  my_printf("(null)");
}

void	free_list(t_my_list_cont *list)
{
  t_my_list_data	*tmp;
  t_my_list_data	*del;

  tmp = list->begin;
  if (list == NULL)
    return ;
  if (list->length == 1 && list->begin == list->end)
    free(list);
  else
  {
    while (tmp)
    {
      del = tmp;
      tmp = tmp->next;
      free(del);
      del = NULL;
    }
    free (list);
  }
}
