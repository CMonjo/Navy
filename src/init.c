/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

int init(sys_t *sys)
{
	sys->my_map = malloc(sizeof(char) * 500);
	sys->ennemy_map = malloc(sizeof(char) * 500);
	sys->file = malloc(sizeof(char) * 35);
	sig.pid = 0;
	sig.sig1 = 0;
	sig.sig2 = 0;
	sys->win = 2;
	sys->hit = 0;
	sys->en_hit = 0;
	sys->freturn = 0;
	if (!sys->my_map || !sys->ennemy_map || !sys->file)
		return (84);
	return (0);
}
