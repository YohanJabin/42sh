/*
** foreach.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/scripting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 16:51:26 2017 Yohan.Jabin
** Last update Fri May  5 13:42:36 2017 Yohan.Jabin
*/

#include "my.h"

int	test_foreach_parenthesis(char **imp, int len)
{
  if (imp[2][0] != '(' || imp[len - 1][0] != ')')
    return (1);
  return (0);
}

char	**create_foreach_words(char **imp)
{
  char	**ret;
  int	len;

  len = 1;
  while (imp[++len] != NULL && imp[len][0] != ')');
  if ((ret = malloc(sizeof(char *) * (len - 1))) == NULL)
    return (NULL);
  ret[len - 2] = NULL;
  len = 1;
  while (imp[++len] != NULL && imp[len][0] != ')')
    ret[len - 2] = my_strdup(imp[len]);
  return (ret);
}

int	test_foreach(t_my_var *data, char **imp)
{
  int	len;

  if ((len = hm_many_env(imp)) >= 5)
    {
      //if (test_foreach_parenthesis(imp, len) == 1)
      //return (1);
      data->script.foreach_status = 1;
      data->script.foreach_var = my_strdup(imp[1]);
      data->script.foreach_words = create_foreach_words(imp);
    }
  else
    return (1);
  return (0);
}

void	parse_foreach(t_my_var *data, char **imp)
{
  if (test_foreach(data, imp) == 1)
    {
      my_fprintf(2, "foreach: Expression Syntax.\n");
      data->return_value = 1;
    }
  else
    {
      data->flag_prompt = 0;
      start_foreach(data);
      data->flag_prompt = 1;
      data->script.foreach_status = 0;
      free(data->script.foreach_var);
      free_double_tab(data->script.foreach_words);
    }
}
