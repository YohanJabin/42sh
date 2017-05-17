
/*
** key.c for 42sh in /home/tokou/Documents/PSU_2016_minishell2/key
** 
** Made by Léron
** Login   <trolol>
** 
** Started on  Tue Apr 25 12:52:22 2017 Léron
** Last update Wed May 17 10:36:42 2017 Léron
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
  int	size;

  size = my_strlen(str);
  if (strncomp(str, p->keyleft, (size)) == 1)
    printf("cmp->gauche\n");
  if (strncomp(str, p->keyright, (size)) == 1)
    printf("cmp->droite\n");
  if (strncomp(str, p->keybot, (size)) == 1)
    printf("cmp->bas\n");
  if (strncomp(str, p->keytop, (size)) == 1)
    printf("cmp->haut\n");
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

char	*my_read(t_conf_key *p)
{
  char	*buff;
  struct termios	old;
  struct termios	new;
  int	size;
  int	i;

  i = 0;
  buff = malloc(sizeof(char) * 100);
  memset(buff, 0, 100);
  ioctl(0, TCGETS, &old);
  new = old;
  new.c_lflag &= ~ECHO;
  new.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &new);
  size = read(0, buff, 10);
  buff[size] = '\0';
  test_fleche(buff, p);
  ioctl(0, TCSETS, &old);
  return (buff);
}

int	test(t_conf_key *p)
{

  while (1)
    {
      my_read(p);
    }
}

t_conf_key	*conf_key()
{
  t_conf_key	*p;

  p = malloc(sizeof(*p));
  p->keyleft = tigetstr("kcub1");
  p->keyright = tigetstr("kcuf1");
  p->keytop = tigetstr("kcuu1");
  p->keybot = tigetstr("kcud1");
  return (p);
}

int		main(int ac, char **av)
{
  t_conf_key	*p;
  char		*mode;

  ac = ac;
  av = av;
  if (setupterm((getenv("TERM")), 0, 0) == ERR)
    return (84);
  if ((mode = tigetstr("smkx")) != NULL)
    write(1, mode, 7);
  p = conf_key();
  test(p);
}
