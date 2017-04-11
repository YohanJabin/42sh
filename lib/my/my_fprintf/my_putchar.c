/*
** my_putchar.c for my_putchar in /data/Epitech/B1/PSU/PSU_2016_my_printf
**
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
**
** Started on  Sun Feb 26 11:16:46 2017 Hugo
** Last update	Tue Apr 04 15:38:57 2017 Hugo MARTIN
*/

#include "my.h"

void	my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}
