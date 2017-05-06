/*
** comments.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/command
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sat May  6 14:30:47 2017 Yohan.Jabin
** Last update Sat May  6 14:32:18 2017 Yohan.Jabin
*/

#include "my.h"

void	check_comment(char *cmd)
{
  int	i;

  i = -1;
  while (cmd[++i] != 0)
    if (cmd[i] == '#')
      {
	cmd[i] = 0;
	return ;
      }
}
