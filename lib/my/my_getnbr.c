/*
** my_getnbr.c for my_printf in /home/yohan/repo/PSU_2016_my_printf
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Mon Nov 14 21:05:45 2016 Yohan.Jabin
** Last update	Mon Apr 10 17:28:39 2017 Hugo MARTIN
*/

#include "my.h"

int     my_getnbr(const char *str)
{
  int   sign;
  int   result;

  sign = 1;
  result = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	     sign = - sign;
      str += 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      result = result * 10 + *str - 48;
      str = str + 1;
    }
  if (sign == -1)
    result = - result;
  return (result);
}
