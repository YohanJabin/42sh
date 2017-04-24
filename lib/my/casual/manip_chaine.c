/*
** manip_chaine.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 18:26:45 2017 Adrien ZEMMA
** Last update	Sun Apr 23 13:33:28 2017 Adrien ZEMMA
*/

#include "my.h"

char *last_buff(char *buff)
{
  int i;
  char **tab;

  i = -1;
  tab = str_to_tab(buff, '/');
  while (tab[++i] != NULL);
  return (tab[i - 1]);
}

char *retir_char(char *str, int nb)
{
  int i;
  char *stock;

  i = -1;
  if (nb > my_strlen(str))
    return (NULL);
  my_malloc(&stock, '\0', my_strlen(str) + 3);
  while (str[++nb] != '\0')
    stock[++i] = str[nb];
  return (stock);
}
