/*
** my_malloc.c for PSU_2016_minishell2
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Mon Apr 03 17:08:23 2017 Adrien ZEMMA
** Last update	Tue Apr 25 15:29:37 2017 Adrien ZEMMA
*/

#include "my.h"

int	my_malloc(char	**str, char c, int size)
{
  int	i;
  char	*v;

  i = -1;
  if ((*str = malloc(sizeof(char) * size)) == NULL)
  {
    my_putstr("Error with malloc\n", 1);
    *str = NULL;
    return (84);
  }
  v = *str;
  while (++i < size)
    v[i] = c;
  return (0);
}
