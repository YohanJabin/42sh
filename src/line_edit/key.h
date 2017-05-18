/*
** key.h for 42 SH in /home/tokou/Documents/PSU_2016_minishell2/key
** 
** Made by Léron
** Login   <trolol>
** 
** Started on  Tue Apr 25 14:59:38 2017 Léron
** Last update Wed May 17 11:15:24 2017 Léron
*/

#ifndef KEY_H_
# define KEY_H_

typedef	struct	s_conf_key
{
  char		*keyleft;
  char		*keyright;
  char		*keytop;
  char		*keybot;
  char		*keyenter;
  char		*keytab;
}		t_conf_key;

#include <string.h>

#endif /* !KEY_H_ */
