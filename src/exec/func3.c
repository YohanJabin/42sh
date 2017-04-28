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

int	hm_line_on_tab(char **arr)
{
  int	i;

  i = -1;
  while (arr[++i] != NULL);
  return (i);
}

void	free_triple_tab(char ***arr)
{
  int	i;
  int	j;

  i = -1;
  while (arr[++i] != NULL)
    {
      j = -1;
      while (arr[i][++j] != NULL)
	{
	  free(arr[i][j]);
	}
      free(arr[i]);
    }
  free(arr);
}

char	*my_strdup(char	*str)
{
  char	*ret;
  int	len;

  len = my_strlen(str);
  if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_memset(ret, 0, len + 1);
  my_strncpy(ret, str, len);
  return (ret);
}
