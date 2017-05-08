/*
** process_imp.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 18:16:20 2017 Yohan.Jabin
** Last update Mon May  8 19:35:53 2017 Yohan.Jabin
*/

#include "my.h"

void	init_imput_loop(t_my_var *data)
{
  init_arr_pid(data);
  data->redir.input = 0;
  if (data->redir.flag_redir_left == 1)
    open_redirections_left(data, data->redir.word_left);
  else if (data->redir.flag_redir_left == 2)
    double_redir_left(data, data->redir.word_left);
}

void	reset_imput_loop(t_my_var *data, char **imp)
{
  if (data->redir.input != 0)
    {
      dup2(data->redir.input, 0);
      close(data->redir.input);
    }
  if (data->redir.flag_redir_right != 0)
    open_redirections_right(data, data->redir.word_right);
  dup2(data->redir.output, 1);
  close(data->redir.output);
  test_cmd_builtin(data, imp);
  wait_all_pid(data);
}

void	process_imput_loop(t_my_var *data, char **imp)
{
  if (pipe(data->redir.fd_pipe) == -1)
    my_fprintf(2, "erorr:%s\n", strerror(errno));
  data->redir.output = data->redir.fd_pipe[1];
  if (data->redir.input != 0)
    {
      dup2(data->redir.input, 0);
      close(data->redir.input);
    }
  if (data->redir.output != 1)
    {
      dup2(data->redir.output, 1);
      close(data->redir.output);
    }
  test_cmd_builtin(data, imp);
  close(data->redir.fd_pipe[1]);
  data->redir.input = data->redir.fd_pipe[0];
}

int	process_imput(t_my_var *data, char ***imp)
{
  int	fd_save[2];
  int	i;

  if ((fd_save[0] = dup(0)) == -1)
    {
      my_fprintf(2, "erorr:%s\n", strerror(errno));
      return (1);
    }
  if ((fd_save[1] = dup(1)) == -1)
    {
      my_fprintf(2, "erorr:%s\n", strerror(errno));
      return (1);
    }
  init_imput_loop(data);
  i = -1;
  while (++i < data->redir.hm_pipe - 1)
    process_imput_loop(data, imp[i]);
  data->redir.output = fd_save[1];
  reset_imput_loop(data, imp[i]);
  dup2(fd_save[0], 0);
  close(fd_save[0]);
  dup2(fd_save[1], 1);
  close(fd_save[1]);
  return (1);
}
