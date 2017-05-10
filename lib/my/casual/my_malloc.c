/*
** my_malloc.c for  in /home/hugo
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Tue May  9 19:02:17 2017 Hugo
** Last update Tue May  9 19:02:20 2017 Hugo
*/

#include "my.h"

int	my_malloc(char	**str, char c, int size)
{
  int	i;
  char	*v;

  i = -1;
  if ((*str = malloc(sizeof(char) * size)) == NULL)
  {
    my_putstr("Error with malloc\n", 1);
    *str = NULL;
    return (84);
  }
  v = *str;
  while (++i < size)
    v[i] = c;
  return (0);
}
