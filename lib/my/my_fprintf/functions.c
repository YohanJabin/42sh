/*
** functions.c for functions in /home/hugo/Epitech/B1/PSU/PSU_2016_my_printf
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Fri Nov 18 12:28:18 2016 Hugo
** Last update	Tue Apr 25 15:44:53 2017 Adrien ZEMMA
*/

#include "my.h"

int	functions(char *fmt, va_list ap, int i, int fd)
{
  if (fmt[i + 1] == 's')
    my_putstr(va_arg(ap, char *), fd);
  else if (fmt[i + 1] == 'd' || (fmt[i + 1] == 'b'))
    my_putnbr(va_arg(ap, int), fd);
  else if (fmt[i + 1] == 'c')
    my_putchar(va_arg(ap, int), fd);
  else if (fmt[i + 1] == 'x')
    my_hexa(va_arg(ap, int), fd);
  else if (fmt[i + 1] == 't')
    my_put_tab(va_arg(ap, char **), fd);
  else
    my_putchar(fmt[i + 1], fd);
  i++;
  return (i);
}
