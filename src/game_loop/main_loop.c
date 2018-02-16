/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"
#include "get_next_line.h"

void my_attak(sys_t *sys)
{
	my_putstr("attack: ");
	char *hit = get_next_line(0);
	// if (hit == NULL)
	// 	exit (84);

	while (convert_letter(hit[0]) > 7 || sys->ennemy_map[(hit[1] - 48) *
	15 - 15 + convert_letter(hit[0])] == 'x' ||
	hit[1] - 48 < 0 || hit[1] - 48 > 9) {
		my_putstr("wrong position\nattack: ");
		hit = get_next_line(0);
		// if (hit == NULL)
		// 	exit (84);

	}
	my_putstr(hit);
	if (sys->ennemy_map[(hit[1] - 48) * 15 - 15 + (convert_letter(hit[0]) * 2)]
	== '.')
		my_putstr(": missed\n\n\n"); //how many \n ?
	else
		my_putstr(": hit\n\n\n");
	sys->ennemy_map[(hit[1] - 48) * 15 - 15 +
	convert_letter(hit[0]) * 2] = 'x';
}

void ennemy_attack(sys_t *sys)
{
	my_putstr("waiting for ennemy's attack... \n");
	my_putstr("attack: ");
	char *hit = get_next_line(0);
	// if (hit == NULL)
	// 	exit (84);
	while (convert_letter(hit[0]) > 7 || sys->my_map[(hit[1] - 48) *
	15 - 15 + convert_letter(hit[0])] == 'x' ||
	hit[1] - 48 < 0 || hit[1] - 48 > 9) {
		my_putstr("wrong position\nattack: ");
		hit = get_next_line(0);
		// if (hit == NULL)
		// 	exit (84);
	}
	my_putstr(hit);
	if (sys->my_map[(hit[1] - 48) * 15 - 15 + (convert_letter(hit[0]) * 2)]
	== '.')
		my_putstr(": missed\n\n");
	else
		my_putstr(": hit\n\n");
	sys->my_map[(hit[1] - 48) * 15 - 15 +
	convert_letter(hit[0]) * 2] = 'x';
}

void game_loop(sys_t *sys)
{
	sys->win = 2;
	while (sys->win == 2) {
		display_maps(sys);
		my_attak(sys);
		display_maps(sys);
		ennemy_attack(sys);
	}

}
