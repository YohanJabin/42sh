/*
** my_prompt.h for PSU_2016_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Fri Apr 21 13:41:05 2017 Adrien ZEMMA
** Last update	Sun May 21 18:31:05 2017 Adrien ZEMMA
*/

#ifndef MY_PROMPT_H
# define MY_PROMPT_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct		s_my_prompt
{
  int			fd_rc;
  int			prompt_git;
  unsigned int		prompt_compteur;
  char			**prompt_prompt;
  char			**prompt_ignore;
  char			**histori_tab;
  int			histori_nb;
  int			ret;
  int			exit;
  char			**env;
  struct s_redir	redir;
}			t_my_prompt;

int			my_histori(char *, t_my_prompt *);
char			*my_clean(char *);
char			*last_buff(char *);
char			*retir_char(char *, int);
int			my_read_rc(t_my_prompt *);
void			my_setprompt(t_my_prompt *);
void			my_prompt(t_my_prompt *);
void			my_default_prompt();

#endif /* !MY_PROMPT_H_ */
