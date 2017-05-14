/*
** my_strcut.c for my_strcut in /home/yohan/repo/PSU/PSU_2016_42sh/src/utils
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sat May  6 18:59:23 2017 Yohan.Jabin
** Last update Sat May  6 18:59:44 2017 Yohan.Jabin
*/

#include "my.h"

char	*my_strcut(char *str, int pos, int n)
{
  char  *ret;
  int   len;
  int   i;
  int   j;

  len = my_strlen(str);
  if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_memset(ret, 0, len + 1);
  j = 0;
  i = 0;
  while (i + j < len)
    {
      if (i == pos)
	while (j < n)
	  j++;
      if (i + j < len)
	ret[i] = str[i + j];
      i++;
    }
  return (ret);
}
