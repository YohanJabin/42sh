/*
** globbing_error.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/formatting/globbing
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Tue May 16 16:11:09 2017 Yohan.Jabin
** Last update Tue May 16 18:17:36 2017 Yohan.Jabin
*/

#include "my.h"

int	globbing_no_match(t_my_var *data, char **arr_file, char *imp)
{
  int	match;
  int	i;
  char	**arr;

  match = 0;
  i = -1;
  while (arr_file[++i] != NULL)
    if (arr_file[i][0] != 0)
      match++;
  if (match == 0)
    {
      arr = my_str_to_wordtab(imp);
      my_fprintf(2, "%s: No match.\n", arr[0]);
      free_double_tab(arr);
      data->return_value = 1;
      return (84);
    }
  return (0);
}
