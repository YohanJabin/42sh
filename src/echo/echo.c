/*
** echo.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:49:39 2017 Adrien ZEMMA
** Last update	Wed Apr 12 17:27:19 2017 Adrien ZEMMA
*/

#include "my.h"

char *my_one_less(char *str)
{
  int	i;
  char *stock;

  i = 0;
  my_malloc(&stock, '\0', my_strlen(str));
  while (str[++i] != '\0')
    stock[i-1] = str;
  return (stock);
}

void	my_echo(char *str, char **env)
{
  int nb;
  char *stock;
  char **tab;

  nb = -1;
  tab = str_to_tab(str, ' ');
  my_printf("%s", str);
  if (tab[1][0] == '$')
  {
    stock = my_one_less(tab[1]);
    while (env[++nb] != NULL)
    {
      if (my_strncmp(stock, env[nb], my_strlen(stock) == 1))
        my_printf("%s", env[nb]);
    }
  }
}
