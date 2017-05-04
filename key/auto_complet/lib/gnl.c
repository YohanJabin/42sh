/*
** gnl.c for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/CPE_2016_matchstick/lib/my/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Tue Feb 21 10:27:17 2017 Camille Gouneau
** Last update Tue May  2 11:51:26 2017 Camille Gouneau
*/

#include  <unistd.h>
#include  <stdlib.h>
#include  <string.h>
#include  "auto_complet.h"

void  *my_malloc(int size)
{
  char  *str;

  if ((str = malloc(size)) == NULL)
    exit (1);
  return (str);
}

char  *my_realloc(char *str)
{
  int i;
  char *str_real;

  i = 0;
  str_real = my_malloc((sizeof(char) * strlen(str)) + 2);
  while (str[i])
    {
      str_real[i] = str[i];
      i++;
    }
  str_real[strlen(str) + 1] = '\0';
  return (str_real);
}

char   *get_next_line(int fd)
{
  int i;
  char *str;
  char  buffer;

  i = 0;
  str = my_malloc(sizeof(char) * 2);
  str[1] = '\0';
  while (1)
    {
      if (read(fd, &buffer, 1) == 0)
        return (0);
      if (buffer == '\n')
        {
          if (i == 0)
            str[0] = '\0';
          return (str);
        }
      str[i] = buffer;
      str = my_realloc(str);
      i++;
      str[i] = '\0';
    }
  return (str);
}
