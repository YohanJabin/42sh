/*
** arr_cmd.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:15:40 2017 Yohan.Jabin
** Last update Sun May 21 17:48:16 2017 Yohan.Jabin
*/

#include "my.h"

int	is_it_only_space_semicolon(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0 && str[i] != ';')
    if (str[i] != ' ')
      return (0);
  return (1);
}

int     my_strlen_cmd(char *imp)
{
  int   i;

  i = -1;
  while (imp[++i] != 0 && imp[i] != ';');
  return (i);
}

int	hm_cmd(char *imp)
{
  int	i;
  int	hm;
  int	len;

  hm = 0;
  i = -1;
  while (++i < my_strlen(imp))
    {
      while (imp[i] == ' ')
	i++;
      if (imp[i] == 0)
	return (hm);
      if (imp[i] != ';')
	{
	  len = my_strlen_cmd(&imp[i]);
	  if (is_it_only_space_semicolon(imp) == 0)
	    hm++;
	  i += len;
	}
    }
  return (hm);
}

void	parse_arr_cmd(char **cmd, char *imp)
{
  int	len;
  int	i;
  int	j;

  j = 0;
  i = -1;
  while (++i < my_strlen(imp))
    {
      while (imp[i] == ' ' || imp[i] == '\t')
	i++;
      if (imp[i] == 0)
	return;
      if (imp[i] != ';')
	{
	  len = my_strlen_cmd(&imp[i]);
	  cmd[j] = malloc(sizeof(char) * (len + 1));
	  my_memset(cmd[j], 0, len + 1);
	  my_strncpy(cmd[j], &imp[i], len);
	  j++;
	  i += len;
	}
    }
}

char	**create_arr_cmd(char *imp)
{
  char	**cmd;
  int	len;

  len = hm_cmd(imp);
  cmd = malloc(sizeof(char*) * (len + 1));
  cmd[len] = NULL;
  parse_arr_cmd(cmd, imp);
  return (cmd);
}
