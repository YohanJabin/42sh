/*
** varargs.c for test in /home/hugo/test_c
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Thu Nov 10 16:22:25 2016 Hugo
** Last update	Tue Apr 04 15:38:32 2017 Hugo MARTIN
*/

#include "my.h"

void	my_fprintf(int fd, char *fmt, ...)
{
  va_list	ap;
  int	i;

  i = -1;
  va_start(ap, fmt);
  while (fmt[++i])
    {
      if (fmt[i] == '%')
	     i = functions(fmt, ap, i, fd);
      else
	     my_putchar(fmt[i], fd);
    }
  va_end(ap);
}
