/*
** str_manip.c for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/src/utils
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Sun May 21 12:57:10 2017 Yohan.Jabin
** Last update Sun May 21 12:57:23 2017 Yohan.Jabin
*/

#include "my.h"

char    *my_strdup(char *str)
{
  char  *return_value;
  int   len;

  len = my_strlen(str);
  if ((return_value = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  my_memset(return_value, 0, len + 1);
  my_strncpy(return_value, str, len);
  return (return_value);
}
