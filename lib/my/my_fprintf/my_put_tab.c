/*
** my_put_tab.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Tue Apr 25 15:40:49 2017 Adrien ZEMMA
** Last update	Tue Apr 25 15:44:35 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_put_tab(char **tab, int nb)
{
  int i;

  i = -1;
  if (tab == NULL)
    return ;
  while (tab[++i] != NULL)
  {
    my_putstr(tab[i], nb);
    my_putstr("\n", nb);
  }
}
