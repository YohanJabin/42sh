/*
** my_memset.c for minishell2
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Tue Mar 28 10:02:45 2017 Hugo MARTIN
** Last update	Thu Mar 30 18:32:43 2017 Hugo MARTIN
*/

#include "my.h"

int	my_malloc(char	**str, char c, int size)
{
  int	i;
  char	*v;

  i = -1;
  if ((*str = malloc(sizeof(char) * size)) == NULL)
  {
    my_putstr("Error with malloc\n", 2);
    return (84);
  }
  v = *str;
  while (++i < size)
    v[i] = c;
  return (0);
}
