/*
** script.h for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/include
**
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
**
** Started on  Thu May  4 15:08:25 2017 Yohan.Jabin
** Last update	Fri May 19 12:58:38 2017 Hugo MARTIN
*/

#ifndef SCRIPT_H_
# define SCRIPT_H_

typedef struct	s_script
{
  int		if_status;
  int		foreach_if_status;
  int		foreach_status;
  char		*foreach_var;
  char		**foreach_words;
  int		foreach_hm_words;
}		t_script;

typedef struct s_my_repeat
{
  int 		hm;
  char	*command;
}		t_my_repeat;

#endif /* !SCRIPT_H_ */
