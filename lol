/*
** my_prompt.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 13 20:59:22 2017 Adrien ZEMMA
** Last update	Sun Apr 23 12:55:00 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_prompt(t_my_data *data)
{
  int nb;
  char *buff;

  nb = -1;
  if (data->prompt_compteur != -1)
    my_printf("[%d] ", ++data->prompt_compteur);
  while (data->prompt_prompt[++nb] != NULL)
  {
    my_malloc(&buff, '\0', 2048);
    if (my_strncmp(my_clean(data->prompt_prompt[nb]),
      "name", my_strlen("name")) == 0)
      my_printf(ANSI_COLOR_RED"%s "ANSI_COLOR_RESET, getenv("USER"));
    if (my_strncmp(my_clean(data->prompt_prompt[nb]),
    "date", my_strlen("date")) == 0)
      printf("%s ", "date");
    if (my_strncmp(my_clean(data->prompt_prompt[nb]),
      "folder", my_strlen("folder")) == 0)
    {
      getcwd(buff, 2048);
      printf(ANSI_COLOR_BLUE"%s "ANSI_COLOR_RESET, last_buff(buff));
    }
  }
  if (access(".git", F_OK) == 0 && data->prompt_git == 1)
    printf(ANSI_COLOR_YELLOW"[git]" ANSI_COLOR_RESET);
  fflush(stdout);
}
