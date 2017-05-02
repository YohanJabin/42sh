/*
** my_setprompt.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 18:30:36 2017 Adrien ZEMMA
** Last update	Fri Apr 28 15:32:52 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_setprompt(t_my_prompt *prompt)
{
  char *str;

  str = get_next_line(prompt->fd_rc);
  if (str == NULL)
    return ;
  if (str[0] == '#' || str[0] == '\0')
    my_setprompt(prompt);
  else if (my_strncmp("prompt=", str, 7) == 1)
    prompt->prompt_prompt = str_to_tab(retir_char(str, 7), ',');
  else if (my_strncmp("ignore=", str, 6) == 1)
    prompt->prompt_ignore = str_to_tab(retir_char(str, 7), ',');
  else if (my_strncmp("git= yes", str, 8) == 1)
    prompt->prompt_git = 1;
  else if ((int)prompt->prompt_compteur == -1 &&
    my_strncmp("compteur= yes", str, 13) == 1)
    prompt->prompt_compteur = 0;
  my_setprompt(prompt);
}
