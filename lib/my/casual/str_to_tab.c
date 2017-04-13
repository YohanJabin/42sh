/*
** str_to_tab.c for PSU_2016_minishell2
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Tue Mar 14 13:05:42 2017 Adrien ZEMMA
** Last update	Wed Apr 12 19:50:43 2017 Hugo MARTIN
*/

#include "my.h"

void	my_prepa(int **nb)
{
  *nb = malloc(sizeof(int) * 4);
  *nb[0] = 0;
  *nb[1] = 0;
  *nb[2] = 0;
}

int	comptechar_tab(char *str, char fin)
{
  int	i;
  int	b;
  int	c;

  i = 0;
  b = 0;
  c = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
  {
    if (str[i] == fin || str == '\0')
    {
      if (c < b)
        c = b;
      b = 0;
    }
    b = b + 1;
    i = i + 1;
  }
  c = c + 1;
  return (c);
}

int	compteligne_tab(char *str, char fin)
{
  int	i;
  int	b;

  i = 0;
  b = 0;
  if (str == NULL)
    return (0);
  while (str[i] && str[i + 1] != '\0')
  {
    if (str[i] == fin || str[i] == '\0')
      b = b + 1;
    i = i + 1;
  }
  b = b + 1;
  return (b);
}

char	**str_to_tab(char *str, char fin)
{
  char **tab;
  int	*nb;

  my_prepa(&nb);
  if (str == NULL)
  return (NULL);
  tab = malloc(sizeof(char *) * (compteligne_tab(str, fin) + 6));
  my_malloc(&tab[nb[1]], '\0', comptechar_tab(str, fin) + 2);
  while (str[nb[0]] != '\0')
  {
    tab[nb[1]][nb[2]] = str[nb[0]];
    nb[0] = nb[0] + 1;
    nb[2] = nb[2] + 1;
    if (str[nb[0]] == fin || str[nb[0]] == '\0')
    {
      tab[nb[1]][nb[2]] = '\0';
      nb[1] = nb[1] + 1;
      nb[0] = nb[0] + 1;
      nb[2] = 0;
      my_malloc(&tab[nb[1]], '\0', comptechar_tab(str, fin) + 2);
    }
  }
  tab[nb[1]] = NULL;
  tab[nb[1] + 1] = NULL;
  return (tab);
}
