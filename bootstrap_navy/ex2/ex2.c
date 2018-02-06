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

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int pid = atoi(av[1]);
	// printf("PID = %d\n", pid);
	// printf("PPID = %d\n", getppid());
	// printf("PGID = %d\n", getpgid(pid));
	printf("%d\n", kill(pid, SIGQUIT));
	return (0);
}
