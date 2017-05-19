/*
** which.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 21:25:49 2017 Yohan.Jabin
** Last update Fri May 19 11:24:07 2017 Yohan.Jabin
*/

#include "my.h"

void	search_cmd_path(t_my_var *data, char *cmd, int flag, int *hm)
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
	  (*hm)++;
	}
    }
  if (flag == 1)
    {
      my_fprintf(2, "%s: Command not found.\n", cmd);
      data->return_value = 1;
    }
}

void	search_cmd(t_my_var *data, char *cmd, int flag, int *hm)
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
      (*hm)++;
    }
  search_cmd_path(data, cmd, flag, hm);
}

void	loop_which(t_my_var *data, char **imp, int flag, int *hm)
{
  int	i;
  int	index;
  int	first_equal;

  i = 0;
  while (imp[++i] != NULL)
    {
      if ((index = check_alias(data, imp[i])) != -1)
	{
	  first_equal = get_first_equal(data->alias[index]);
	  write(1, data->alias[index], first_equal);
	  my_printf(" is aliased to %s\n", &data->alias[index][first_equal + 1]);
	}
      search_cmd(data, imp[i], flag, hm);
    }
}

int	test_cmd_which(t_my_var *data, char **imp)
{
  int	hm;

  hm = 0;
  if (my_strncmp(imp[0], "which", 6) == 1)
    {
      if (imp[1] == NULL)
	{
	  my_fprintf(2, "which: Too few arguments.\n");
	  data->return_value = 1;
	}
      else
	loop_which(data, imp, 1, &hm);
      return (0);
    }
  else if (my_strncmp(imp[0], "where", 6) == 1)
    {
      loop_which(data, imp, 2, &hm);
      if (hm == 0)
	data->return_value = 1;
      return (0);
    }
  return (1);
}
