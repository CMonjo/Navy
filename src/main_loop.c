/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"
#include "get_next_line.h"

// void my_attack(sys_t *sys)
// {
// 	my_putstr("\nattack: ");
// 	char *hit = get_next_line(0);
// 	// if (hit == NULL)
// 	// 	exit (84);
//
// 	while (convert_letter(hit[0]) > 7 || sys->ennemy_map[(hit[1] - 48) *
// 	15 - 15 + convert_letter(hit[0])] == 'x' ||
// 	hit[1] - 48 < 0 || hit[1] - 48 > 9) {
// 		my_putstr("wrong position\nattack: ");
// 		hit = get_next_line(0);
// 		// if (hit == NULL)
// 		// 	exit (84);
//
// 	}
// 	my_putstr(hit);
// 	if (sys->ennemy_map[(hit[1] - 48) * 15 - 15 + (convert_letter(hit[0]) * 2)]
// 	== '.')
// 		my_putstr(": missed\n\n"); //how many \n ?
// 	else
// 		my_putstr(": hit\n\n");
// 	sys->ennemy_map[(hit[1] - 48) * 15 - 15 +
// 	convert_letter(hit[0]) * 2] = 'x';
// }

// void my_defence(sys_t *sys)
// {
	//my_putstr("waiting for ennemy's attack... \n");
	// my_putstr("attack: ");
	// char *hit = get_next_line(0);
	// if (hit == NULL)
	// 	exit (84);
	// while (convert_letter(hit[0]) > 7 || sys->my_map[(hit[1] - 48) *
	// 15 - 15 + convert_letter(hit[0])] == 'x' ||
	// hit[1] - 48 < 0 || hit[1] - 48 > 9) {
	// 	my_putstr("wrong position\nattack: ");
	// 	hit = get_next_line(0);
	// 	// if (hit == NULL)
	// 	// 	exit (84);
	// }
	// my_putstr(hit);
	// if (sys->my_map[(hit[1] - 48) * 15 - 15 + (convert_letter(hit[0]) * 2)]
	// == '.')
	// 	my_putstr(": missed\n\n");
	// else
	// 	my_putstr(": hit\n\n");
	// sys->my_map[(hit[1] - 48) * 15 - 15 +
	// convert_letter(hit[0]) * 2] = 'x';
//}

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

void modified_pos_sys(sys_t *sys)
{
	int i = 0;
	int nb_backslash = 0;

	while (i <= sys->pos * 2) {
		if (sys->ennemy_map[i] != ' ' && sys->ennemy_map[i + 1] != ' ')
			nb_backslash++;
		i++;
	}
	sys->pos = sys->pos * 2 - nb_backslash;
}

int modified_pos_ennemy(sys_t *sys, int pos)
{
	int i = 0;
	int nb_backslash = 0;

	while (i <= pos * 2) {
		if (sys->ennemy_map[i] != ' ' && sys->ennemy_map[i + 1] != ' ')
			nb_backslash++;
		i++;
	}
	pos = pos * 2 - nb_backslash;
	return (pos);
}

int get_pos(void)
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

void reset_sig()
{
	sig.sig1 = 0;
	sig.sig2 = 0;
}

void send_attack(int pos)
{
	usleep(30000);
	for (int i = 0; i < pos / 8; i++) {
		kill(sig.pid, 10);
		usleep(1000);
	}
	kill(sig.pid, 12);
	usleep(1000);
	for (int i = 0; i < pos % 8; i++) {
		kill(sig.pid, 10);
		usleep(1000);
	}
	kill(sig.pid, 12);
	usleep(1000);
}

int hit_enemy(void)
{
	int hit = 1;

	pause();
	if (sig.sig2 == 1)
		hit = 0;
	reset_sig();
	return (hit);
}

int turn_attack(sys_t *sys)
{
	int hit = 1;

	sys->pos = get_pos();
	send_attack(sys->pos);
	my_putchar(sys->pos % 8 + 65);
	my_putchar(sys->pos / 8 + 49);
	modified_pos_sys(sys);

	hit = hit_enemy();
	if (hit == 1) {
		my_putstr(": hit\n\n");
		sys->hit++;
		sys->ennemy_map[sys->pos] = 'x';
	} else {
		my_putstr(": missed\n\n");
		sys->ennemy_map[sys->pos] = 'o';
	}
	return (0);
}

int check_attack(void)
{
	int pos = 0;

	while (sig.sig2 == 0);
	pos = sig.sig1 * 8;
	reset_sig();
	while (sig.sig2 == 0);
	pos += sig.sig1;
	reset_sig();
	return (pos);
}

void turn_defence(sys_t *sys)
{
	int pos = 0;

	my_putstr("\nwaiting for enemy's attack...\n");
	pos = check_attack();
	my_putchar(pos % 8 + 65);
	my_putchar(pos / 8 + 49);
	pos = modified_pos_ennemy(sys, pos);
	usleep(30000);
	if (sys->my_map[pos] != '.') {
		my_putstr(": hit\n\n");
		kill(sig.pid, 10);
		sys->my_map[pos] = 'x';
	} else {
		my_putstr(": missed\n\n");
		kill(sig.pid, 12);
		sys->my_map[pos] = 'o';
	}
	usleep(1000);
}

int game_loop(sys_t *sys, int ac)
{
	sys->win = 2;
	reset_sig();
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
