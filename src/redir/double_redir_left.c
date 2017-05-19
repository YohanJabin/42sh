/*
** double_redir_left.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr  6 15:03:31 2017 Yohan.Jabin
** Last update Fri May 19 09:54:02 2017 Yohan.Jabin
*/

#include "my.h"

void	double_redir_left(t_my_var *data, char *word)
{
  char	*str;
  int	fd[2];

  if (pipe(fd) == -1)
    return ;
  my_printf("? ");
  while ((str = get_next_line(0)) != NULL)
    {
      if (my_strncmp(str, word, my_strlen(word) + 1) == 1)
	{
	  close(fd[1]);
	  data->redir.input = fd[0];
	  return ;
	}
      my_fprintf(fd[1], "%s\n", str);
      my_printf("? ");
      free(str);
    }
}
