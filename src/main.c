/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** .c
*/

#include "main.h"

int main(int ac, char **av)
{
	sys_t *sys = malloc(sizeof(sys_t));

	if (ac != 2 || init(sys) == 84)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		display_rules();
	return (0);
}
