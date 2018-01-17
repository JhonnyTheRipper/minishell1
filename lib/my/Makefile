##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

NAME	=	libmy.a

RM	=	rm -f

SRCS	=	my_printf.c	\
		printoct.c	\
		printstr.c	\
		printchar.c	\
		printdec.c	\
		printdecu.c	\
		printhex.c	\
		printbin.c	\
		printstrspe.c	\
		prtintadd.c	\
		flags.c	\
		my_strcat.c	\
		my_getnbr.c	\
		my_strcmp.c	\
		my_str_to_word_array.c	\

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) *
		$(RM) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
