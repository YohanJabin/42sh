/*
** my_str_is_num.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/utils
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sun May 21 12:54:00 2017 Yohan.Jabin
** Last update Sun May 21 12:54:21 2017 Yohan.Jabin
*/

#include "my.h"

int	my_str_is_num(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}
