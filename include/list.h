/*
** my.h for my.h in /home/hugo.martin/CPool_Day12/include
**
** Made by Hugo MARTIN
** Login   <hugo.martin@epitech.net>
**
** Started on  Tue Oct 18 09:05:12 2016 Hugo MARTIN
** Last update	Sun May 21 18:30:23 2017 Adrien ZEMMA
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_my_list_data
{
  void		*data;
  struct	s_my_list_data *next;
  struct	s_my_list_data *prev;
}		t_my_list_data;

typedef struct	s_my_list_cont
{
  int		length;
  struct	s_my_list_data	*begin;
  struct	s_my_list_data	*end;
}		t_my_list_cont;

typedef struct	s_my_separator
{
  char		*command;
  int		flag;
}		t_my_separator;

void		rm_end_list(t_my_list_cont **);
void		rm_start_list(t_my_list_cont **);

void		aff_list(t_my_list_cont *);
void		free_list(t_my_list_cont *);

void		add_end_list(t_my_list_cont **, void *);
void		add_start_list(t_my_list_cont **, void *);
#endif /* LIST_H_ */
