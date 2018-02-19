##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I include/

LIB	=	-L lib/my -lmy

SRC	=	src/main.c \
		src/main_loop.c \
		src/display.c \
		src/init.c \
		src/open_and_fill.c \
		src/convert_alpha_in_int.c \
		src/verif_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/my/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/
	rm -f include/*.gch

re: fclean all
