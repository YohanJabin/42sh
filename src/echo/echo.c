/*
** echo.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:49:39 2017 Adrien ZEMMA
** Last update	Wed Apr 12 17:43:30 2017 Adrien ZEMMA
*/

#include "my.h"

char *my_one_less(char *str)
{
  int	i;
  int a;
  char *stock;

  i = 0;
  a = -1;
  my_malloc(&stock, '\0', my_strlen(str));
  while (str[++i] != '\0')
    stock[++a] = str[i];
  return (stock);
}

void	my_echo(char *str, char **env)
{
  int nb;
  char *stock;
  char **tab;

  nb = -1;
  tab = str_to_tab(str, ' ');
  if (tab[1][0] == '$')
  {
    stock = my_one_less(tab[1]);
    my_printf("%s\n", stock);
    while (env[++nb] != NULL)
    {
      if (my_strncmp(stock, env[nb], my_strlen(stock)) == 1)
        my_printf("%s\n", env[nb]);
    }
  }
}
