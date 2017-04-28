/*
** manip_chaine.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 18:26:45 2017 Adrien ZEMMA
** Last update	Fri Apr 28 11:12:36 2017 Adrien ZEMMA
*/

#include "my.h"

char *last_buff(char *buff)
{
  int a;
  int i;
  char *ret;

  a = -1;
  i = my_strlen(buff);
  my_malloc(&ret, '\0', i);
  while (buff[--i] != '/');
  if (buff[i + 1] == '\0')
    return ("/");
  while (buff[++i] != '\0')
    ret[++a] = buff[i];
  return (ret);
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
