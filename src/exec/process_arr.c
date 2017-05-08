/*
** process_arr.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr  6 19:50:00 2017 Yohan.Jabin
** Last update Mon May  8 14:47:30 2017 Yohan.Jabin
*/

#include "my.h"

int	check_cmd_error(t_my_var *data, char ***arr_imp)
{
  if (check_redirection_error(data, arr_imp) == 84)
    {
      data->return_value = 1;
      return (1);
    }
  if (check_for_redirections_right(data, arr_imp) == 84
      || check_for_redirections_left(data, arr_imp) == 84)
    {
      data->return_value = 1;
      return (1);
    }
  return (2);
}

int     create_arr_imp(t_my_var *data, char **arr_pipe)
{
  char  ***arr_imp;
  int   return_value;
  int   i;

  arr_imp = malloc(sizeof(char **) * (data->redir.hm_pipe + 1));
  arr_imp[data->redir.hm_pipe] = NULL;
  i = -1;
  while (++i < data->redir.hm_pipe)
    arr_imp[i] = my_str_to_wordtab(arr_pipe[i]);
  if ((return_value = check_cmd_error(data, arr_imp)) == 0
      || return_value == 1)
    return (return_value);
  if ((return_value = process_imput(data, arr_imp)) == 0)
    {
      free_triple_tab(arr_imp);
      return (return_value);
    }
  free_triple_tab(arr_imp);
  return (1);
}

int     parse_pipe(t_my_var *data, char *imp)
{
  char  **arr_pipe;
  int   return_value;

  if (format_imput(data, &imp) != 0)
    return (1);
  if ((arr_pipe = create_arr_pipe(imp)) == NULL)
    my_fprintf(2, "Invalid null command.\n");
  else
    {
      data->redir.hm_pipe = hm_line_on_tab(arr_pipe);
      if ((return_value = create_arr_imp(data, arr_pipe)) == 0
	  || return_value == 84)
	{
	  free_double_tab(arr_pipe);
	  return (return_value);
	}
      free_double_tab(arr_pipe);
    }
  return (1);
}
