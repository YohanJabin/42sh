/*
** process_magic_quote.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/magic_quote
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Fri May 19 22:35:00 2017 Yohan.Jabin
** Last update Sun May 21 15:03:00 2017 Yohan.Jabin
*/

#include "my.h"

void	replace_return_magic_quote(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] == '\n')
      str[i] = ' ';
}

char	*get_output_magic_quote(int fd)
{
  char	*ret;
  char	buff[1024];
  int	len;
  int	i;

  if ((ret = malloc(sizeof(char))) == NULL)
    return (NULL);
  ret[0] = 0;
  my_memset(buff, 0, 1024);
  i = 0;
  while ((len = read(fd, buff, 1023)) > 0)
    {
      ret = my_stradd(ret, buff, i);
      i += len;
      my_memset(buff, 0, 1024);
    }
  replace_return_magic_quote(ret);
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
