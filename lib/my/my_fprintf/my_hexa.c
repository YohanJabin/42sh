/*
** my_hexa.c for my_hexa in /home/hugo/Epitech/B1/PSU/PSU_2016_my_printf
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Mon Nov 14 22:11:05 2016 Hugo
** Last update	Tue Apr 04 15:38:58 2017 Hugo MARTIN
*/

#include "my.h"

int	my_hexa(int nb, int fd)
{
  int	i;
  int	backup;
  char	*str;

  backup = nb;
  str = malloc(sizeof(char) * (nb / 2));
  i = 0;
  while (nb >= 1)
    {
      nb = nb % 16;
      if (nb >= 0 && nb <= 9)
	{
	  str[i] = nb + 48;
	}
      else
	{
	  my_convert(str, nb, i);
	}
      nb = backup;
      nb = nb / 16;
      backup = nb;
      i++;
    }
  my_revstr(str, fd);
  return (0);
}

int	my_convert(char *str, int nb, int i)
{
  if (nb == 10)
    str[i] = 'a';
  else if (nb == 11)
    str[i] = 'b';
  else if (nb == 12)
    str[i] = 'c';
  else if (nb == 13)
    str[i] = 'd';
  else if (nb == 14)
    str[i] = 'e';
  else if (nb == 15)
    str[i] = 'f';
  return (0);
}
