/*
** arr_star.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/formatting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Mon May 15 18:05:40 2017 Yohan.Jabin
** Last update Tue May 16 16:17:28 2017 Yohan.Jabin
*/

#include "my.h"

int	hm_stars(char *str)
{
  int	hm;
  int	i;

  hm = 0;
  i = -1;
  while (str[++i] != 0)
    if (str[i] == '*')
      hm++;
  return (hm);
}

int	size_next_star(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] == '*')
      return (i);
  return (i);
}

int	parse_arr_star(char **arr, char *str, int *j)
{
  int	i;
  int	len;
  int	size;

  size = my_strlen(str);
  i = 0;
  while (i < size)
    {
      len = size_next_star(&str[i]);
      if ((arr[*j] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (84);
      my_memset(arr[*j], 0, len + 1);
      my_strncpy(arr[*j], &str[i], len);
      i += len + 1;
      (*j)++;
    }
  return (0);
}

char	**create_arr_star(char *str)
{
  char	**arr;
  int	len;
  int	j;

  j = 0;
  len = hm_stars(str) + 1;
  if ((arr = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  arr[len] = NULL;
  if (parse_arr_star(arr, str, &j) == 84)
    return (NULL);
  if (str[my_strlen(str) - 1] == '*')
    {
      arr[len - 1] = malloc(sizeof(char));
      arr[len - 1][0] = 0;
    }
  return (arr);
}
