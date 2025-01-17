/*
** get_next_line.h for PSU_2016_minishell2
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Apr 03 15:21:17 2017 Hugo MARTIN
** Last update	Sun May 21 18:30:09 2017 Adrien ZEMMA
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#		define READ_SIZE (500)
# endif /* !READ_SIZE */

typedef	struct	s_gnl
{
  char		*src;
  char		*buffer;
  int		s;
  char		*st;
}		t_gnl;

char		*get_next_line(const int);
char		*my_ralloc(char *, char *, int, int);
char		*new_stock(char *, int, int, int);
char		*my_process(char *);
int		my_len(char *, int);
#endif /* !GET_NEXT_LINE_H_ */
