/*
** my.h for my.h in /home/hugo.martin/CPool_Day12/include
**
** Made by Hugo MARTIN
** Login   <hugo.martin@epitech.net>
**
** Started on  Tue Oct 18 09:05:12 2016 Hugo MARTIN
** Last update	Tue Apr 25 15:45:22 2017 Adrien ZEMMA
*/

#ifndef MY_FPRINTF_H_
#define MY_FPRINTF_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void    my_putchar(char, int);
void    my_putstr(char*, int);
int     my_putnbr(int, int);
void    my_fprintf(int, char *, ...);
int     my_hexa(int, int);
int			my_convert(char *, int, int);
int     my_strlen(char *);
void    my_revstr(char *, int);
int     functions(char *, va_list, int, int);
void	my_put_tab(char **, int);

#endif /* MY_FPRINTF_H_ */
