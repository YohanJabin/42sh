/*
** func2.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 20 16:15:00 2017 Yohan.Jabin
** Last update Fri Apr 28 00:20:44 2017 Yohan.Jabin
*/

#include "my.h"

void	my_strncpy(char *s1, char *s2, int n)
{
  int	i;

  i = -1;
  while (++i < n)
    s1[i] = s2[i];
}

void	my_memset(char *str, char c, int len)
{
  int	i;

  i = -1;
  while (++i < len)
    str[i] = c;
}

char	*my_pathadd(char *dir, char *file)
{
  char	*ret;
  int	i;
  int	j;

  i = my_strlen(dir) + my_strlen(file) + 2;
  ret = malloc(sizeof(char) * i);
  my_memset(ret, 0, i);
  i = -1;
  while (dir[++i] != 0)
    ret[i] = dir[i];
  if (ret[i - 1] != '/')
    ret[i++] = '/';
  j = -1;
  while (file[++j] != 0)
    ret[i + j] = file[j];
  return (ret);
}

void	free_double_tab(char **arr)
{
  int	i;

  i = -1;
  while (arr[++i] != NULL)
    {
      if (arr[i] != NULL)
	{
	  free(arr[i]);
	  arr[i] = NULL;
	}
    }
  if (arr != NULL)
    {
      free(arr);
      arr = NULL;
    }
}

void	aff_double_tab(char **arr)
{
  int	i;

  if (arr == NULL)
    return;
  i = -1;
  while (arr[++i] != NULL)
    my_printf("%s\n", arr[i]);
}
