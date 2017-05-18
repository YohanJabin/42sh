/*
** tab_formating.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/exec
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sun May 14 15:16:08 2017 Yohan.Jabin
** Last update Thu May 18 10:48:16 2017 Yohan.Jabin
*/

#include "my.h"

int	tab_formatting(t_my_var *data, char **imp)
{
  int	index;
  char	*var;
  int	len;
  char	*backup;

  backup = my_strdup(imp[0]);
  while ((index = get_index_alias(data->alias, imp[0])) != -1)
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
      imp[0] = my_strcut(imp[0], 0, len);
      imp[0] = my_stradd(imp[0], var, 0);
    }
  return (1);
}
