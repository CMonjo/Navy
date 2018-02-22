/*
** EPITECH PROJECT, 2017
** Project NaVy
** File description:
** Main file
*/

#include "main.h"

// void free_system(sys_t *sys)
// {
//
// }

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

void connection_first_player()
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

int return_winner(sys_t *sys)
{
	if (sys->hit == 14)
		return (0);
	else
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int winner = 0;
	sys_t *sys = malloc(sizeof(sys_t));

	if (av[1] != NULL && my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		display_rules();
		return (0);
	}
	set_connection(10);
	set_connection(12);
	if ((ac != 2 && ac != 3) || init(sys) == 84)
		return (84);
	//ATTENTION SETPOSITION CHECK AUSSI LA VERIF DES MAPS
	//CEPENDANT CE N'EST PAS ENCORE FONCTIONNEL
	if (set_position(sys, ac, av) == 84)
		return (84);
	connection(ac, av);
	if (map_fill(sys) == 84)
		return (84);
	if (game_loop(sys, ac) == 84)
		return (84);
	winner = return_winner(sys);
	//free_system(sys);
	return (winner);
}
