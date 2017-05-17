/*
** str_to_word_tab.c for  in /PSU_2016_minishell1/lib/my/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Tue Feb 21 15:21:24 2017 Camille Gouneau
** Last update Wed May  3 11:04:54 2017 Camille Gouneau
*/

#include  <stdlib.h>
#include  <stdio.h>
#include  "auto_complet.h"

int   count_separator(char *str, char separator)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == separator)
        {
          j++;
        }
      i++;
    }
  return (j);
}

char  **put_in_charstar(char **word_tab, char *str, char separator)
{
  int count;
  int j;
  int i;

  count = 0;
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == separator)
        {
          j = 0;
          count++;
        }
      else
        {
          word_tab[count][j] = str[i];
          j++;
        }
      i++;
    }
  return (word_tab);
}

int   count_malloc(char *str, char sep)
{
  static int i = 0;
  int j;

  if (str == NULL)
    {
      i = 0;
      return (0);
    }
  j = 0;
  while (str[i] != sep && str[i])
    {
      i++;
      j++;
    }
  i++;
  return (j);
}

char  **str_to_word_tab(char *str, char separator)
{
  int i;
  int size_malloc;
  int count_sep;
  char  **word_tab;

  count_sep = count_separator(str, separator) + 1;
  word_tab = my_malloc((sizeof(char *) * (count_sep + 1)));
  word_tab[count_sep] = NULL;
  i = 0;
  while (i < count_sep)
    {
      size_malloc = count_malloc(str, separator);
      word_tab[i] = my_malloc(sizeof(char) * (size_malloc + 1));
      word_tab[i][size_malloc] = '\0';
      i++;
    }
    count_malloc(NULL, 0);
  word_tab = put_in_charstar(word_tab, str, separator);
  return (word_tab);
}
