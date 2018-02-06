/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** .c
*/
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int ac, char **av)
{
	struct sigaction sb;
	if (ac >= 2) {
		if (atoi(av[1]) == 10)
         		sigaction(SIGUSR1, &sb, NULL);
		else if (atoi(av[1]) == 12)
			sigaction(SIGUSR1, &sb, NULL);
	}
	if (ac == 3) {
		if (atoi(av[2]) == 10)
			sigaction(SIGUSR2, &sb, NULL);
		else if (atoi(av[2]) == 12)
			sigaction(SIGUSR2, &sb, NULL);
	}
	while (1) {
		if ()
	}
	return (0);
}
