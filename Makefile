##
## Makefile for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
##
## Made by Hugo
## Login   <hugo.martin@epitech.eu>
##
## Started on  Fri May 19 17:59:31 2017 Hugo
## Last update Fri May 19 17:59:31 2017 Hugo
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

CURDIR = ./

TODO = -@fgrep --color --exclude=.git --exclude=*.o --exclude=Makefile --exclude=tags --exclude=cscope* -H -e TODO -e FIXME -r $(CURDIR) || true

SRCS	= ./src/builtins/aff_var_alias.c \
	  ./src/builtins/alias/alias.c \
	  ./src/builtins/alias/arr_alias.c \
	  ./src/builtins/alias/my_setalias.c \
	  ./src/builtins/alias/my_unsetalias.c \
	  ./src/builtins/cd.c \
	  ./src/builtins/echo.c \
	  ./src/builtins/env/arr_env.c \
	  ./src/builtins/env/env.c \
	  ./src/builtins/env/my_setenv.c \
	  ./src/builtins/env/my_unsetenv.c \
	  ./src/builtins/exit.c \
	  ./src/builtins/var/arr_var.c \
	  ./src/builtins/var/get_var.c \
	  ./src/builtins/var/my_setvar.c \
	  ./src/builtins/var/my_unsetvar.c \
	  ./src/builtins/var/var.c \
	  ./src/builtins/which.c \
	  ./src/command/command.c \
	  ./src/command/comments.c \
	  ./src/echo/echo.c \
	  ./src/exec/arr_pipe.c \
	  ./src/exec/check_pipe_error.c \
	  ./src/exec/cmd.c \
	  ./src/exec/my_exec.c \
	  ./src/exec/my_str_to_wordtab.c \
	  ./src/exec/path.c \
	  ./src/exec/process_arr.c \
	  ./src/exec/process_imp.c \
	  ./src/exec/process_pid.c \
	  ./src/formatting/globbing/arr_star.c \
	  ./src/formatting/globbing/globbing.c \
	  ./src/formatting/globbing/globbing_error.c \
	  ./src/formatting/globbing/globbing_manip.c \
	  ./src/formatting/line_formatting.c \
	  ./src/formatting/tab_formatting.c \
	  ./src/main.c \
	  ./src/prompt/histori.c \
	  ./src/prompt/my_prompt.c \
	  ./src/prompt/my_setprompt.c \
	  ./src/prompt/setup_prompt.c \
	  ./src/redir/double_redir_left.c \
	  ./src/redir/new_redirect_tab.c \
	  ./src/redir/redirections_left.c \
	  ./src/redir/redirections_right.c \
	  ./src/repeat/repeat.c \
	  ./src/scripting/foreach.c \
	  ./src/scripting/if.c \
	  ./src/scripting/process_foreach.c \
	  ./src/scripting/process_if.c \
	  ./src/scripting/scripting.c \
	  ./src/separator/separator.c \
	  ./src/setup/exit.c \
	  ./src/setup/init_var.c \
	  ./src/setup/start.c \
	  ./src/to_sort/func.c \
	  ./src/to_sort/func2.c \
	  ./src/to_sort/func3.c \
	  ./src/utils/my_stradd.c \
	  ./src/utils/my_strcut.c

LIB		=	./lib/my/casual/count_char.c \
	  ./lib/my/casual/epur.c \
	  ./lib/my/casual/get_arg.c \
	  ./lib/my/casual/get_next_line.c \
	  ./lib/my/casual/line_formatting.c \
	  ./lib/my/casual/manip_chaine.c \
	  ./lib/my/casual/my_clean.c \
	  ./lib/my/casual/my_getnbr.c \
	  ./lib/my/casual/my_malloc.c \
	  ./lib/my/casual/my_strcat.c \
	  ./lib/my/casual/my_strcmp.c \
	  ./lib/my/casual/my_strncmp.c \
	  ./lib/my/casual/str_to_tab.c \
	  ./lib/my/list/add.c \
	  ./lib/my/list/other.c \
	  ./lib/my/list/rm.c \
	  ./lib/my/my_fprintf/functions.c \
	  ./lib/my/my_fprintf/my_fprintf.c \
	  ./lib/my/my_fprintf/my_hexa.c \
	  ./lib/my/my_fprintf/my_put_nbr.c \
	  ./lib/my/my_fprintf/my_put_tab.c \
	  ./lib/my/my_fprintf/my_putchar.c \
	  ./lib/my/my_fprintf/my_putstr.c \
	  ./lib/my/my_fprintf/my_revstr.c \
	  ./lib/my/my_printf/my_printf.c

OBJS	= $(SRCS:.c=.o) $(LIB:.c=.o)

CFLAGS = -I./include/
CFLAGS += -W -Wall -Wextra
LDLIBS = -Llib/my -lmy

all: $(NAME)

$(NAME): $(OBJS)
	ar rc lib/my/libmy.a $(LIB_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	@$(TODO)

#changer le '#' de place pour les couleur ou non

clean:
	@#@echo "clean OK"
	@echo -e "\e[1;46m clean OK \e[0m"
	@$(RM) lib/my/libmy.a
	@$(RM) $(OBJS)

fclean:
	@#@echo "fclean OK"
	@echo -e "\e[1;46m fclean OK \e[0m"
	@$(RM) $(OBJS)
	@$(RM) lib/my/libmy.a
	@$(RM) $(NAME)

re: fclean all

%.o: %.c
	@gcc -c -o $@ $(CFLAGS) $<
	@echo -e "[\e[0;32m OK \e[0m] built '$@'"

.PHONY: all clean fclean re
