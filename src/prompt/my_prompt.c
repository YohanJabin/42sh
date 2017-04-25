/*
** my_prompt.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 13 20:59:22 2017 Adrien ZEMMA
** Last update	Tue Apr 25 15:50:26 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_prompt(t_my_data *data)
{
  int nb;
  char *buff;

  nb = -1;
  if ((int)data->prompt_compteur != -1)
    my_printf("[%d] ", ++data->prompt_compteur);
  while (data->prompt_prompt[++nb] != NULL)
  {
    if (data->prompt_prompt[nb] == NULL)
      break;
    my_malloc(&buff, '\0', 2048);
    if (my_strncmp(my_clean(data->prompt_prompt[nb]),
      "name", my_strlen("name")) == 1)
      my_printf(ANSI_COLOR_RED"%s "ANSI_COLOR_RESET, getenv("USER"));
    else if (my_strncmp(my_clean(data->prompt_prompt[nb]),
    "date", my_strlen("date")) == 1)
      my_printf("%s ", "date");
    else if (my_strncmp(my_clean(data->prompt_prompt[nb]),
      "folder", my_strlen("folder")) == 1)
    {
      getcwd(buff, 2048);
      my_printf(ANSI_COLOR_BLUE"%s "ANSI_COLOR_RESET, last_buff(buff));
    }
  }
  if (access(".git", F_OK) == 0 && data->prompt_git == 1)
    my_printf(ANSI_COLOR_YELLOW"[git]" ANSI_COLOR_RESET);
}
