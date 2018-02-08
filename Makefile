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
		src/game_handling/init.c \
		src/display/display_rules.c

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
