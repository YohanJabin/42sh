/*
** my_stradd.c for my_stradd in /home/yohan/repo/PSU/PSU_2016_42sh/src/utils
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sat May  6 18:58:44 2017 Yohan.Jabin
** Last update Mon May  8 14:27:49 2017 Yohan.Jabin
*/

#include "my.h"

char	*my_stradd(char *str, char *to_add, int pos)
{
  char  *ret;
  int   len;
  int   i;
  int   j;

  len = my_strlen(str) + my_strlen(to_add);
  if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_memset(ret, 0, len + 1);
  i = 0;
  j = 0;
  while (i < len)
    {
      if (i == pos)
	while (to_add[j] != 0)
	  ret[i++] = to_add[j++];
      ret[i] = str[i - j];
      i++;
    }
  return (ret);
}
