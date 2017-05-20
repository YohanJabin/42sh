/*
** process_foreach.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 20:24:27 2017 Yohan.Jabin
** Last update Sat May 20 13:30:39 2017 Yohan.Jabin
*/

#include "my.h"

int	foreach_next_endif(t_my_var *data, char **cmd, int i, int flag)
{
  char	**arr;

  while (cmd[++i] != NULL)
    {
      if (format_imput(data, &cmd[i]) == 0)
	{
	  arr = my_str_to_wordtab(cmd[i]);
	  if (my_strncmp(arr[0], "if", 3)
	      || my_strncmp(arr[0], "else", 5))
	    return (i);
	  if (flag == 1)
	    parse_pipe(data, cmd[i]);
	}
    }
  return (i - 1);
}

void	foreach_send_cmd(t_my_var *data, char **cmd_b)
{
  int	j;
  char	**cmd;
  char	**arr;

  cmd = cpy_arr_env(cmd_b);
  j = -1;
  while (cmd[++j] != NULL)
    {
      if (format_imput(data, &cmd[j]) == 0)
	{
	  arr = my_str_to_wordtab(cmd[j]);
	  if (my_strncmp(arr[0], "if", 3)
	      || my_strncmp(arr[0], "else", 5))
	    {
	      test_cmd_scripting_if(data, arr, &cmd[j]);
	      if (data->script.foreach_if_status != -1)
		j = foreach_next_endif(data, cmd, j, 1);
	      else
		j = foreach_next_endif(data, cmd, j, 0);
	    }
	  else
	    parse_pipe(data, cmd[j]);
	}
    }
}

void	my_foreach(t_my_var *data, char **cmd)
{
  char	**var;
  int	i;

  var = malloc(sizeof(char *) * 3);
  var[0] = malloc(sizeof(char) * 1);
  var[0][0] = 0;
  var[2] = NULL;
  i = -1;
  while (data->script.foreach_words[++i] != NULL)
    {
      var[1] = my_strcat(data->script.foreach_var, "=");
      var[1] = my_strcat(var[1], data->script.foreach_words[i]);
      my_setvar(data, var);
      foreach_send_cmd(data, cmd);
    }
}

char                    **get_foreach_cmd(t_my_var *data)
{
  t_my_list_data        *command;
  char                  **ret;
  int                   i;
  char                  **arr;

  if ((ret = malloc(sizeof(char *))) == NULL)
    return (NULL);
  ret[0] = NULL;
  i = 1;
  while ((my_command(data, data->prompt)) != -1)
    {
      command = data->list_command->begin;
      while (command)
	{
	  arr = my_str_to_wordtab(command->data);
	  if (my_strncmp(arr[0], "end", 4) == 1)
	    return (ret);
	  if ((ret = realloc(ret, sizeof(char *) * (i + 1))) == NULL)
	    return (NULL);
	  ret[i - 1] = my_strdup(command->data);
	  ret[i++] = NULL;
	  command = command->next;
	}
    }
  return (NULL);
}

void    start_foreach(t_my_var *data)
{
  char  **cmd;

  if ((cmd = get_foreach_cmd(data)) == NULL)
    {
      my_fprintf(2, "foreach: end not found.\n");
      return ;
    }
  else
    my_foreach(data, cmd);
}
