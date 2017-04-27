/*
** redir.h for 42sh in /home/yohan/repo/PSU/PSU_2016_42sh/include
** 
** Made by Yohan.Jabin
** Login   <yohan.jabin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 27 18:36:54 2017 Yohan.Jabin
** Last update Fri Apr 28 00:31:49 2017 Yohan.Jabin
*/

#ifndef REDIR_H_
# define REDIR_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

int	my_getnbr(const char *);

/* process_arr.c */
int     parse_pipe(t_my_data *, char *);

/* process_pid.c */
void    init_arr_pid(t_my_data *);
int     *add_pid(int *, int, int);
void    wait_all_pid(t_my_data *);
void    aff_pid(t_redir);

/* check_arr_cmd.c */
int     check_arr_cmd(char **);
int     how_many_exit(char **);
void    swap_cmd(char **, int);

/* process_imp.c */
int     process_imput(t_my_data *, char ***);
void    process_imput_loop(t_my_data *, char **);

/* redirections_right.c */
int     open_redirections_right(t_my_data *, char *);
int     check_error_redirections_right(t_my_data *, char **);
int     check_for_redirections_right(t_my_data *, char ***);
int     parse_redirections_right(t_my_data *, char ***, int);

/* redirections_left.c */
int     open_redirections_left(t_my_data *, char *);
int     check_error_redirections_left(t_my_data *, char **);
int     check_for_redirections_left(t_my_data *, char ***);
int     parse_redirections_left(t_my_data *, char ***, int);

/* new_redirect_tab.c */
char    **new_redirect_tab(char **, char);

/* double_redir_left.c */
void    double_redir_left(t_my_data *, char *);

/* check_pipe_error.c */
int     check_redirection_error(t_my_data *, char ***);
int     check_for_exit_pipe(t_my_data *, char ***);

/* manip_fd.c */
void    check_fd_for_exec(t_my_data *);

/* my_exec.c */
void    my_exec(char *, char **, t_my_data *);
void    check_child_status2(int, int, t_my_data *);
void    check_child_status(int, t_my_data *);

/* arr_pipe.c */
char    **create_arr_pipe(char *);
void    parse_arr_pipe(char **, char *);
int     hm_pipe(char *);
int     my_strlen_pipe(char *);
int     is_it_only_space_pipe(char *);

/* my_setenv.c */
void    my_setenv(t_my_data *, char **);
void    change_env(t_my_data *, char *, char *, int);
void    add_env(t_my_data *, char *, char *);
char    *get_string_to_add(char *, char *);

/* my_unsetenv.c */
void    my_unsetenv(t_my_data *, char **);
void    delete_env(t_my_data *, char *);
void    parse_delete_env(t_my_data *, char **, int);

/* cd.c */
int     my_cd(t_my_data *, char **);
int     test_cd(t_my_data *, char **);
int     test_cd_old(t_my_data *, char **);
int     test_cd_home(t_my_data *, char **);
void    change_pwd(t_my_data *);

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
int     test_cmd_env(t_my_data *, char **);
void    my_error_setenv(t_my_data *, char **);
void    my_error_unsetenv(t_my_data *, char **);
void    update_env(t_my_data *);
int     my_error_setenv2(t_my_data *, char **);

/* cmd.c */
int     test_cmd_builtin(t_my_data *, char **);
int     test_cmd_path(t_my_data *, char **);

/* my_exec.c */
void    my_exec(char *, char **, t_my_data *);
void    check_child_status2(int, int, t_my_data *);
void    check_child_status(int, t_my_data *);

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

#endif /* !REDIR_H_ */
