/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

void print_my_map(sys_t *sys, int i)
{
	int a = i * 14 - 14 + (1 * i - 1);
	int j = i * 15;

	for (; a < j; a++)
		my_putchar(sys->my_map[a]);
	my_putchar('\n');
}

void print_ennemy_map(sys_t *sys, int i)
{
	int a = i * 14 - 14 + (1 * i - 1);
	int j = i * 15;
	for (;a < j; a++)
		my_putchar(sys->ennemy_map[a]);
	my_putchar('\n');
}

void display_maps(sys_t *sys)
{
	my_putstr("my positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 1; i != 9; i++) {
		my_put_nbr(i);
		my_putchar('|');
		print_my_map(sys, i);
	}
	my_putchar('\n');
	my_putstr("ennemy's positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 1; i != 9; i++) {
		my_put_nbr(i);
		my_putchar('|');
		print_ennemy_map(sys, i);
	}
}

void display_rules()
{
	my_putstr("USAGE\n");
	my_putstr("\t./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("first_player_pid: only for the 2nd player. pid of the ");
	my_putstr("first player.\n");
	my_putstr("navy_positions: file representing the positions of the ");
	my_putstr("ships.\n");
}
