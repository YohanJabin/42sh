/*
** init_var.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/setup
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 11:57:28 2017 Yohan.Jabin
** Last update Thu May  4 11:58:41 2017 Yohan.Jabin
*/

#include "my.h"

char	**init_var()
{
  char	**var;

  if ((var = malloc(sizeof(char *))) == NULL)
    return (NULL);
  var[0] = NULL;
  return (var);
}
