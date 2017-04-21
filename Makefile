NAME	= 42sh

CC	= gcc

RM	= rm -f

CURDIR = ./

TODO = -@fgrep --color --exclude=.git --exclude=*.o --exclude=Makefile --exclude=tags --exclude=cscope* -H -e TODO -e FIXME -r $(CURDIR) || true

SRCS	= ./lib/my/casual/epur.c \
	  ./lib/my/casual/get_next_line.c \
	  ./lib/my/casual/line_formatting.c \
	  ./lib/my/casual/manip_chaine.c \
	  ./lib/my/casual/my_clean.c \
	  ./lib/my/casual/my_getnbr.c \
	  ./lib/my/casual/my_malloc.c \
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
	  ./lib/my/my_fprintf/my_putchar.c \
	  ./lib/my/my_fprintf/my_putstr.c \
	  ./lib/my/my_fprintf/my_revstr.c \
	  ./lib/my/my_printf/my_printf.c \
	  ./src/command/command.c \
	  ./src/echo/echo.c \
	  ./src/exit.c \
	  ./src/main.c \
	  ./src/prompt/histori.c \
	  ./src/prompt/my_get_commande.c \
	  ./src/prompt/my_prompt.c \
	  ./src/prompt/my_setprompt.c \
	  ./src/prompt/setup_prompt.c \
	  ./src/start.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./include/
CFLAGS += -W -Wall -Wextra -Werror -g -g3
LDLIBS =

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	@$(TODO)

#changer le '#' de place pour les couleur ou non

clean:
	@#@echo "clean OK"
	@echo -e "\033[1;46m clean OK \033[0m"
	@$(RM) $(OBJS)

fclean:
	@#@echo "fclean OK"
	@echo -e "\033[1;46m fclean OK \033[0m"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

%.o: %.c
	@gcc -c -o $@ $(CFLAGS) $<
	@echo -e "[\033[0;32m OK \033[0m] built '$@'"

.PHONY: all clean fclean re
