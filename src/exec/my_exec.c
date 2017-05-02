/*
** my_exec.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Mon Apr  3 15:01:10 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:32 2017 Adrien ZEMMA
*/

#include "my.h"

void	check_child_status2(int status, int sig, t_my_var *data)
{
  if (sig == SIGFPE)
    {
      if (WCOREDUMP(status) == 0)
	my_fprintf(2, "Floating exception\n");
      else
	my_fprintf(2, "Floating exception (core dumped)\n");
      data->return_value = 136;
    }
}

void    check_child_status(int status, t_my_var *data)
{
  int   sig;

  if (WIFEXITED(status) != 1)
    {
      if (WIFSIGNALED(status) == 1)
	{
	  sig = WTERMSIG(status);
	  if (sig == SIGSEGV)
	    {
	      if (WCOREDUMP(status) == 0)
		my_fprintf(2, "Segmentation fault\n");
	      else
		my_fprintf(2, "Segmentation fault (core dumped)\n");
	      data->return_value = 139;
	    }
	  check_child_status2(status, sig, data);
	}
    }
}

void    my_exec(char *path, char **imp, t_my_var *data)
{
  pid_t pid;

  if ((pid = fork()) != -1)
    {
      if (pid == 0)
	{
	  if (execve(path, imp, data->env) == -1 && errno)
	    data->return_value = 1;
	  exit(data->return_value);
	}
      else
	{
	  data->redir.arr_pid = add_pid(data->redir.arr_pid,
					data->redir.hm_pid, pid);
	  data->redir.hm_pid++;
	}
    }
}
