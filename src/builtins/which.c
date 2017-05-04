/*
** which.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 21:25:49 2017 Yohan.Jabin
** Last update Thu May  4 21:50:18 2017 Yohan.Jabin
*/

#include "my.h"

void	search_cmd_path(t_my_var *data, char *cmd)
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
	  return ;
	}
    }
  my_fprintf(2, "%s: Command not found.\n", cmd);
  data->return_value = 1;
}

void	search_cmd(t_my_var *data, char *cmd)
{
  if (my_strncmp(cmd, "set", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "unset", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "cd", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "exit", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "env", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "setenv", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "unsetenv", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "which", my_strlen(cmd)) == 1
      || my_strncmp(cmd, "echo", my_strlen(cmd)) == 1)
    {
      my_printf("%s: shell built-in command.\n");
      return ;
    }
  search_cmd_path(data, cmd);
}

void	loop_which(t_my_var *data, char **imp)
{
  int	i;

  i = 0;
  while (imp[++i] != NULL)
    search_cmd(data, imp[i]);
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
	loop_which(data, imp);
      return (0);
    }
  return (1);
}
