/*
** get_arg.c for PSU_2016_42sh
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Fri Apr 28 10:05:14 2017 Hugo MARTIN
** Last update	Fri May 19 15:17:29 2017 Hugo MARTIN
*/

#include "my.h"

char	*get_full(char *str, int n, char *c)
{
  char	*tmp;
  int	i;

  tmp = str;
  i = 0;
  while (i != n && *tmp)
  {
    if (my_strncmp(tmp, c, my_strlen(c)) == 1)
      i++;
    tmp++;
  }
  return (tmp);
}

char	*get_arg(char *str, int n, char *c)
{
  char	*tmp;
  char	*a;
  int	i;
  int	j;

  my_malloc(&a, '\0', my_strlen(str) + 1);
  tmp = str;
  j = -1;
  i = 0;
  while (i != n && *tmp)
    {
      if (*tmp == '`')
	while (*(++tmp) && *tmp != '`');
      if (my_strncmp(tmp, c, my_strlen(c)) == 1)
	i++;
      tmp++;
    }
  if (my_strncmp(tmp, c, my_strlen(c)) == 1)
    tmp++;
  while ((*tmp) && (my_strncmp(tmp, c, my_strlen(c)) == 0))
    {
      if (*tmp == '`')
	{
	  a[++j] = *tmp;
	  while (*(++tmp) && *tmp != '`')
	    a[++j] = *tmp;
	}
      if (*tmp)
	a[++j] = *tmp;
      tmp++;
    }
  return (a);
}
