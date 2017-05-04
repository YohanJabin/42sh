/*
** my.h for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.martin@epitech.eu>
** 
** Started on  Fri Apr 28 16:10:30 2017 Hugo
** Last update Thu May  4 14:09:15 2017 Yohan.Jabin
*/

#ifndef MY_H_
# define MY_H_

#include "redir.h"
#include "my_prompt.h"
#include "my_printf.h"
#include "my_fprintf.h"
#include "get_next_line.h"
#include "list.h"

typedef	struct		s_my_var
{
  char			**env;
  char			**var;
  char			*full_command;
  char			*command;
  int			return_value;
  int			exit;
  t_redir		redir;
  t_my_list_cont	*list_command;
  t_my_list_cont	*separator;
}			t_my_var;

int	my_start(t_my_var *, t_my_prompt *);
void	my_command(t_my_var *, t_my_prompt *);

/*
** LIB
*/

int	my_malloc(char	**, char, int);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
char	*my_pure(char *);
char	**str_to_tab(char *, char);
void	my_exit(t_my_var *);
char	*get_arg(char *, int, char *);
int	my_getnbr(const char *);

/*
** SEPARATOR
*/

void	my_separator(t_my_var *);
int	my_check_char(char *, char);

/* process_arr.c */
int     parse_pipe(t_my_var *, char *);

/* process_pid.c */
void    init_arr_pid(t_my_var *);
int     *add_pid(int *, int, int);
void    wait_all_pid(t_my_var *);
void    aff_pid(t_redir);

/* check_arr_cmd.c */
int     check_arr_cmd(char **);
int     how_many_exit(char **);
void    swap_cmd(char **, int);

/* process_imp.c */
int     process_imput(t_my_var *, char ***);
void    process_imput_loop(t_my_var *, char **);

/* redirections_right.c */
int     open_redirections_right(t_my_var *, char *);
int     check_error_redirections_right(t_my_var *, char **);
int     check_for_redirections_right(t_my_var *, char ***);
int     parse_redirections_right(t_my_var *, char ***, int);

/* redirections_left.c */
int     open_redirections_left(t_my_var *, char *);
int     check_error_redirections_left(t_my_var *, char **);
int     check_for_redirections_left(t_my_var *, char ***);
int     parse_redirections_left(t_my_var *, char ***, int);

/* new_redirect_tab.c */
char    **new_redirect_tab(char **, char);

/* double_redir_left.c */
void    double_redir_left(t_my_var *, char *);

/* check_pipe_error.c */
int     check_redirection_error(t_my_var *, char ***);
int     check_for_exit_pipe(t_my_var *, char ***);

/* manip_fd.c */
void    check_fd_for_exec(t_my_var *);

/* my_exec.c */
void    my_exec(char *, char **, t_my_var *);
void    check_child_status2(int, int, t_my_var *);
void    check_child_status(int, t_my_var *);

/* arr_pipe.c */
char    **create_arr_pipe(char *);
void    parse_arr_pipe(char **, char *);
int     hm_pipe(char *);
int     my_strlen_pipe(char *);
int     is_it_only_space_pipe(char *);

/* my_setenv.c */
void    my_setenv(t_my_var *, char **);
void    change_env(t_my_var *, char *, char *, int);
void    add_env(t_my_var *, char *, char *);
char    *get_string_to_add(char *, char *);

/* my_unsetenv.c */
void    my_unsetenv(t_my_var *, char **);
void    delete_env(t_my_var *, char *);
void    parse_delete_env(t_my_var *, char **, int);

/* cd.c */
int     my_cd(t_my_var *, char **);
int     test_cmd_cd(t_my_var *, char **);
int     test_cd_old(t_my_var *, char **);
int     test_cd_home(t_my_var *, char **);
void    change_pwd(t_my_var *);

/* my_str_to_wordtab.c */
char    **my_str_to_wordtab(char *);
void    parse_tab(char **, char *, int);
int     size_word(char *);
int     size_word(char *);
int     hm_word(char *);

/* arr_env.c */
char    **cpy_arr_env(char **);
void    parse_env(char **, char **);
int     hm_many_env(char **);
int     get_index_env(char **, char *);

/* env.c */
int     test_cmd_env(t_my_var *, char **);
void    my_error_setenv(t_my_var *, char **);
void    my_error_unsetenv(t_my_var *, char **);
void    update_env(t_my_var *);
int     my_error_setenv2(t_my_var *, char **);

/* init_var.c */
char	**init_var();

/* var.c */
int     test_cmd_var(t_my_var *, char **);
void    my_error_setvar(t_my_var *, char **);
int     my_error_setvar2(t_my_var *, char **);
void    my_error_unsetvar(t_my_var *, char **);
int	get_first_equal(char *);

/* my_setvar.c */
void    my_setvar(t_my_var *, char **);
void    change_var(t_my_var *, char *, int);
void    add_var(t_my_var *, char *);

/* my_unsetvar.c */
void    my_unsetvar(t_my_var *, char **);
void    delete_var(t_my_var *, char *);
void    parse_delete_var(t_my_var *, char **, int);

/* arr_var.c */
char    **cpy_arr_var(char **);
void    parse_var(char **, char **);
int     hm_many_var(char **);
int     get_index_var(char **, char *);

/* get_var.c */
int     check_var(t_my_var *, char **);
char    *get_var(t_my_var *, char *);
char    *get_var_str(char **, int);

/* cmd.c */
int     test_cmd_builtin(t_my_var *, char **);
int     test_cmd_path(t_my_var *, char **);

/* my_exec.c */
void    my_exec(char *, char **, t_my_var *);
void    check_child_status2(int, int, t_my_var *);
void    check_child_status(int, t_my_var *);

/* func.c */
int     my_strncmp(char *, char *, int);
int     my_str_is_num(char *);
int     my_strlen(char *);
int     is_there_a_slash(char *);
int     my_str_is_alpha(char *);

/* func2.c */
void    free_double_tab(char **);
char    *my_pathadd(char *, char *);
void    my_memset(char *, char, int);
void    my_strncpy(char *, char *, int);
void    aff_double_tab(char **);

/* func3.c */
int     is_it_num_alpha(char *);
int     hm_line_on_tab(char **);
void    free_triple_tab(char ***);
char    *my_strdup(char *);

/* path.c */
char    **get_arr_path(char **);
void    parse_path(char **, char *);
int     my_strlen_path(char *);
int     hm_path(char *);
int     get_path_index(char **);

/* exit.c */
int     test_cmd_exit(t_my_var *, char **);

#endif /* !MY_H_ */
