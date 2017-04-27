/*
** new_redirect_tab.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr  6 12:56:25 2017 Yohan.Jabin
** Last update Thu Apr 27 23:35:24 2017 Yohan.Jabin
*/

#include "my.h"

int	new_redirect_tab_len(char **arr, char c)
{
  int	ret;
  int	i;

  ret = 0;
  i = -1;
  while (arr[++i] != NULL)
    {
      if (arr[i][0] == c)
	i += 2;
      if (arr[i] == NULL)
	return (ret);
      ret++;
    }
  return (ret);
}

void	parse_new_redirect_tab(char **ret, char **arr, char c)
{
  int	i;
  int	j;
  int	len;

  i = -1;
  j = 0;
  while (arr[++i] != NULL)
    {
      if (arr[i][0] == c)
	i += 2;
      if (arr[i] == NULL)
	return;
      len = my_strlen(arr[i]);
      ret[j] = malloc(sizeof(char) * (len + 1));
      my_memset(ret[j], 0, len + 1);
      my_strncpy(ret[j], arr[i], len);
      j++;
    }
}

char	**new_redirect_tab(char **arr, char c)
{
  char	**ret;
  int	len;

  len = new_redirect_tab_len(arr, c);
  if ((ret = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  ret[len] = NULL;
  parse_new_redirect_tab(ret, arr, c);
  return (ret);
}
