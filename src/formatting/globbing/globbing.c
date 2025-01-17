/*
** globbing.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/formatting
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Mon May 15 11:07:46 2017 Yohan.Jabin
** Last update Sun May 21 15:06:36 2017 Yohan.Jabin
*/

#include "my.h"

int	my_strncmp_globbing(char *str1, char *str2, int n)
{
  int	i;

  i = -1;
  while (++i < n)
    {
      if (str1[i] != '?' && str2[i] != '?')
	if (str1[i] != str2[i])
	  return (0);
    }
  return (1);
}

int	cmp_globbing(char *file, char **arr_star)
{
  int	size;
  int	i;
  int	j;
  int	len;

  size = hm_line_on_tab(arr_star);
  i = 0;
  j = -1;
  while (++j < size)
    {
      len = my_strlen(arr_star[j]);
      while (i < my_strlen(file)
	     && my_strncmp_globbing(&file[i], arr_star[j], len) == 0)
	i++;
      if (my_strncmp_globbing(&file[i], arr_star[j], len) == 0)
	return (0);
      i += len;
    }
  return (1);
}

int	tranform_globbing(char **imp,
			  char **arr_file,
			  char *to_process,
			  int j,
			  char *filename)
{
  char	**arr_star;
  int	i;

  if ((arr_star = create_arr_star(to_process)) == NULL)
    return (-1);
  i = -1;
  while (arr_file[++i] != NULL)
    {
      if (cmp_globbing(arr_file[i], arr_star) == 0)
	arr_file[i][0] = 0;
    }
  i = -1;
  while (arr_file[++i] != NULL)
    {
      if (arr_file[i][0] != 0)
	{
	  *imp = my_stradd(*imp, filename, j);
	  j += my_strlen(filename);
	  *imp = my_stradd(*imp, arr_file[i], j);
	  j += my_strlen(arr_file[i]);
	  *imp = my_stradd(*imp, " ", j++);
	}
    }
  return (0);
}

int	format_globbing(t_my_var *data, char **imp, int i)
{
  int	j;
  char	*to_process;
  char	*filename;
  char	**arr_file;

  while (--i >= 0 && ((*imp)[i] != ' ' && (*imp)[i] != '\t'));
  i++;
  j = -1;
  while ((*imp)[i + ++j] != 0
	 && (*imp)[i + j] != ' ' && (*imp)[i + j] != '\t');
  to_process = malloc(sizeof(char) * (j + 1));
  my_memset(to_process, 0, j + 1);
  my_strncpy(to_process, &(*imp)[i], j);
  if ((filename = get_globbing_filename(to_process)) == NULL)
    return (-1);
  if ((arr_file = get_file_arr(filename)) == NULL)
    return (-1);
  if ((j = my_strlen(filename)) <= 1 && filename[0] == '.')
    j = 0;
  *imp = my_strcut(*imp, i, my_strlen(to_process));
  if (tranform_globbing(imp, arr_file, &to_process[j], i, filename) == 84)
    return (-1);
  if (globbing_no_match(data, arr_file, *imp) == 84)
    return (-1);
  return (i);
}
