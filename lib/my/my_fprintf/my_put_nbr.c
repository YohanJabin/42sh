/*
** my_putnbr2.c for putnbr in /home/hugo.martin/progs
**
** Made by Hugo MARTIN
** Login   <hugo.martin@epitech.net>
**
** Started on  Tue Oct 25 18:52:34 2016 Hugo MARTIN
** Last update	Tue Apr 04 15:38:58 2017 Hugo MARTIN
*/

#include "my.h"

int	my_putnbr(int nb, int fd)
{
  int   result;

  if (nb < 0)
    {
      my_putchar('-', fd);
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  result = (nb % 10);
	  nb = (nb - result) / 10;
	  my_putnbr(nb, fd);
	  my_putchar(result + 48, fd);
	}
      else if (nb < 10)
	my_putchar((nb % 10) + 48, fd);
      else
	return (0);
    }
  return (0);
}
