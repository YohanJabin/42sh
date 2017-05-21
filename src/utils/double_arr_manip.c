/*
** double_arr_manip.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/utils
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sun May 21 12:55:33 2017 Yohan.Jabin
** Last update Sun May 21 12:56:42 2017 Yohan.Jabin
*/

#include "my.h"

void    aff_double_tab(char **arr)
{
  int   i;

  if (arr == NULL)
    return ;
  i = -1;
  while (arr[++i] != NULL)
    my_printf("%s\n", arr[i]);
}

void    free_double_tab(char **arr)
{
  int   i;

  i = -1;
  while (arr[++i] != NULL)
    {
      if (arr[i] != NULL)
	{
	  free(arr[i]);
	  arr[i] = NULL;
	}
    }
  if (arr != NULL)
    {
      free(arr);
      arr = NULL;
    }
}

int     hm_line_on_tab(char **arr)
{
  int   i;

  i = -1;
  while (arr[++i] != NULL);
  return (i);
}

void    free_triple_tab(char ***arr)
{
  int   i;
  int   j;

  i = -1;
  while (arr[++i] != NULL)
    {
      j = -1;
      while (arr[i][++j] != NULL)
	{
	  free(arr[i][j]);
	}
      free(arr[i]);
    }
  free(arr);
}
