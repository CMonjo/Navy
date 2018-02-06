##
## EPITECH PROJECT, 2017
## c
## File description:
## c
##

RM		=	rm -f

CFLAGS = -Wall -Wextra -Werror -I ../../include/

SRC		= 	my_getnbr.c			\
			my_put_nbr.c		\
			my_putchar.c 		\
			my_putstr.c			\
			my_sort_int_array.c	\
			my_strcmp.c			\
			my_strlen.c			\
			my_strcat.c		\
			get_next_line.c		\
			my_put_nbr.c

OBJ		= 	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
fclean:
	$(RM) *.o
	$(RM) $(NAME)
