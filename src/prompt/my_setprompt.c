/*
** my_setprompt.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 18:30:36 2017 Adrien ZEMMA
** Last update	Mon Apr 24 15:43:10 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_setprompt(t_my_data *data)
{
  char *str;

  str = get_next_line(data->fd_rc);
  if (str == NULL)
    return ;
  if (str[0] == '#' || str[0] == '\0')
    my_setprompt(data);
  if (my_strncmp("prompt=", str, 7) == 1)
    data->prompt_prompt = str_to_tab(retir_char(str, 7), ',');
  else if (my_strncmp("ignore=", str, 6) == 1)
    data->prompt_ignore = str_to_tab(retir_char(str, 7), ',');
  else if (my_strncmp("git=", str, 3) == 1)
    data->prompt_git = 1;
  else if (data->prompt_compteur == -1 && my_strncmp("compteur=", str, 9) == 0)
    data->prompt_compteur = 0;
  my_setprompt(data);
}
