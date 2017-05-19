/*
** tab_formating.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/exec
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sun May 14 15:16:08 2017 Yohan.Jabin
** Last update Fri May 19 13:50:58 2017 Yohan.Jabin
*/

#include "my.h"

char	*get_name_formatting(char *imp)
{
  char	**arr;
  int	len;
  char	*ret;

  if ((arr = my_str_to_wordtab(imp)) == NULL)
    return (NULL);
  len = my_strlen(arr[0]);
  if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_memset(ret, 0, len + 1);
  my_strncpy(ret, arr[0], len);
  free_double_tab(arr);
  return (ret);
}

int	tab_formatting(t_my_var *data, char **imp)
{
  char	*tmp;
  int	index;
  char	*var;
  int	len;
  char	*backup;

  tmp = get_name_formatting(*imp);
  backup = my_strdup(tmp);
  while ((index = get_index_alias(data->alias, tmp)) != -1)
    {
      len = get_first_equal(data->alias[index]);
      var = get_var_str(data->alias, index);
      if (my_strncmp(backup, var, my_strlen(backup)) == 1)
	{
	  my_fprintf(2, "Alias loop.\n");
	  data->return_value = 1;
	  free(backup);
	  free(var);
	  return (0);
	}
      *imp = my_strcut(*imp, 0, len);
      *imp = my_stradd(*imp, var, 0);
      tmp = get_name_formatting(*imp);
    }
  return (1);
}
