/*
** my_get_commande.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 17:56:13 2017 Adrien ZEMMA
** Last update	Thu Apr 20 19:36:24 2017 Adrien ZEMMA
*/

#include "my.h"

int my_get_commande(t_my_data *data)
{
  char *str;

  str = get_next_line(0);
  my_histori(str, data);
  return (0);
  free(str);
}
