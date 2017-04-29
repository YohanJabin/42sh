/*
1;4205;0c** my_str_to_wordtab.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Fri Apr  7 19:29:26 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:38 2017 Adrien ZEMMA
*/

#include "my.h"

int	hm_word(char *str)
{
  int	i;
  int	return_value;

  return_value = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      else
	{
	  while (str[i] != 0 && (str[i] != ' ' && str[i] != '\t'))
	    i++;
	  return_value++;
	}
    }
  return (return_value);
}

int	size_word(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] == ' ' || str[i] == '\t')
      return (i);
  return (i);
}

void	parse_tab(char **tab, char *str, int hm)
{
  int	i;
  int	j;
  int	size;

  i = 0;
  j = 0;
  while (i < hm)
    {
      while (str[j] == ' ' || str[j] == '\t')
	j++;
      size = size_word(&str[j]);
      tab[i] = malloc(sizeof(char) * (size + 1));
      my_strncpy(tab[i], &str[j], size);
      j += size;
      tab[i][size] = 0;
      i++;
    }
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	hm;

  hm = hm_word(str);
  tab = malloc(sizeof(char*) * (hm + 1));
  tab[hm] = 0;
  parse_tab(tab, str, hm);
  return (tab);
}
