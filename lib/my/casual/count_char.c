/*
** count_char.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Fri Apr 28 10:04:56 2017 Hugo MARTIN
** Last update	Fri Apr 28 10:04:59 2017 Hugo MARTIN
*/

#include "my.h"

int	my_check_char(char *str, char c)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (str[++i])
    if (str[i] == c)
      nb++;
  return (nb);
}
