/*
** my_prompt.c for Parse_42sh
**
** Made by	Adrien ZEMMA
** Login	adrien.zemma@epitech.eu
**
** Started on	Thu Apr 13 20:59:22 2017 Adrien ZEMMA
** Last update	Fri May 19 16:39:21 2017 Adrien ZEMMA
*/

#include "my.h"

void	my_prompt(t_my_prompt *prompt)
{
  int nb;
  char buff[2049];

  nb = -1;
  if ((int)prompt->prompt_compteur != -1)
    my_printf("[%d] ", ++prompt->prompt_compteur);
  if (prompt->prompt_prompt[0] == NULL)
    my_default_prompt();
  while (prompt->prompt_prompt[++nb] != NULL)
  {
    if (my_strncmp(my_clean(prompt->prompt_prompt[nb]),
      "name", my_strlen("name")) == 1)
      my_printf(ANSI_COLOR_RED"%s "ANSI_COLOR_RESET, getenv("USER"));
    else if (my_strncmp(my_clean(prompt->prompt_prompt[nb]),
      "folder", my_strlen("folder")) == 1)
    {
      getcwd(buff, 2048);
      my_printf(ANSI_COLOR_BLUE"%s "ANSI_COLOR_RESET, last_buff(buff));
    }
  }
  if (access(".git", F_OK) == 0 && prompt->prompt_git == 1)
    my_printf(ANSI_COLOR_YELLOW"[git]" ANSI_COLOR_RESET);
}

void	my_default_prompt()
{
  my_printf("$> ");
}
