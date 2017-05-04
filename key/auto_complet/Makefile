##
## Makefile for  in /home/khazixismywaifu/Documents/Epitech/TEK1/B2/PSU_2016_42sh/key/auto_complet/
##
## Made by Camille Gouneau
## Login   <camille.gouneau@epitech.eu>
##
## Started on  Tue May  2 11:00:13 2017 Camille Gouneau
## Last update Wed May  3 16:58:20 2017 Camille Gouneau
##

SRCLIB 		=	main.c								\
						lib/gnl.c							\
						lib/auto_complet.c		\
						lib/string.c					\
						lib/str_to_word_tab.c	\
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
