/*
** my_strcat.c for 42sh in /home/tokou/Documents/PSU_2016_minishell2/key
** 
** Made by Léron
** Login   <trolol>
** 
** Started on  Tue Apr 25 13:45:09 2017 Léron
** Last update Tue Apr 25 14:12:21 2017 Léron
*/

#include "my.h"

char	*my_strcat(char *str, char *str2)
{
  int	i;
  char	*str3;
  int	j;

  i = -1;
  j = -1;
  my_malloc(&str3, '\0', (my_strlen(str) + my_strlen(str2) + 1));
  while (str[++i] != '\0')
      str3[i] = str[i];
  while (str2[++j] != '\0')
      str3[i++] = str2[j];
  str3[i] = '\0';
  return (str3);
}
