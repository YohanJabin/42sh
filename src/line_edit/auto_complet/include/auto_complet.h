/*
** auto_complet.h for  in PSU_2016_42sh/key/auto_complet/include/
**
** Made by Camille Gouneau
** Login   <camille.gouneau@epitech.eu>
**
** Started on  Tue May  2 10:54:32 2017 Camille Gouneau
** Last update Sun May 14 16:34:04 2017 Camille Gouneau
*/

#ifndef AUTO_COMPLET_H_
  #define AUTO_COMPLET_H_

  extern char **environ;

  typedef struct s_my_auto
  {
    int i;
    int nothing;
    char  **auto_list;
  } t_my_auto;

  void  *my_malloc(int size);
  int   my_strlen(char *str);
  char  *get_next_line(int fd);
  char  *get_next_line_2(int fd);
  char  *my_realloc(char *str);
  int   my_strncmp(char *src, char *comp, int nbr);
  char  **my_realloc_star(char **str);
  int   vs(char **tab);
  void  my_fput(char *str, int fd);
  void  auto_complet(char *str);
  void  auto_complet_param(char *str, t_my_auto *p);
  void  auto_complet_command(char *str, t_my_auto *p, char **path);
  int   find_space(char *str);
  int   my_strlen(char *str);
  char  **create_path();
  char  *remove_path(char *str, char *to_remove);
  void  auto_dir(char *str, char *dir, t_my_auto *p);
  char  **str_to_word_tab(char *str, char separator);
  void  layout(char *str);
  char  *my_put_in_char(char *dest, char *src);
  void  my_free_struct(t_my_auto *p);
  char  **my_memset(char **tab);
  void  free_path(char **path);
  int   my_free_struct_2(t_my_auto *p);
  void  aff_auto_list(t_my_auto *p);
  void  cd_param(char *str, char *dir, t_my_auto  *p);
  char  *remove_space(char *str);
  void  make_param(char *str, t_my_auto *p);
  char  *get_space(char *str);

#endif /* AUTO_COMPLET_H_ */
