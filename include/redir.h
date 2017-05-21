/*
** redir.h for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/include
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Thu Apr 27 18:36:54 2017 Yohan.Jabin
** Last update	Sun May 21 18:31:57 2017 Adrien ZEMMA
*/

#ifndef REDIR_H_
# define REDIR_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct  s_redir
{
  int           hm_pid;
  int           *arr_pid;
  int           hm_pipe;
  int           fd_pipe[2];
  int           input;
  int           output;
  int           flag_redir_right;
  char          *word_right;
  int           flag_redir_left;
  char          *word_left;
}               t_redir;

#endif /* !REDIR_H_ */
