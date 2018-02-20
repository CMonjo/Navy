/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

int input_error(char *str)
{
	if (my_strlen(str) != 2)
		return (84);
	if (str[0] > 'H' || str[0] < 'A')
		return (84);
	if (str[1] > '9' || str[1] < '1')
		return (84);
	return (0);
}

int check_input()
{
	char *str = NULL;
	int pos = 0;

	my_putstr("\nattack: ");
	str = get_next_line(0);
	if (str == NULL)
		return (84);
	for (; input_error(str) == 84;) {
		free(str);
		my_putstr("wrong position\n");
		my_putstr("attack: ");
		str = get_next_line(0);
	}
	pos = (str[1] - 49) * 8 + str[0] - 65;
	free(str);
	return (pos);
}

int turn_attack(sys_t *sys)
{
	int hit = 1;

	sys->pos = 0;
	sys->pos = check_input();
	send_attack(sys->pos);
	my_putchar(sys->pos % 8 + 65);
	my_putchar(sys->pos / 8 + 49);
	hit = hit_enemy();
	if (hit == 1) {
		my_putstr(": hit1\n");
		sys->hit++;
		sys->ennemy_map[sys->pos] = 'x';
	} else {
		my_putstr(": missed1\n");
		sys->ennemy_map[sys->pos] = 'o';
	}
	return (0);
}

void turn_defence(sys_t *sys)
{
	int pos = 0;

	my_putstr("\nwaiting for enemy's attack...\n");
	pos = check_attack();
	my_putchar(pos % 8 + 65);
	my_putchar(pos / 8 + 49);
	usleep(30000);
	if (sys->my_map[pos] != '.') {
		my_putstr(": hit2\n");
		kill(sig.pid, 10);
		sys->my_map[pos] = 'x';
	} else {
		my_putstr(": missed2\n");
		kill(sig.pid, 12);
		sys->my_map[pos] = 'o';
	}
	usleep(1000);
}

int game_loop(sys_t *sys, int ac)
{
	sys->win = 2;
	sig.sig1 = 0;
	sig.sig2 = 0;
	while (sys->win == 2) {
		display_maps(sys);
		if (ac == 3) {
			turn_defence(sys);
			if (turn_attack(sys) == 84)
				return (84);
		} else {
			if (turn_attack(sys) == 84)
				return (84);
			turn_defence(sys);
		}
	}
	return (0);
}
