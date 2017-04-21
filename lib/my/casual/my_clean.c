/*
** my_clean.c for PSU_2016_minishell2
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Tue Mar 14 13:33:05 2017 Adrien ZEMMA
** Last update	Fri Apr 21 13:51:18 2017 Adrien ZEMMA
*/

#include "my.h"

char	*my_clean(char *str)
{
  int	nb[2];
  char *lel;

  nb[0] = -1;
  nb[1] = 0;
  if (str == NULL)
    return (NULL);
  my_malloc(&lel, '\0', my_strlen(str) + 1);
  while (str[++nb[0]] != '\0')
  {
    if (str[nb[0]] >= 33)
    {
      lel[nb[1]] = str[nb[0]];
      nb[1] = nb[1] + 1;
      if (str[nb[0] + 1] == ' ' || str[nb[0] + 1] == '\t')
      {
        lel[nb[1]] = ' ';
        nb[1] = nb[1] + 1;
      }
    }
  }
  while (lel[--nb[1]] <= 33)
    lel[nb[1]] = '\0';
  lel[nb[1] + 1] = '\0';
  return (lel);
}
