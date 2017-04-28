##
## Makefile for  in /home/hugo/Epitech/B2/PSU/PSU_2016_42sh
## 
## Made by Hugo
## Login   <hugo.martin@epitech.eu>
## 
## Started on  Fri Apr 28 15:04:57 2017 Hugo
## Last update Fri Apr 28 15:05:02 2017 Hugo
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

CURDIR = ./

TODO = -@fgrep --color --exclude=.git --exclude=*.o --exclude=Makefile --exclude=tags --exclude=cscope* -H -e TODO -e FIXME -r $(CURDIR) || true

SRCS	= ./lib/my/casual/count_char.c \
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
	  ./lib/my/my_printf/my_printf.c \
	  ./src/command/command.c \
	  ./src/echo/echo.c \
	  ./src/exec/arr_env.c \
	  ./src/exec/cd.c \
	  ./src/exec/cmd.c \
	  ./src/exec/env.c \
	  ./src/exec/func.c \
	  ./src/exec/func2.c \
	  ./src/exec/func3.c \
	  ./src/exec/my_exec.c \
	  ./src/exec/my_setenv.c \
	  ./src/exec/my_str_to_wordtab.c \
	  ./src/exec/my_unsetenv.c \
	  ./src/exec/path.c \
	  ./src/main.c \
	  ./src/prompt/histori.c \
	  ./src/prompt/my_get_commande.c \
	  ./src/prompt/my_prompt.c \
	  ./src/prompt/my_setprompt.c \
	  ./src/prompt/setup_prompt.c \
	  ./src/redir/arr_pipe.c \
	  ./src/redir/check_pipe_error.c \
	  ./src/redir/double_redir_left.c \
	  ./src/redir/new_redirect_tab.c \
	  ./src/redir/process_arr.c \
	  ./src/redir/process_imp.c \
	  ./src/redir/process_pid.c \
	  ./src/redir/redirections_left.c \
	  ./src/redir/redirections_right.c \
	  ./src/separator/separator.c \
	  ./src/setup/exit.c \
	  ./src/setup/start.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./include/
CFLAGS += -W -Wall -Wextra -g3
LDLIBS = 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	@$(TODO)

#changer le '#' de place pour les couleur ou non

clean:
	@#@echo "clean OK"
	@echo -e "\e[1;46m clean OK \e[0m"
	@$(RM) $(OBJS)

fclean:
	@#@echo "fclean OK"
	@echo -e "\e[1;46m fclean OK \e[0m"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

%.o: %.c
	@gcc -c -o $@ $(CFLAGS) $<
	@echo -e "[\e[0;32m OK \e[0m] built '$@'"

.PHONY: all clean fclean re
