#ifndef MY_H
# define MY_H

#include "my_printf.h"
#include "my_fprintf.h"
#include "get_next_line.h"
#include "list.h"

typedef	struct s_my_var
{
  char	**env;
  char	*full_command;
  char	*command;
  int	return_value;
  t_my_list_cont	*list_command;
}	t_my_var;

typedef struct	s_my_args
{
  int	i;
  int	j;
  int	k;
  int	n;
  char	*path;
}	t_my_args;

int	my_start(t_my_var *);

void	my_command(t_my_var *);

/*
** LIB
*/

int	my_malloc(char	**, char, int);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
char	*my_pure(char *);
void	my_exit(t_my_var *);

#endif /*MY_H_*/
