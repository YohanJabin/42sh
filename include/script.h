/*
** script.h for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/include
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu>
** 
** Started on  Thu May  4 15:08:25 2017 Yohan.Jabin
** Last update Sat May  6 13:40:12 2017 Yohan.Jabin
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
}		t_script;

#endif /* !SCRIPT_H_ */
