/*
** echo.c for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 12:49:39 2017 Adrien ZEMMA
** Last update	Wed Apr 12 13:30:07 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_echo(char *str, char **env)
{
  int nb;
  char **tab;

  nb = -1;
  tab = str_to_tab(str, ' ');
  my_printf("%s", str);
  if (tab[1][0] == '$')
    my_printf("%s", (tab[0]));
}
