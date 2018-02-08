/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** .c
*/

#include "main.h"

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
