/*
** main.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Tue May  2 10:57:05 2017 Camille Gouneau
** Last update Wed May  3 11:55:08 2017 Camille Gouneau
*/

#include  <stdio.h>
#include  <unistd.h>
#include  <string.h>
#include  <stdlib.h>
#include  "auto_complet.h"

int main(void)
{
  int   to_return;
  char  *gnl_return;

  to_return = 0;
  while (1)
  {
    if (isatty(0) == 1)
      my_fput("auto_completion_v0.1> ", 1);
    gnl_return = get_next_line(0);
    if (gnl_return == NULL)
      return (to_return);
    if (gnl_return[0] != '\0')
      auto_complet(gnl_return);
    free (gnl_return);
  }
}
