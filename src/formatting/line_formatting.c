/*
** line_formatting.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/exec
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Mon May  8 13:51:36 2017 Yohan.Jabin
** Last update Sun May 21 19:03:48 2017 Yohan.Jabin
*/

#include "my.h"

int	get_var_len(char *imp)
{
  int	len;

  len = -1;
  while (imp[++len] != 0)
    {
      if (imp[len] < '0'
	  || (imp[len] > '9' && imp[len] < 'A')
	  || (imp[len] > 'Z' && imp[len] < 'a')
	  || imp[len] > 'z')
	return (len);
    }
  return (len);
}

int	format_change_var(t_my_var *data, char **imp, int i)
{
  int	var_len;
  char	*to_search;
  char	*var;
  int	flag;

  flag = 0;
  if ((*imp)[i + 1] == '{')
    flag = 1;
  var_len = get_var_len(&(*imp)[i + 1 + flag]);
  if (flag == 1 && (*imp)[i + 1 + flag + var_len] != '}')
    {
      my_fprintf(2, "Missing '}'.\n");
      return (1);
    }
  if ((to_search = malloc(sizeof(char) * (var_len + 1))) == NULL)
    return (1);
  my_memset(to_search, 0, var_len + 1);
  my_strncpy(to_search, &(*imp)[i + 1 + flag], var_len);
  if ((var = get_var(data, to_search)) == NULL)
    return (1);
  *imp = my_strcut(*imp, i, var_len + 1 + (flag * 2));
  *imp = my_stradd(*imp, var, i);
  return (0);
}

int	magic_quote(t_my_var *data, char **imp, int *i)
{
  *imp = my_strcut(*imp, *i, 1);
  (*i)--;
  while ((*imp)[++(*i)] != 0 && (*imp)[*i] != '\'');
  if ((*imp)[*i] == 0)
    {
      my_fprintf(2, "Unmatched '''.\n");
      data->return_value = 1;
      return (84);
    }
  if ((*imp)[*i] == '\'')
    {
      *imp = my_strcut(*imp, *i, 1);
      (*i)--;
    }
  return (0);
}

int	format_imput_loop(t_my_var *data, char **imp, int *i)
{
  if ((*imp)[*i] == '`')
    if (parse_magic_quote(data, imp, *i) == -1)
      return (1);
  if ((*imp)[*i] == '$')
    {
      if (format_change_var(data, imp, *i) == 1)
	return (1);
      (*i)--;
    }
  if ((*imp)[*i] == '\'')
    if (magic_quote(data, imp, i) == 84)
      return (1);
  if ((*imp)[*i] == '(' || (*imp)[*i] == ')'
      || (*imp)[*i] == '{' || (*imp)[*i] == '}')
    *imp = my_strcut(*imp, (*i)--, 1);
  if ((*imp)[*i] == '*')
    if ((*i = format_globbing(data, imp, *i)) == -1)
      return (1);
  return (0);
}

int	format_imput(t_my_var *data, char **imp)
{
  int	i;

  if (tab_formatting(data, imp) == 0)
    return (1);
  i = -1;
  while ((*imp)[++i] != 0)
    {
      if ((*imp)[i] == '\\' && (*imp)[i + 1] != 0)
	*imp = my_strcut(*imp, i, 1);
      else
	{
	  if (format_imput_loop(data, imp, &i) == 1)
	    return (1);
	}
    }
  return (0);
}
