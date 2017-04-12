/*
** get_next_line.h for PSU_2016_minishell2
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Apr 03 15:21:17 2017 Hugo MARTIN
** Last update	Mon Apr 03 16:11:40 2017 Hugo MARTIN
*/

# ifndef READ_SIZE
#		define READ_SIZE (500)
# endif /* !READ_SIZE */

typedef	struct	s_main
{
  char	*src;
  char	*buffer;
  int	s;
  char	*st;
}	t_main;

char	*get_next_line(const int);
char	*my_ralloc(char *, char *, int, int);
char	*new_stock(char *, int, int, int);
char	*my_process(char *);
int	my_len(char *, int);