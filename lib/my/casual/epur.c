/*
** epur.c for minishell2
**
** Made by	Hugo MARTIN
** Login	hugo.martin@epitech.eu
**
** Started on	Mon Mar 27 17:05:49 2017 Hugo MARTIN
** Last update	Sun May 21 11:40:10 2017 Hugo MARTIN
*/

#include "my.h"

int	my_first_space(char *a)
{
  int	nb;

  nb = -1;
  while (a[++nb] == '\t' || a[nb] == ' ');
  return (nb);
}

char	*my_pure(char *command)
{
  int	i;
  int	j;
  char	*pure;

  pure = malloc(sizeof(char) * my_strlen(command) + 1);
  i = my_first_space(command);
  j = 0;
  while (command[i])
    {
      if (i != my_first_space(command))
        if (command[i] > ' ' && (command[i - 1] == ' ' ||
            command[i - 1] == '\t'))
	  {
	    pure[j] = ' ';
	    j++;
	  }
      if (command[i] > ' ')
	{
	  pure[j] = command[i];
	  j++;
	}
      i++;
    }
  pure[j] = '\0';
  return (pure);
}
