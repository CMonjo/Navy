/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

int init(sys_t *sys)
{
	//taille a optimiser
	sys->my_map = malloc(sizeof(char) * 500);
	sys->ennemy_map = malloc(sizeof(char) * 500);
	sys->coordone_ennemy_ship = malloc(sizeof(char) * 35);
	sys->coordone_my_ship = malloc(sizeof(char) * 35);
	sig.pid = 0;
	sig.sig1 = 0;
	sig.sig2 = 0;
	if (!sys->my_map || !sys->ennemy_map || !sys->coordone_ennemy_ship ||
	!sys->coordone_my_ship)
		return (84);
	return (0);
}
