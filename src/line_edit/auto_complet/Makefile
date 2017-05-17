##
## Makefile for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/
##
## Made by Camille Gouneau
## Login   <camille.gouneau@epitech.eu>
##
## Started on  Tue May  2 11:00:13 2017 Camille Gouneau
## Last update Thu May 11 19:59:23 2017 Camille Gouneau
##

SRCLIB 		=	main.c											\
						lib/gnl.c										\
						lib/auto_complet.c					\
						lib/auto_complet_command.c 	\
						lib/auto_complet_param.c 		\
						lib/base_command.c					\
						lib/string.c								\
						lib/string2.c								\
						lib/string3.c								\
						lib/str_to_word_tab.c				\
						lib/path_handle.c

OBJLIB 		=	$(SRCLIB:.c=.o);

NAME 			=	auto_test

NAMELIB 	= libacomp.a

LFLAGS		= -lacomp -L./

CFLAGS		= -g -W -Wall -Wextra -Iinclude

all: $(NAME)

$(NAME): 	$(OBJLIB)
					ar rc $(NAMELIB) $(OBJLIB)
					gcc -o $(NAME) $(CFLAGS) $(LFLAGS)

clean:
					rm -f $(OBJLIB)

fclean: 	clean
					rm -f $(NAME) $(NAMELIB)

re: 			fclean all

.PHONY: 	all clean fclean re
