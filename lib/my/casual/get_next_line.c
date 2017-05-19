/*
** get_next_line.c for gol in /home/yohan/repo/Colles/CPE_2016_stumper4/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Tue May  9 18:21:26 2017 Yohan.Jabin
** Last update Fri May 19 13:53:02 2017 Yohan.Jabin
*/

#include "my.h"

char	*gnl_realloc(char *str, int size)
{
  char	*ret;
  int	i;

  size += my_strlen(str);
  if ((ret = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  my_memset(ret, 0, size + 1);
  i = 0;
  while (str[i] != 0)
    {
      ret[i] = str[i];
      i++;
    }
  free(str);
  return (ret);
}

char	*gnl_ret(char *ret)
{
  int	len;

  if ((len = my_strlen(ret)) == 0)
    {
      free(ret);
      return (NULL);
    }
  if (ret[len - 1] == '\n')
    ret[len - 1] = 0;
  return (ret);
}

char	*get_next_line(int fd)
{
  char	*ret;
  char	c;
  int	i;

  if ((ret = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  my_memset(ret, 0, 2);
  i = 0;
  c = 1;
  while (c != 0 && c != '\n')
    {
      if (read(fd, &c, 1) < 1)
	return (gnl_ret(ret));
      ret[i] = c;
      if ((ret = gnl_realloc(ret, i + 1)) == NULL)
	return (NULL);
      i++;
    }
  return (gnl_ret(ret));
}
