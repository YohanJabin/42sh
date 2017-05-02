/*
** process_pid.c for 42sh in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Fri Apr 21 12:05:23 2017 Yohan.Jabin
** Last update Mon May  1 15:46:15 2017 Yohan.Jabin
*/

#include "my.h"

void	init_arr_pid(t_my_var *data)
{
  data->redir.arr_pid = NULL;
  data->redir.hm_pid = 0;
}

int	*add_pid(int *arr_pid, int size, int to_add)
{
  arr_pid = realloc(arr_pid, sizeof(int) * (size + 1));
  arr_pid[size] = to_add;
  return (arr_pid);
}

void	wait_all_pid(t_my_var *data)
{
  int	status;
  int	i;

  i = -1;
  while (++i < data->redir.hm_pid)
    {
      waitpid(data->redir.arr_pid[i], &status, 0);
      if (WEXITSTATUS(status) != 0)
	data->return_value = WEXITSTATUS(status);
      check_child_status(status, data);
    }
}
