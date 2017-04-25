/*
** my_putstr.c for my_putstr in /home/hugo.martin/CPool_Day04
**
** Made by Hugo MARTIN
** Login   <hugo.martin@epitech.net>
**
** Started on  Thu Oct  6 08:34:09 2016 Hugo MARTIN
** Last update	Tue Apr 25 15:47:54 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_putstr(char *str, int fd)
{
  if (str == NULL)
    write(fd, "(null)", my_strlen("(null)"));
  else
    write(fd, str, my_strlen(str));
}

void	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}
