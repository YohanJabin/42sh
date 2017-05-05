/*
** which.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 21:25:49 2017 Yohan.Jabin
** Last update Fri May  5 13:04:09 2017 Yohan.Jabin
*/

#include "my.h"

void	search_cmd_path(t_my_var *data, char *cmd, int flag)
{
  char	**arr_path;
  char	*path;
  int	i;

  arr_path = get_arr_path(data->env);
  i = -1;
  while (arr_path[++i] != NULL)
    {
      path = my_pathadd(arr_path[i], cmd);
      if (access(path, F_OK) == 0)
	{
	  my_printf("%s\n", path);
	  if (flag == 1)
	    return ;
	}
    }
  if (flag == 1)
    {
      my_fprintf(2, "%s: Command not found.\n", cmd);
      data->return_value = 1;
    }
}

void	search_cmd(t_my_var *data, char *cmd, int flag)
{
  if (my_strncmp(cmd, "set", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "unset", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "cd", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "exit", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "env", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "setenv", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "unsetenv", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "which", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "where", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "echo", my_strlen(cmd)) == 1)
    {
      if (flag == 1)
	{
	  my_printf("%s: shell built-in command.\n", cmd);
	  return ;
	}
      my_printf("%s is a shell built-in\n", cmd);
    }
  search_cmd_path(data, cmd, flag);
}

void	loop_which(t_my_var *data, char **imp, int flag)
{
  int	i;

  i = 0;
  while (imp[++i] != NULL)
    search_cmd(data, imp[i], flag);
}

int	test_cmd_which(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "which", 6) == 1)
    {
      if (imp[1] == NULL)
	{
	  my_fprintf(2, "which: Too few arguments.\n");
	  data->return_value = 1;
	}
      else
	loop_which(data, imp, 1);
      return (0);
    }
  else if (my_strncmp(imp[0], "where", 6) == 1)
    {
      loop_which(data, imp, 2);
      return (0);
    }
  return (1);
}