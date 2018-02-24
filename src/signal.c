/*
** EPITECH PROJECT, 2017
** Project NaVy
** File description:
** Signal file
*/

#include "main.h"

void handler(int sigal, siginfo_t *info, void *ptr)
{
	(void)ptr;
	sig.pid = info->si_pid;
	sig.sig1 += (sigal == 10) ? 1 : 0;
	sig.sig2 += (sigal == 12) ? 1 : 0;
}

void connection_second_player(char **av)
{
	sig.pid =  my_getnbr(av[1]);
	usleep(10000);
	kill(sig.pid, 12);
	usleep(10000);
	my_putstr("\nsuccessfully connected\n");
}

void connection_first_player(void)
{
	my_putstr("\nwaiting for enemy connection...\n\n");
	pause();
	my_putstr("enemy connected\n");
}

void connection(int ac, char **av)
{
	my_putstr("my_pid:\t");
	my_put_nbr(getpid());
	if (ac == 2)
		connection_first_player();
	else
		connection_second_player(av);
}

void set_connection(int pid)
{
	struct sigaction action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &handler;
	sigaction(pid, &action, NULL);
}
