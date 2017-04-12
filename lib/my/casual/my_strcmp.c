/*
** my_strcmp.c for PSU_2016_minishell2
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Mar 22 11:01:55 2017 Adrien ZEMMA
** Last update	Sun Apr 09 23:19:54 2017 Adrien ZEMMA
*/

#include "my.h"

int	my_strcmp(char *str, char *av)
{
  int	a;

  a = 0;
  if (str == NULL || av == NULL)
    return (-1);
  while (str[a] != '\0' || av[a] != '\0')
  {
    if (str[a] == av[a])
      a = a + 1;
    else
      return (-1);
  }
  return (1);
}
