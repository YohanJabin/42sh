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

void	get_arg_cpy(char *tmp, char *a, char *c)
{
  int	j;

  j = -1;
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
}

char	*get_arg(char *str, int n, char *c)
{
  char	*tmp;
  char	*a;
  int	i;

  my_malloc(&a, '\0', my_strlen(str) + 1);
  tmp = str;
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
  get_arg_cpy(tmp, a, c);
  return (a);
}
