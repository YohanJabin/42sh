/*
** process_imp.c for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Wed May 17 15:11:35 2017 Hugo
** Last update Fri May 19 23:04:36 2017 Yohan.Jabin
*/

#include "my.h"

int	init_imput_loop(t_my_var *data)
{
  init_arr_pid(data);
  data->redir.input = 0;
  if (data->redir.flag_redir_left == 1)
    {
      if ((open_redirections_left(data, data->redir.word_left)) == 84)
	return (84);
    }
  else if (data->redir.flag_redir_left == 2)
    double_redir_left(data, data->redir.word_left);
  return (0);
}

int	reset_imput_loop(t_my_var *data, char **imp)
{
  if (data->redir.input != 0)
    {
      if (dup2(data->redir.input, 0) == -1)
	return (84);
      close(data->redir.input);
    }
  if (data->redir.flag_redir_right != 0)
    if ((open_redirections_right(data, data->redir.word_right)) == 84)
      return (84);
  if (dup2(data->redir.output, 1) == -1)
    return (84);
  close(data->redir.output);
  test_cmd_builtin(data, imp);
  wait_all_pid(data);
  return (0);
}

int	process_imput_loop(t_my_var *data, char **imp)
{
  if (pipe(data->redir.fd_pipe) == -1)
    return (84);
  data->redir.output = data->redir.fd_pipe[1];
  if (data->redir.input != 0)
    {
      if (dup2(data->redir.input, 0) == -1)
	return (84);
      close(data->redir.input);
    }
  if (data->redir.output != 1)
    {
      if (dup2(data->redir.output, 1) == -1)
	return (84);
      close(data->redir.output);
    }
  test_cmd_builtin(data, imp);
  close(data->redir.fd_pipe[1]);
  data->redir.input = data->redir.fd_pipe[0];
  return (0);
}

int	process_imput(t_my_var *data, char ***imp)
{
  int	fd_save[2];
  int	i;

  if ((fd_save[0] = dup(0)) == -1)
    return (1);
  if ((fd_save[1] = dup(1)) == -1)
    return (1);
  if (init_imput_loop(data) == 84)
    return (1);
  i = -1;
  while (++i < data->redir.hm_pipe - 1)
    if (process_imput_loop(data, imp[i]) == 84)
      return (1);
  data->redir.output = fd_save[1];
  if (reset_imput_loop(data, imp[i]) == 84)
    return (1);
  if (dup2(fd_save[0], 0) == -1)
    return (1);
  close(fd_save[0]);
  if (dup2(fd_save[1], 1) == -1)
    return (1);
  close(fd_save[1]);
  return (1);
}
