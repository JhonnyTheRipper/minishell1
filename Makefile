##
## EPITECH PROJECT, 2017
## makefile
## File description:
## 
##

NAME	=	minishell

CC	=	gcc

RM	=	rm -f

SRCS	=	minishell.c \
			list_res.c \
			lis_res_bis.c 	\
			resources.c \
			exec.c \
			res_bis.c 	\

OBJS	=	$(SRCS:.c=.o)

CFLAFS	=	-L lib/my/ -l my
CFLAGS +=	-W -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJS)
		cd lib/my && $(MAKE)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L lib/my/ -lmy -g
		$(RM) $(OBJS)
		$(RM) lib/my/libmy.a

clean:
	$(RM) $(OBJS)

tests_run :
	cd tests && $(MAKE)
fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
