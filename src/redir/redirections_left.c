/*
** redirections.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 19:49:10 2017 Yohan.Jabin
** Last update Fri Apr 28 00:17:57 2017 Yohan.Jabin
*/

#include "my.h"

void	cp_redirections_left(t_my_var *data)
{
  char	*str;
  int	fd[2];

  pipe(fd);
  while ((str = get_next_line(data->redir.input)) != NULL)
    {
      my_fprintf(fd[1], "%s\n", str);
      free(str);
    }
  close(data->redir.input);
  close(fd[1]);
  data->redir.input = fd[0];
}

int     open_redirections_left(t_my_var *data, char *str)
{
  if (access(str, F_OK) == -1 && errno)
    my_fprintf(2, "%s: %s.\n", str, strerror(errno));
  if ((data->redir.input =
       open(str, O_RDWR)) == -1)
    return (84);
  //cp_redirections_left(data);
  return (0);
}

int	parse_redirections_left(t_my_var *data, char ***imp, int i)
{
  if (i == 0 && (imp[0][1] == NULL || imp[0][2] == NULL))
    {
      if (imp[0][1] == NULL)
	my_fprintf(2, "Missing name for redirect.\n");
      else if (imp[0][2] == NULL)
	my_fprintf(2, "Invalid null command.\n");
      data->return_value = 1;
      return (84);
    }
  else if (imp[0][i + 1] == NULL)
    {
      my_fprintf(2, "Missing name for redirect.\n");
      data->return_value = 1;
      return (84);
    }
  data->redir.word_left = my_strdup(imp[0][i + 1]);
  imp[0] = new_redirect_tab(imp[0], '<');
  return (0);
}

void	check_for_redirections_left2(t_my_var *data, char ***imp,
				     int i, int j)
{
  if (imp[0][i][j + 1] == '<')
    {
      data->redir.flag_redir_left = 2;
      if (imp[0][i + 1] != NULL)
	data->redir.word_left = my_strdup(imp[0][i + 1]);
    }
  else
    data->redir.flag_redir_left = 1;
}

int	check_for_redirections_left(t_my_var *data, char ***imp)
{
  int	i;
  int	j;

  data->redir.flag_redir_left = 0;
  data->redir.input = 0;
  data->redir.word_left = NULL;
  i = -1;
  while (imp[0][++i] != NULL)
    {
      j = -1;
      while (imp[0][i][++j] != 0)
	{
	  if (imp[0][i][j] == '<')
	    {
	      check_for_redirections_left2(data, imp, i, j);
	      if (parse_redirections_left(data, imp, i) == 84)
		return (84);
	      return (0);
	    }
	}
    }
  return (0);
}
