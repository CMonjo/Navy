/*
** EPITECH PROJECT, 2017
** Project NaVy
** File description:
** Fight file
*/

#include "main.h"

int input_error(char *str)
{
	if (my_strlen(str) != 2 || (str[0] > 'H' ||
	str[0] < 'A') || (str[1] > '9' || str[1] < '1'))
		return (1);
	return (0);
}

int check_input(void)
{
	char *str = NULL;
	int pos = 0;

	my_putstr("\nattack: ");
	str = get_next_line(0);
	if (str == NULL)
		return (84);
	for (; input_error(str) == 1;) {
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
	sys->get_hit = 1;
	sys->pos = check_input();
	if (sys->pos == 84)
		return (84);
	send_attack(sys->pos);
	my_putchar(sys->pos % 8 + 65);
	my_putchar(sys->pos / 8 + 49);
	sys->get_hit = hit_enemy();
	if (sys->ennemy_map[sys->pos] == 'x') {
		my_putstr(": missed\n");
	}
	else if (sys->get_hit == 1) {
		my_putstr(": hit\n");
		sys->hit++;
		sys->ennemy_map[sys->pos] = 'x';
	} else {
		my_putstr(": missed\n");
		sys->ennemy_map[sys->pos] = 'o';
	}
	return (0);
}

void turn_defence_map(sys_t *sys, int pos)
{
	if (sys->my_map[pos] == 'x') {
		my_putstr(": missed\n");
		kill(sig.pid, 12);
	}
	else if (sys->my_map[pos] != '.' && sys->my_map[pos] != 'o') {
		my_putstr(": hit\n");
		kill(sig.pid, 10);
		sys->en_hit++;
		sys->my_map[pos] = 'x';
	} else {
		my_putstr(": missed\n");
		kill(sig.pid, 12);
		sys->my_map[pos] = 'o';
	}
}

void turn_defence(sys_t *sys)
{
	int pos = 0;

	my_putstr("\nwaiting for enemy's attack...\n");
	pos = check_attack();
	my_putchar(pos % 8 + 65);
	my_putchar(pos / 8 + 49);
	usleep(30000);
	turn_defence_map(sys, pos);
	usleep(1000);
}
