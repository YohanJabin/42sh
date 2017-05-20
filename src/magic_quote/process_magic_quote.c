/*
** process_magic_quote.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/magic_quote
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Fri May 19 22:35:00 2017 Yohan.Jabin
** Last update Sat May 20 02:05:52 2017 Yohan.Jabin
*/

#include "my.h"

char	*get_output_magic_quote(int fd)
{
  char	*ret;
  char	*str;
  int	len;

  if ((ret = malloc(sizeof(char))) == NULL)
    return (NULL);
  ret[0] = 0;
  len = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      ret = my_stradd(ret, str, len);
      len += my_strlen(str);
      ret = my_stradd(ret, "\n", len);
      len++;
    }
  ret = my_strcut(ret, --len, 1);
  return (ret);
}

char	*process_magic_quote(t_my_var *data, char *cmd)
{
  int	pipe_fd[2];
  int	pid;
  char	*ret;

  if (pipe(pipe_fd) == -1)
    return (NULL);
  if ((pid = fork()) == -1)
    return (NULL);
  if (pid == 0)
    {
      close(pipe_fd[0]);
      if (dup2(pipe_fd[1], 1) == -1)
	return (NULL);
      close(pipe_fd[1]);
      parse_pipe(data, cmd);
      exit(0);
    }
  else
    {
      close(pipe_fd[1]);
      if ((ret = get_output_magic_quote(pipe_fd[0])) == NULL)
	return (NULL);
    }
  return (ret);
}
