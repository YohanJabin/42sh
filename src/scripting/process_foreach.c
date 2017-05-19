/*
** process_foreach.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 20:24:27 2017 Yohan.Jabin
** Last update Fri May 19 15:30:22 2017 Yohan.Jabin
*/

#include "my.h"

void	my_foreach(t_my_var *data, char **cmd)
{
  char	**var;
  int	i;
  int	j;

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
      j = -1;
      while (cmd[++j] != NULL)
	parse_pipe(data, cmd[j]);
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
	  ret[i] = NULL;
	  i++;
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
