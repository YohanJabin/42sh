/*
** my_strcmp.c for PSU_2016_minishell1
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Tue Feb 21 15:38:43 2017 Hugo MARTIN
** Last update	Tue Apr 11 16:54:22 2017 Hugo MARTIN
*/

#include "my.h"

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = -1;
  while (++i < n)
  {
    if (str1[i] != str2[i])
      return (0);
  }
  return (1);
}
