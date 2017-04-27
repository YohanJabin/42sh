/*
** redirections.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 19:49:10 2017 Yohan.Jabin
** Last update Fri Apr 28 00:18:10 2017 Yohan.Jabin
*/

#include "my.h"

int	open_redirections_right(t_my_data *data, char *str)
{
  if (data->redir.flag_redir_right == 1)
    {
      if ((data->redir.output =
	   open(str, O_CREAT | O_WRONLY | O_TRUNC, 0664)) == -1)
	return (84);
    }
  else if (data->redir.flag_redir_right == 2)
    {
      if ((data->redir.output =
	   open(str, O_CREAT | O_WRONLY | O_APPEND, 0664)) == -1)
	return (84);
    }
  return (0);
}

int	parse_redirections_right(t_my_data *data, char ***imp, int i)
{
  if ((i == 0 && imp[data->redir.hm_pipe - 1][i] == NULL)
      || imp[data->redir.hm_pipe - 1][i + 1] == NULL)
    {
      my_fprintf(2, "Missing name for redirect.\n");
      return (84);
    }
  if (i == 0 && imp[data->redir.hm_pipe - 1][i + 2] == NULL)
    {
      my_fprintf(2, "Invalid null command.\n");
      return (84);
    }
  data->redir.word_right =
    my_strdup(imp[data->redir.hm_pipe - 1][i + 1]);
  imp[data->redir.hm_pipe - 1] =
    new_redirect_tab(imp[data->redir.hm_pipe - 1], '>');
  return (0);
}

int	check_for_redirections_right(t_my_data *data, char ***imp)
{
  int	i;
  int	j;

  data->redir.flag_redir_right = 0;
  data->redir.output = 1;
  data->redir.word_right = NULL;
  i = -1;
  while (imp[data->redir.hm_pipe - 1][++i] != NULL)
    {
      j = -1;
      while (imp[data->redir.hm_pipe - 1][i][++j] != 0)
	{
	  if (imp[data->redir.hm_pipe - 1][i][j] == '>')
	    {
	      if (imp[data->redir.hm_pipe - 1][i][j + 1] == '>')
		data->redir.flag_redir_right = 2;
	      else
		data->redir.flag_redir_right = 1;
	      if (parse_redirections_right(data, imp, i) == 84)
		return (84);
	      return (0);
	    }
	}
    }
  return (0);
}
