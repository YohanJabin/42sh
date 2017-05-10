/*
** script.h for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/include
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
**
** Started on  Thu May  4 15:08:25 2017 Yohan.Jabin
** Last update	Wed May 10 15:34:19 2017 Hugo MARTIN
*/

#ifndef SCRIPT_H_
# define SCRIPT_H_

typedef struct	s_script
{
  int		if_status;
  int		foreach_status;
  char		*foreach_var;
  char		**foreach_words;
  int		foreach_hm_words;
  int		repeat_f;
  int		repeat_n;
  char	*repeat_c;
}		t_script;

#endif /* !SCRIPT_H_ */
