/*
** my_strcmp.c for PSU_2016_minishell1
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Tue Feb 21 15:38:43 2017 Hugo MARTIN
** Last update	Tue Feb 21 16:35:31 2017 Hugo MARTIN
*/

#include "my.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = -1;
  while (str1[++i] != '\0' || str2[i] != '\0')
  {
    if (str1[i] != str2[i])
      return (0);
  }
  return (1);
}
