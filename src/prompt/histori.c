/*
** histori.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 19:03:24 2017 Adrien ZEMMA
** Last update	Fri Apr 28 15:30:57 2017 Adrien ZEMMA
*/

#include "my.h"

int	my_histori(char *str, t_my_prompt *prompt)
{
  int i;

  i = -1;
  prompt->histori_tab = realloc(prompt->histori_tab,
    sizeof(char *) * (prompt->histori_nb + 4));
  my_malloc(&prompt->histori_tab[prompt->histori_nb], '\0', my_strlen(str) + 1);
  while (str[++i] != '\0')
    prompt->histori_tab[prompt->histori_nb][i] = str[i];
  prompt->histori_nb++;
  return (0);
}
