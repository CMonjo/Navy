##
## EPITECH PROJECT, 2017
## c
## File description:
## c
##

RM	=	rm -f

CFLAGS =	-Wall -Wextra -W -I ../../include/

SRC	=	my_put_nbr.c		\
		my_putchar.c 		\
		my_putstr.c		\
		my_strlen.c		\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
fclean:
	$(RM) *.o
	$(RM) $(NAME)
