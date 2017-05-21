/*
** func3.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Mon Mar 27 19:33:09 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:28 2017 Adrien ZEMMA
*/

#include "my.h"

void    my_strncpy(char *s1, char *s2, int n)
{
  int   i;

  i = -1;
  while (++i < n)
    s1[i] = s2[i];
}

void    my_memset(char *str, char c, int len)
{
  int   i;

  i = -1;
  while (++i < len)
    str[i] = c;
}

char    *my_pathadd(char *dir, char *file)
{
  char  *return_value;
  int   i;
  int   j;

  i = my_strlen(dir) + my_strlen(file) + 2;
  return_value = malloc(sizeof(char) * i);
  my_memset(return_value, 0, i);
  i = -1;
  while (dir[++i] != 0)
    return_value[i] = dir[i];
  if (return_value[i - 1] != '/')
    return_value[i++] = '/';
  j = -1;
  while (file[++j] != 0)
    return_value[i + j] = file[j];
  return (return_value);
}

int	is_it_num_alpha(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    {
      if (str[i] < '0'
	  || (str[i] > '9' && str[i] < 'A')
	  || (str[i] > 'Z' && str[i] < 'a')
	  || str[i] > 'z')
	return (0);
    }
  return (1);
}

int     is_there_a_slash(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}
