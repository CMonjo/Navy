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

int main(void)
{
	int pid = getpid();
	printf("PID = %d\n", pid);
	printf("PPID = %d\n", getppid());
	printf("PGID = %d\n", getpgid(pid));
	return (0);
}
