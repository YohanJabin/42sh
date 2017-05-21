/*
** init_magic_quote.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/magic_quote
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Fri May 19 22:02:43 2017 Yohan.Jabin
** Last update Sun May 21 18:15:12 2017 Yohan.Jabin
*/

#include "my.h"

char	*get_magic_cmd(char *imp, int j)
{
  char	*ret;

  if ((ret = malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  my_memset(ret, 0, j + 1);
  my_strncpy(ret, imp, j);
  return (ret);
}

int	parse_magic_quote(t_my_var *data, char **imp, int i)
{
  int	j;
  char	*cmd;
  char	*to_add;

  i++;
  j = -1;
  while ((*imp)[++j + i] != 0 && (*imp)[j + i] != '`'
	 && (i + j == 0 || (*imp)[j + i - 1] != '\\'));
  if ((*imp)[j + i] == 0)
    {
      my_fprintf(2, "Unmatched '`'.\n");
      data->return_value = 1;
      return (-1);
    }
  if ((cmd = get_magic_cmd(&(*imp)[i], j)) == NULL)
    return (-1);
  *imp = my_strcut(*imp, --i, j + 2);
  if ((to_add = process_magic_quote(data, cmd)) == NULL)
    return (-1);
  *imp = my_stradd(*imp, to_add, i);
  free(cmd);
  return (i + my_strlen(to_add));
}
