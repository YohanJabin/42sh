/*
** main.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 17:14:43 2017 Adrien ZEMMA
** Last update	Fri May 19 16:25:26 2017 Adrien ZEMMA
*/

#include "my.h"

int my_read_rc(t_my_prompt *prompt)
{
  int fd;

  if (access(".42shrc", R_OK) == 0)
    fd = open(".42shrc", O_RDONLY);
  else
    return (84);
  prompt->prompt_compteur = -1;
  prompt->prompt_git = 0;
  prompt->histori_tab = malloc(sizeof(char *) * 3);
  prompt->histori_nb = 0;
  prompt->fd_rc = fd;
  my_setprompt(prompt);
  close(fd);
  return (0);
}
