/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

int open_pos(sys_t *sys, char *pos1, char *pos2)
{
	int fd1 = open(pos1, O_RDONLY);
	int rt1 = read(fd1, sys->coordone_my_ship, 35);
	close(fd1);
	int fd2 = open(pos2, O_RDONLY);
	int rt2 = read(fd2, sys->coordone_ennemy_ship, 35);
	close(fd2);

	if (rt1 < 0 || rt2 < 0)
		return (84);
	return (0);
}

void placement_ship_in_map(sys_t *sys, int i)
{
	static int nb = 2;

	int x1 = convert_letter(sys->coordone_my_ship[i]) * 2;
	int y1 = sys->coordone_my_ship[i + 1] - '0' - 1;
	int x2 = convert_letter(sys->coordone_my_ship[i + 3]) * 2;
	int y2 = sys->coordone_my_ship[i + 4] - '0' - 1;

	sys->my_map[(y1 * 15) + x1] = nb + 48;
	sys->my_map[y2 * 15 + x2] = nb + 48;
	for (;nb > 2 && x1 < x2; x1 += 2)
		sys->my_map[(y1 * 15) + x1] = nb + 48;
	for (;nb > 2 && y1 < y2; y1 += 1)
		sys->my_map[(y1 * 15) + x1] = nb + 48;
	nb += 1;
}

void placement_ennemy_ship_in_map(sys_t *sys, int i)
{
	static int nb = 2;

	int x1 = convert_letter(sys->coordone_ennemy_ship[i]) * 2;
	int y1 = sys->coordone_ennemy_ship[i + 1] - '0' - 1;
	int x2 = convert_letter(sys->coordone_ennemy_ship[i + 3]) * 2;
	int y2 = sys->coordone_ennemy_ship[i + 4] - '0' - 1;

	sys->ennemy_map[(y1 * 15) + x1] = nb + 48;
	sys->ennemy_map[y2 * 15 + x2] = nb + 48;
	for (;nb > 2 && x1 < x2; x1 += 2)
		sys->ennemy_map[(y1 * 15) + x1] = nb + 48;
	for (;nb > 2 && y1 < y2; y1 += 1)
		sys->ennemy_map[(y1 * 15) + x1] = nb + 48;
	nb += 1;
}

void map_fill(sys_t *sys)
{
	for (int i = 0; i != 121; i += 1) {
		if (i == 0 || sys->my_map[i - 1] == ' ' || i % 15 == 0) {
			sys->my_map[i] = '.';
			sys->ennemy_map[i] = '.';
		} else {
			sys->my_map[i] = ' ';
			sys->ennemy_map[i] = ' ';
		}
	}
	for (int i = 2; i < 30; i += 8)
		placement_ship_in_map(sys, i);
	for (int i = 2; i < 30; i += 8)
		placement_ennemy_ship_in_map(sys, i);
}
