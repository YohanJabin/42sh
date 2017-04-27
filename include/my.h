/*
** my.h for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Wed Apr 12 17:30:28 2017 Adrien ZEMMA
** Last update	Tue Apr 25 15:23:32 2017 Adrien ZEMMA
*/

#ifndef MY_H_
# define MY_H_

//#include "redir.h"
#include "my_prompt.h"
#include "my_printf.h"
#include "my_fprintf.h"
#include "get_next_line.h"
#include "list.h"

typedef	struct		s_my_var
{
  char			**env;
  char			*full_command;
  char			*command;
  int			return_value;
  t_my_list_cont	*list_command;
}			t_my_var;

typedef struct	s_my_args
{
  int		i;
  int		j;
  int		k;
  int		n;
  char		*path;
}		t_my_args;

int	my_start(t_my_var *, t_my_data *);

void	my_command(t_my_var *, t_my_data *);

/*
** LIB
*/

int	my_malloc(char	**, char, int);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
char	*my_pure(char *);
char	**str_to_tab(char *, char);
void	my_exit(t_my_var *);

#endif /* !MY_H_ */
