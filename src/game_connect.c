/*
** EPITECH PROJECT, 2017
** Project NaVy
** File description:
** Game connect file
*/

#include "main.h"

int check_attack(void)
{
	int pos = 0;

	while (sig.sig2 == 0);
	pos = sig.sig1 * 8;
	sig.sig1 = 0;
	sig.sig2 = 0;
	while (sig.sig2 == 0);
	pos += sig.sig1;
	sig.sig1 = 0;
	sig.sig2 = 0;
	return (pos);
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
	sig.sig1 = 0;
	sig.sig2 = 0;
	return (hit);
}
