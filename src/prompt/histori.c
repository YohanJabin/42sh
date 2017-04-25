/*
** histori.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 19:03:24 2017 Adrien ZEMMA
** Last update	Tue Apr 25 15:48:03 2017 Adrien ZEMMA
*/

#include "my.h"

int	my_histori(char *str, t_my_data *data)
{
  int i;

  i = -1;
  data->histori_tab = realloc(data->histori_tab,
    sizeof(char *) * (data->histori_nb + 4));
  my_malloc(&data->histori_tab[data->histori_nb], '\0', my_strlen(str) + 1);
  while (str[++i] != '\0')
    data->histori_tab[data->histori_nb][i] = str[i];
  data->histori_nb++;
  return (0);
}
