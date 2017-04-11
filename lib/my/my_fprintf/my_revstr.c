/*
**     my_revstr.c for my_revstr in /home/hugo.martin/CPool_Day06
**
** Made by Hugo MARTIN
** Login   <hugo.martin@epitech.net>
**
** Started on  Mon Oct 10 08:52:32 2016 Hugo MARTIN
** Last update	Tue Apr 04 15:38:55 2017 Hugo MARTIN
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i++;
    }
  return (i);
}

void	my_revstr(char *str, int fd)
{
  int	i;

  i = my_strlen(str);
  while (i >= 0)
    {
      my_putchar(str[i], fd);
      i = i - 1;
    }
}
