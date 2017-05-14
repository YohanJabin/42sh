/*
** arr_pipe.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 17:29:53 2017 Yohan.Jabin
** Last update Thu Apr 27 23:35:13 2017 Yohan.Jabin
*/

#include "my.h"

int	is_it_only_space_pipe(char *cmd)
{
  int	i;

  i = -1;
  while (cmd[++i] != 0 && cmd[i] != '|')
    if (cmd[i] != ' ')
      return (0);
  return (1);
}

int	my_strlen_pipe(char *cmd)
{
  int	i;

  i = -1;
  while (cmd[++i] != 0 && cmd[i] != '|');
  return (i);
}

int	hm_pipe(char *cmd)
{
  int	i;
  int	hm;
  int	len;

  hm = 0;
  i = -1;
  while (++i < my_strlen(cmd))
    {
      if (is_it_only_space_pipe(&cmd[i]) == 1)
	return (-1);
      len = my_strlen_pipe(&cmd[i]);
      hm++;
      i += len;
    }
  return (hm);
}

void	parse_arr_pipe(char **arr_pipe, char *cmd)
{
  int	i;
  int	j;
  int	len;

  j = 0;
  i = -1;
  while (++i < my_strlen(cmd))
    {
      while (cmd[i] == ' ' || cmd[i] == '\t')
	i++;
      if (cmd[i] == 0)
	return;
      if (cmd[i] != '|')
	{
	  len = my_strlen_pipe(&cmd[i]);
	  arr_pipe[j] = malloc(sizeof(char) * (len + 1));
	  my_memset(arr_pipe[j], 0, len + 1);
	  my_strncpy(arr_pipe[j], &cmd[i], len);
	  j++;
	  i += len;
	}
    }
}

char	**create_arr_pipe(char *cmd)
{
  char	**arr_pipe;
  int	len;

  if ((len = hm_pipe(cmd)) == -1 || cmd[my_strlen(cmd) - 1] == '|')
    return (NULL);
  arr_pipe = malloc(sizeof(char*) * (len + 1));
  arr_pipe[len] = NULL;
  parse_arr_pipe(arr_pipe, cmd);
  return (arr_pipe);
}
