/*
** main.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 20 17:14:43 2017 Adrien ZEMMA
** Last update	Sun Apr 23 11:26:59 2017 Adrien ZEMMA
*/

#include "my.h"

int my_read_rc(t_my_data *data)
{
  int fd;

  if (access(".42shrc", R_OK) == 0)
    fd = open(".42shrc", O_RDONLY);
  else
    return (84);
  data->prompt_compteur = -1;
  data->prompt_git = 0;
  data->histori_tab = malloc(sizeof(char *) * 3);
  data->histori_nb = 0;
  data->fd_rc = fd;
  my_setprompt(data);
  close(fd);
  return (0);
}
