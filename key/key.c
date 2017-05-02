
/*
** key.c for 42sh in /home/tokou/Documents/PSU_2016_minishell2/key
** 
** Made by Léron
** Login   <trolol>
** 
** Started on  Tue Apr 25 12:52:22 2017 Léron
** Last update Fri Apr 28 11:54:02 2017 Léron
*/
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <getopt.h>
#include <time.h>
#include <sys/ioctl.h>
#include "key.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}

int	strncomp(char *str, char *str2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (str[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}

int	test_fleche(char *str, t_conf_key *p)
{
  int	i;
  int	size;

  size = my_strlen(str);
  if (strncomp(str, p->keyleft, (size - 1)) == 1)
    printf("gauche\n");
}

char	*my_read(t_conf_key *p)
{
  char	buff[10];
  int	size;
  struct termios	old;
  struct termios	new;

  memset(buff, 0, 10);
  ioctl(0, TCGETS, &old);
  new = old;
  new.c_lflag &= ~ECHO;
  new.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &new);
  size = read(0, buff, 10);
  test_fleche(buff, p);
  ioctl(0, TCSETS, &old);
  return (buff);
}

int	test(t_conf_key *p)
{
  char *str;

  while (1)
    {
     str =  my_read(p);
    }
}

t_conf_key	*conf_key(t_conf_key *p)
{
  p->keyleft = tigetstr("kcub1");
  p->keyright = tigetstr("kcuf1");
  p->keytop = tigetstr("kcuu1");
  p->keybot = tigetstr("kcud1");
}

int		main(int ac, char **av)
{
  t_conf_key	*p;
  char		*str;
  
  p = malloc(sizeof(*p));
  if (setupterm((getenv("TERM")), 0, 0) == ERR)
    return (84);
  conf_key(p);
  test(p);
}
