NAME	= 42sh

CC	= gcc

RM	= rm -f

CURDIR = ./

SRC_DIR = ./src/

LIB_DIR = ./lib/my/

TODO = -@fgrep --color --exclude=.git --exclude=*.o --exclude=Makefile --exclude=tags --exclude=cscope* -H -e TODO -e FIXME -r $(CURDIR) || true

SRCS	= $(SRC_DIR)command/command.c \
	  $(SRC_DIR)echo/echo.c \
	  $(SRC_DIR)exec/arr_env.c \
	  $(SRC_DIR)exec/cd.c \
	  $(SRC_DIR)exec/cmd.c \
	  $(SRC_DIR)exec/env.c \
	  $(SRC_DIR)exec/func.c \
	  $(SRC_DIR)exec/func2.c \
	  $(SRC_DIR)exec/func3.c \
	  $(SRC_DIR)exec/my_exec.c \
	  $(SRC_DIR)exec/my_setenv.c \
	  $(SRC_DIR)exec/my_str_to_wordtab.c \
	  $(SRC_DIR)exec/my_unsetenv.c \
	  $(SRC_DIR)exec/path.c \
	  $(SRC_DIR)main.c \
	  $(SRC_DIR)prompt/histori.c \
	  $(SRC_DIR)prompt/my_prompt.c \
	  $(SRC_DIR)prompt/my_setprompt.c \
	  $(SRC_DIR)prompt/setup_prompt.c \
	  $(SRC_DIR)redir/arr_pipe.c \
	  $(SRC_DIR)redir/check_pipe_error.c \
	  $(SRC_DIR)redir/double_redir_left.c \
	  $(SRC_DIR)redir/new_redirect_tab.c \
	  $(SRC_DIR)redir/process_arr.c \
	  $(SRC_DIR)redir/process_imp.c \
	  $(SRC_DIR)redir/process_pid.c \
	  $(SRC_DIR)redir/redirections_left.c \
	  $(SRC_DIR)redir/redirections_right.c \
	  $(SRC_DIR)separator/separator.c \
	  $(SRC_DIR)setup/exit.c \
	  ./src/setup/start.c

LIB = $(LIB_DIR)casual/count_char.c \
	  $(LIB_DIR)casual/epur.c \
	  $(LIB_DIR)casual/get_arg.c \
	  $(LIB_DIR)casual/get_next_line.c \
	  $(LIB_DIR)casual/line_formatting.c \
	  $(LIB_DIR)casual/manip_chaine.c \
	  $(LIB_DIR)casual/my_clean.c \
	  $(LIB_DIR)casual/my_getnbr.c \
	  $(LIB_DIR)casual/my_malloc.c \
	  $(LIB_DIR)casual/my_strcat.c \
	  $(LIB_DIR)casual/my_strcmp.c \
	  $(LIB_DIR)casual/my_strncmp.c \
	  $(LIB_DIR)casual/str_to_tab.c \
	  $(LIB_DIR)list/add.c \
	  $(LIB_DIR)list/other.c \
	  $(LIB_DIR)list/rm.c \
	  $(LIB_DIR)my_fprintf/functions.c \
	  $(LIB_DIR)my_fprintf/my_fprintf.c \
	  $(LIB_DIR)my_fprintf/my_hexa.c \
	  $(LIB_DIR)my_fprintf/my_put_nbr.c \
	  $(LIB_DIR)my_fprintf/my_put_tab.c \
	  $(LIB_DIR)my_fprintf/my_putchar.c \
	  $(LIB_DIR)my_fprintf/my_putstr.c \
	  $(LIB_DIR)my_fprintf/my_revstr.c \
	  $(LIB_DIR)my_printf/my_printf.c

OBJS	= $(SRCS:.c=.o)

LIBS = $(LIB:.c=.o)

CFLAGS = -I./include/
CFLAGS += -W -Wall -Wextra
LDLIBS = -Llib/my -lmy

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@ar rc lib/my/libmy.a $(LIBS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	@$(TODO)

#changer le '#' de place pour les couleur ou non

clean:
	@#@echo "clean OK"
	@echo -e "\e[1;46m clean OK \e[0m"
	@$(RM) $(OBJS)
	@$(RM) $(LIBS)
	@$(RM) ./libmy.a

fclean:
	@#@echo "fclean OK"
	@echo -e "\e[1;46m fclean OK \e[0m"
	@$(RM) $(OBJS)
	@$(RM) $(LIBS)
	@$(RM) $(NAME)
	@$(RM) ./libmy.a

re: fclean all

%.o: %.c
	@gcc -c -o $@ $(CFLAGS) $<
	@echo -e "[\e[0;32m OK \e[0m] built '$@'"

.PHONY: all clean fclean re
