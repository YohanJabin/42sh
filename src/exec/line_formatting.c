/*
** line_formatting.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/exec
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Mon May  8 13:51:36 2017 Yohan.Jabin
** Last update Sun May 14 15:13:01 2017 Yohan.Jabin
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
  free(to_search);
  free(var);
  return (0);
}

void	format_change_alias(t_my_var *data, char **imp, int i)
{
  int	index;
  char	*var;
  int	len;

  if ((index = check_alias(data, &(*imp)[i])) == -1)
    return ;
  len = get_first_equal(data->alias[index]);
  var = get_var_str(data->alias, index);
  *imp = my_strcut(*imp, i, len);
  *imp = my_stradd(*imp, var, i);
}

int	format_imput(t_my_var *data, char **imp)
{
  int	i;

  i = -1;
  while ((*imp)[++i] != 0)
    {
      if ((*imp)[i] == '(' || (*imp)[i] == ')')
	*imp = my_strcut(*imp, i--, 1);
      if ((*imp)[i] == '$')
	{
	  if (format_change_var(data, imp, i) == 1)
	    return (1);
	  i--;
	}
    }
  return (0);
}
