/*
** my_setprompt.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 18:30:36 2017 Adrien ZEMMA
** Last update	Fri Apr 21 14:53:54 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_setprompt(t_my_data *data)
{
  char *str;

  str = get_next_line(data->fd_rc);
  my_printf("%s\n", str);
  if (str == NULL)
    return ;
  if (str[0] == '#')
    my_setprompt(data);
  if (my_strncmp("prompt=", str, 6) == 0)
    data->prompt_prompt = str_to_tab(retir_char(str, 7), ',');
  if (my_strncmp("ignore=", str, 6) == 0)
    data->prompt_ignore = str_to_tab(retir_char(str, 7), ',');
  if (my_strncmp("git=", str, 3) == 0)
    data->prompt_git = 1;
  if (data->prompt_compteur == -1 && my_strncmp("compteur=", str, 8) == 0)
    data->prompt_compteur = 0;
  exit(0);
  my_setprompt(data);
}
