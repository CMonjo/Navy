/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** .c
*/

#include "main.h"

int malloc_ennemys_map(sys_t *sys)
{
	int j = 0;

	sys->ennemy_map = malloc(sizeof(char *) * 11);
	if (!sys->ennemy_map)
		return (84);
	for (; j < 11; j++) {
		sys->ennemy_map[j] = malloc(sizeof(char) * 18);
		if (!sys->ennemy_map[j])
			return (84);
		for (int e = 0; e <= 18; sys->ennemy_map[j][e] = '\0', e++);
	}
	sys->ennemy_map[j] = NULL;
	return (0);
}

int malloc_my_map(sys_t *sys)
{
	int j = 0;

	sys->my_map = malloc(sizeof(char *) * 11);
	if (!sys->my_map)
		return (84);
	for (; j < 11; j++) {
		sys->my_map[j] = malloc(sizeof(char) * 18);
		if (!sys->my_map[j])
			return (84);
		for (int e = 0; e <= 18; sys->my_map[j][e] = '\0', e++);
	}
	sys->my_map[j] = NULL;
	return (0);
}

int init(sys_t *sys)
{
	if (malloc_my_map(sys) == 84)
		return (84);
	if (malloc_ennemys_map(sys) == 84)
		return (84);
	return (0);
}
