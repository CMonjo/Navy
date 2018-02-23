/*
** EPITECH PROJECT, 2017
** Project NaVy
** File description:
** Main file
*/

#include "main.h"

void free_system(sys_t *sys)
{
	free(sys->my_map);
	free(sys->ennemy_map);
	free(sys->file);
	free(sys);
}

int return_winner(sys_t *sys)
{
	if (sys->hit == 14)
		return (0);
	else
		return (1);
	return (0);
}

int start_game(sys_t *sys, int ac, char **av)
{
	if (set_position(sys, ac, av) == 84)
		return (84);
	connection(ac, av);
	if (map_fill(sys) == 84)
		return (84);
	if (game_loop(sys, ac) == 84)
		return (84);
	return (0);
}

int main(int ac, char **av)
{
	int winner = 0;
	sys_t *sys = malloc(sizeof(sys_t));

	if (av[1] != NULL && my_strlen(av[1]) == 2
	&& av[1][0] == '-' && av[1][1] == 'h') {
		display_rules();
		return (0);
	}
	set_connection(10);
	set_connection(12);
	if ((ac != 2 && ac != 3) || init(sys) == 84)
		return (84);
	if (start_game(sys, ac, av) == 84)
		return (84);
	winner = return_winner(sys);
	free_system(sys);
	return (winner);
}
