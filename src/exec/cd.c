/*
** cd.c for minishell in /home/yohan/repo/PSU/PSU_2016_minishell2/src
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
**
** Started on  Sun Mar 26 12:35:53 2017 Yohan.Jabin
** Last update	Fri Apr 28 09:27:37 2017 Adrien ZEMMA
*/

#include "my.h"

void	change_pwd(t_my_data *data)
{
  int   index;
  int   index2;

  if ((index2 = get_index_env(data->env, "OLDPWD")) == -1)
    {
      if ((index = get_index_env(data->env, "PWD")) != -1)
	add_env(data, "OLDPWD", &data->env[index][4]);
    }
  else
    {
      if ((index = get_index_env(data->env, "PWD")) != -1)
	change_env(data, "OLDPWD", &data->env[index][4], index2);
    }
}

int	test_cd_home(t_my_data *data, char **imp)
{
  int   index;

  if (imp[1] == NULL)
    {
      if ((index = get_index_env(data->env, "HOME")) == -1)
	{
	  my_fprintf(2, "cd: No home directory.\n");
	  data->ret = 1;
	}
      else if (chdir(&data->env[index][5]) == -1)
	{
	  my_fprintf(2, "%s: %s.\n", &data->env[index][5], strerror(errno));
	  data->ret = 1;
	}
      return (1);
    }
  return (0);
}

int	test_cd_old(t_my_data *data, char **imp)
{
  int	index;

  if (my_strncmp(imp[1], "-", 2) == 1)
    {
      if ((index = get_index_env(data->env, "OLDPWD")) == -1)
	{
	  my_fprintf(2, ": No such file or directory.\n");
	  data->ret = 1;
	}
      else if (chdir(&data->env[index][7]) == -1)
	{
	  my_fprintf(2, "%s: %s.\n", &data->env[index][7], strerror(errno));
	  data->ret = 1;
	}
      return (1);
    }
  return (0);
}

int	test_cd(t_my_data *data, char **imp)
{
  if (test_cd_home(data, imp) == 1)
    return (1);
  else if (test_cd_old(data, imp) == 1)
    return (1);
  else if (chdir(&imp[1][0]) == -1)
    {
      my_fprintf(2, "%s: %s.\n", &imp[1][0], strerror(errno));
      data->ret = 1;
      return (0);
    }
  return (1);
}

int	my_cd(t_my_data *data, char **imp)
{
  if (imp[1] != NULL && imp[2] != NULL)
    {
      my_fprintf(2, "cd: Too many arguments.\n");
      data->ret = 1;
      return (84);
    }
  else if (test_cd(data, imp) == 1)
    change_pwd(data);
  else
    return (84);
  return (1);
}
