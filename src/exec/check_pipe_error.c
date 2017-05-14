/*
** check_pipe_error.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr  6 19:32:07 2017 Yohan.Jabin
** Last update Mon May  8 16:16:03 2017 Yohan.Jabin
*/

#include "my.h"

int	check_redirection_error(t_my_var *data, char ***imp)
{
  int	i;
  int	j;

  i = -1;
  while (imp[++i] != NULL)
    {
      j = -1;
      while (imp[i][++j] != NULL)
	{
	  if (imp[i][j][0] == '>' && i != data->redir.hm_pipe - 1)
	    {
	      my_fprintf(2, "Ambiguous output redirect.\n");
	      data->return_value = 1;
	      return (84);
	    }
	  if (imp[i][j][0] == '<' && i != 0)
	    {
	      my_fprintf(2, "Ambiguous input redirect.\n");
	      data->return_value = 1;
	      return (84);
	    }
	}
    }
  return (0);
}
