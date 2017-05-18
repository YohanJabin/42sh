/*
** cmd.c for minishell in /home/yohan/repo/PSU/my_minishell
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Thu Mar  2 16:49:41 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:28:16 2017 Adrien ZEMMA
*/

#include "my.h"

int	is_it_direct_path(char *path)
{
  int	i;

  i = 0;
  while (path[i] != 0 && path[i] != '/')
    i++;
  if (path[i] == 0)
    return (1);
  if (path[i + 1] != 0)
    return (0);
  return (0);
}

char	**get_hard_path(t_my_var *data)
{
  char	**arr_path;
  char	*path;
  int	len;
  //char	*var;
  //int	index;

  /*if ((index = get_index_var(data->var, "path")) == -1)
    return (NULL);
  if ((var = get_var_str(data->var, index)) == NULL)
    return (NULL);
  if ((arr_path = my_str_to_wordtab(var)) == NULL)
    return (NULL);
  free(var);*/
  len = confstr(_CS_PATH, NULL, 0);
  if ((path = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_memset(path, 0, len + 1);
  confstr(_CS_PATH, path, len);
  if ((arr_path = str_to_tab(path, ':')) == NULL)
    return (NULL);
  return (arr_path);
}

int     test_cmd_path(t_my_var *data, char **imp)
{
  char	**arr_path;
  char	*binary;
  int	i;

  if (is_there_a_slash(imp[0]) == 1 && access(imp[0], F_OK) == 0)
    {
      my_exec(imp[0], imp, data);
      return (0);
    }
  if (is_it_direct_path(imp[0]) == 0)
    return (1);
  if ((arr_path = get_arr_path(data->env)) == NULL
      && (arr_path = get_hard_path(data)) == NULL)
    return (1);
  i = -1;
  while (arr_path[++i] != NULL)
    {
      binary = my_pathadd(arr_path[i], imp[0]);
      if (imp[0][0] != '/' && access(binary, F_OK) == 0)
	{
	  my_exec(binary, imp, data);
	  free_double_tab(arr_path);
	  return (0);
	}
      free(binary);
    }
  free_double_tab(arr_path);
  return (1);
}

int	test_cmd_builtin(t_my_var *data, char **imp)
{
  if (my_strncmp(imp[0], "endif", 6) == 1 ||
      my_strncmp(imp[0], "end", 4) == 1)
    return (1);
  if (tab_formatting(data, imp) == 0)
    return (1);
  if (test_cmd_scripting(data, imp) == 0)
    return (1);
  if (test_cmd_echo(data, imp) == 0)
    return (1);
  if (test_cmd_cd(data, imp) == 0)
    return (1);
  if (test_cmd_exit(data, imp) == 0)
    return (1);
  if (test_cmd_env(data, imp) == 0)
    return (1);
  if (test_cmd_var(data, imp) == 0)
    return (1);
  if (test_cmd_alias(data, imp) == 0)
    return (1);
  if (test_cmd_which(data, imp) == 0)
    return (1);
  if (test_cmd_path(data, imp) == 0)
    return (1);
  my_fprintf(2, "%s: Command not found.\n", &imp[0][0]);
  data->return_value = 1;
  return (1);
}
