/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

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
