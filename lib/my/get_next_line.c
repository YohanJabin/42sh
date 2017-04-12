/*
** get_next_line.c for CPE_2016_Lemin
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Tue Apr 04 10:53:59 2017 Hugo MARTIN
** Last update	Fri Apr 07 11:25:55 2017 Hugo MARTIN
*/

#include "my.h"

char	*new_stock(char *tmp, int o, int u, int a)
{
  char	*st;

  if (my_malloc(&st, '\0', (my_len(tmp, 1) + 1)) == 84)
    return (NULL);
  if (my_len(tmp, 2) == 0)
    return (tmp);
  while (tmp[u] != '\n')
    {
      st[a] = tmp[u];
      a = a + 1;
      u = u + 1;
    }
  if (o == 2)
    return (st);
  a = -1;
  while (tmp[u] != '\0')
    {
      st[++a] = tmp[u + 1];
      u = u + 1;
    }
  return (st);
}

char	*my_ralloc(char *d, char *s, int o, int a)
{
  char	*st;
  int	i;

  if (my_malloc(&st, '\0', (my_len(d, 1) + my_len(s, 1) + 1)) == 84)
    return (NULL);
  i = -1;
  while (d[++i] != '\0')
    {
      st[a] = d[i];
      a = a + 1;
    }
  if (o == 2)
    return (st);
  i = -1;
  while (s[++i] != '\0')
    {
      st[a] = s[i];
      a = a + 1;
    }
  free(d);
  free(s);
  return (st);
}

int	my_len(char *str, int o)
{
  int	i;

  i = -1;
  if (o == 1)
    {
      while (str[++i] != '\0');
      return (i);
    }
  else
    {
      while (str[++i] != '\0')
	if (str[i] == '\n')
	  return (1);
    }
  return (0);
}

char	*my_process(char *str)
{
  static int	process = 0;

  if (process == 0)
    {
      if (my_malloc(&str, '\0', (READ_SIZE + 1)) == 84)
	return (NULL);
      process = 1;
    }
  return (str);
}

char	*get_next_line(int fd)
{
  static	char	*tmp;
  t_main	a;

  a.buffer = malloc(sizeof(char) * (READ_SIZE + 1));
  if (fd == -1 || a.buffer == NULL || (tmp = my_process(tmp)) == NULL)
    return (NULL);
  while (my_len(tmp, 2) == 0)
    {
      a.s = read(fd, a.buffer, READ_SIZE);
      if (a.s == -1)
	return (NULL);
      a.buffer[a.s] = '\0';
      tmp = my_ralloc(tmp, a.buffer, 0, 0);
      if (a.s == 0 && my_len(tmp, 1) == 0)
	return (NULL);
      else if (a.s == 0 && my_len(tmp, 2) == 0)
	{
	  a.st = my_ralloc(tmp, tmp, 2, 0);
	  tmp[0] = '\0';
	  return (a.st);
	}
    }
  a.src = new_stock(tmp, 2, 0, 0);
  tmp = new_stock(tmp, 0, 0, 0);
  return (a.src);
}
