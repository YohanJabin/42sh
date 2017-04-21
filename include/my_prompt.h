/*
** my_prompt.h for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Fri Apr 21 13:41:05 2017 Adrien ZEMMA
** Last update	Fri Apr 21 14:10:30 2017 Adrien ZEMMA
*/

#ifndef MY_PROMPT_H
# define MY_PROMPT_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_my_data
{
  int fd_rc;
  int prompt_git;
  int prompt_compteur;
  char **prompt_prompt;
  char **prompt_ignore;
  char **histori_tab;
  int histori_nb;
}	t_my_data;

int	my_histori(char *str, t_my_data *data);
char	*my_clean(char *str);
char *last_buff(char *buff);
char *retir_char(char *str, int nb);
int my_read_rc(t_my_data *data);
void	my_setprompt(t_my_data *data);
void	my_prompt(t_my_data *data);

#endif /* !MY_PROMPT_H_ */
