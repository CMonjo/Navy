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

int main(int ac, char **av)
{
	int winner = 0;
	sys_t *sys = malloc(sizeof(sys_t));

	if (av[1] != NULL && my_strlen(av[1]) == 2 && av[1][0]
	== '-' && av[1][1] == 'h') {
		display_rules();
		return (0);
	}
	else if (ac != 1 || ac != 2 ||init(sys) == 84)
		return (84);
	else if (open_pos(sys, av[1], av[2]) == 84)
		return (84);
	map_fill(sys);
	game_loop(sys);
	winner = sys->win;
	//free_system(sys);
	return (winner);
}
