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
  int	return_value;
  int	i;

  return_value = 0;
  i = -1;
  while (arr[++i] != NULL)
    {
      if (arr[i][0] == c)
	i += 2;
      if (arr[i] == NULL)
	return (return_value);
      return_value++;
    }
  return (return_value);
}

void	parse_new_redirect_tab(char **return_value, char **arr, char c)
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
      return_value[j] = malloc(sizeof(char) * (len + 1));
      my_memset(return_value[j], 0, len + 1);
      my_strncpy(return_value[j], arr[i], len);
      j++;
    }
}

char	**new_redirect_tab(char **arr, char c)
{
  char	**return_value;
  int	len;

  len = new_redirect_tab_len(arr, c);
  if ((return_value = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  return_value[len] = NULL;
  parse_new_redirect_tab(return_value, arr, c);
  return (return_value);
}
