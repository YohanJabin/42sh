/*
** my.h for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Fri Apr 28 16:10:30 2017 Hugo
** Last update Fri Apr 28 16:10:32 2017 Hugo
*/

#ifndef MY_H_
# define MY_H_

#include "redir.h"
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
  t_my_list_cont	*separator;
}			t_my_var;

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
char	*get_arg(char *, int, char *);

/*
** SEPARATOR
*/

void	my_separator(t_my_var *);
int	my_check_char(char *, char);

#endif /* !MY_H_ */
