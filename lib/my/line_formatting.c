/*
** line_formatting.c for CPE_2016_Lemin
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Apr 10 17:38:55 2017 Hugo MARTIN
** Last update	Mon Apr 10 17:57:25 2017 Hugo MARTIN
*/

#include "my.h"

int	line_formatting(char *str)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (str[++i])
    if (str[i] == ' ' || str[i] == '-' || str[i] == '\t')
      nb++;
  return (nb);
}
