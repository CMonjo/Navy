##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -I include/

LIB	=	-L lib/my -lmy

SRC	=	src/main.c \
		src/game_loop/main_loop.c \
		src/tools/display.c \
		src/tools/init.c \
		src/map_handling/open_and_fill.c \
		src/tools/convert_alpha_in_int.c \
		src/map_handling/verif_map.c

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
