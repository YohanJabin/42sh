#ifndef MY_H
# define MY_H

#include "my_printf.h"
#include "my_fprintf.h"
#include "get_next_line.h"
#include "list.h"

int	my_strcmp(char *str, char *av);
int	*my_prepa(int *nb);
char	**str_to_tab(char *str, char fin);
int	comptechar_tab(char *str, char fin);
int	compteligne_tab(char *str, char fin);
int	my_strlen(char *str);
int	my_malloc(char	**str, char c, int size);
void	my_printf(char *fmt, ...);
void	my_putchar(char c, int fd);
int	functions(char *fmt, va_list ap, int i, int fd);
int	my_putnbr(int nb, int fd);
int	my_hexa(int nb, int fd);
int	my_convert(char *str, int nb, int i);
void	my_putstr(char *str, int fd);
void	my_putstr_err(char *str);
void	my_fprintf(int fd, char *fmt, ...);
int	my_strlen(char *str);
void	my_revstr(char *str, int fd);
void	aff_list(t_my_list_cont *list);
void	free_list(t_my_list_cont *list);
void	rm_end_list(t_my_list_cont **list);
void	rm_start_list(t_my_list_cont **list);
void	add_end_list(t_my_list_cont **list, void *str);
void	add_start_list(t_my_list_cont **list, void *str);
void	link_end_list(t_my_list_cont **list, t_my_list_data *data);
int	main(int ac, char **av, char **env);
void	my_echo(char *str, char **env);

#endif /*MY_H_*/
