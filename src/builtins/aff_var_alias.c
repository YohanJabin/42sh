/*
** aff_var_alias.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/builtins/var
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Mon May  8 16:33:09 2017 Yohan.Jabin
** Last update Mon May  8 16:40:06 2017 Yohan.Jabin
*/

#include "my.h"

void	aff_var_alias(char **arr)
{
  int	i;
  int	first_equal;

  i = -1;
  while (arr[++i] != NULL)
    {
      if ((first_equal = get_first_equal(arr[i])) == -1)
	my_printf("%s\n", arr[i]);
      else
	{
	  write(1, arr[i], first_equal);
	  my_printf("\t%s\n", &arr[i][first_equal + 1]);
	}
    }
}
