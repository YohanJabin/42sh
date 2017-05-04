/*
** func.c for minishell in /home/yohan/repo/PSU/my_minishell
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Thu Mar  2 17:00:42 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:26 2017 Adrien ZEMMA
*/

#include "my.h"

int	is_there_a_slash(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

int	my_str_is_alpha(char *str)
{
  int	i;

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

int	my_str_is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}
