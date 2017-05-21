/*
** my_str_is_alpha.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/utils
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sun May 21 12:53:23 2017 Yohan.Jabin
** Last update Sun May 21 12:53:45 2017 Yohan.Jabin
*/

#include "my.h"

int     my_str_is_alpha(char *str)
{
  int   i;

  i = -1;
  while (str[++i] != 0)
    {
      if (str[i] < 'A' ||
	  (str[i] > 'Z' && str[i] < 'a')
	  || str[i] > 'z')
	return (0);
    }
  return (1);
}
