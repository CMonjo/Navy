/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
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

void check_winner_lose(sys_t *sys, int ac)
{
	if (sys->en_hit == 14 && ac == 3) {
		display_maps(sys);
		my_putstr("\nEnemy won\n");
		sys->win = 1;
	}
	else if (sys->en_hit == 14 && ac == 2) {
		display_maps(sys);

		my_putstr("\nEnemy won\n");
		sys->win = 1;
	}
}

int check_winner_win(sys_t *sys, int ac)
{
	if (sys->hit == 14 && ac == 3) {
		display_maps(sys);
		my_putstr("\nI won\n");
		sys->win = 0;
	}
	else if (sys->hit == 14 && ac == 2) {
		display_maps(sys);
		my_putstr("\nI won\n");
		sys->win = 0;
	} else
		check_winner_lose(sys, ac);
	if (sys->win == 0 || sys->win == 1)
		return (1);
	return (0);
}

int player_one(sys_t *sys, int ac)
{
	for (; turn_attack(sys) == 84;)
		return (84);
	if (check_winner_win(sys, ac) == 1)
		return (1);
	turn_defence(sys);
	if (check_winner_win(sys, ac) == 1)
		return (1);
	return (0);
}

int player_two(sys_t *sys, int ac)
{
	turn_defence(sys);
	if (check_winner_win(sys, ac) == 1)
		return (1);
	for (; turn_attack(sys) == 84;)
		return (84);
	if (check_winner_win(sys, ac) == 1)
		return (1);
	return (0);
}

int game_loop(sys_t *sys, int ac)
{
	int val_return = 0;

	sig.sig1 = 0;
	sig.sig2 = 0;
	sys->hit = 12;
	sys->en_hit = 12;
	while (sys->win == 2) {
		display_maps(sys);
		if (ac == 3) {
			sys->freturn = player_two(sys, ac);
			val_return = (sys->freturn != 0) ? 1 : 0;
		} else {
			sys->freturn = player_one(sys, ac);
			val_return = (sys->freturn != 0) ? 1 : 0;
		}
		if (val_return != 0)
			return (val_return);
	}
	return (0);
}
