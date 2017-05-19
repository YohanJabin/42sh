/*
** process_if.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May 18 21:11:46 2017 Yohan.Jabin
** Last update Fri May 19 15:48:42 2017 Yohan.Jabin
*/

#include "my.h"

int	check_if_status(t_my_var *data, char **arr)
{
  if (my_strncmp(arr[0], "else", 5) == 1)
    {
      if (arr[1] != NULL && my_strncmp(arr[1], "if", 3) == 1)
	{
	  parse_if(data, &arr[1], 2);
	  if (data->script.if_status != -1)
	    return (1);
	}
      return (0);
    }
  return (1);
}

void    start_if(t_my_var *data, char *flag)
{
  char  *str;
  char  **arr;

  if (isatty(0) && data->flag_prompt == 1)
    my_printf("%s? ", flag);
  while ((str = get_next_line(0)) != NULL)
    {
      if (str[0] != 0)
	{
	  arr = my_str_to_wordtab(str);
	  if (my_strncmp(arr[0], "endif", 6) == 1)
	    return ;
	  if (my_strncmp(flag, "else", 5) == 0
	      && check_if_status(data, arr) == 0)
	    return ;
	}
      if (isatty(0) && data->flag_prompt == 1)
	my_printf("%s? ", flag);
    }
  if (my_strncmp(flag, "if", 3))
    my_fprintf(2, "then: then/endif not found.\n");
  else
    my_fprintf(2, "%s: then/endif not found.\n", flag);
  data->return_value = 1;
}
