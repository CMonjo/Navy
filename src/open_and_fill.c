/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

int open_pos2(sys_t *sys, char *pos2)
{
	int fd_pos2 = open(pos2, O_RDONLY);
	int rd_pos2 = 0;

	if (fd_pos2 < 0)
		return (84);
	rd_pos2 = read(fd_pos2, sys->coordone_my_ship, 35);
	close(fd_pos2);
	if (rd_pos2 < 0)
		return (84);
	return (0);
}

int open_pos1(sys_t *sys, char *pos1)
{
	int fd_pos1 = open(pos1, O_RDONLY);
	int rd_pos1 = 0;

	if (fd_pos1 < 0)
		return (84);
	rd_pos1 = read(fd_pos1, sys->coordone_my_ship, 35);
	close(fd_pos1);
	if (rd_pos1 < 0)
		return (84);
	return (0);
}

int set_position(sys_t *sys, int ac, char **av)
{
	if (ac == 2) {
		if (open_pos1(sys, av[1]) == 84 || verif_pos1(sys) == 84)
			return (84);
	} else {
		if (open_pos2(sys, av[2]) == 84)
			return (84);
	}
	return (0);
}

int placement_ship_in_map(sys_t *sys, int i)
{
	static int nb = 2;
	int x1 = convert_letter(sys->coordone_my_ship[i]);
	int y1 = sys->coordone_my_ship[i + 1] - '0' - 1;
	int x2 = convert_letter(sys->coordone_my_ship[i + 3]);
	int y2 = sys->coordone_my_ship[i + 4] - '0' - 1;

	if (sys->my_map[(y1 * 8) + x1] != '.' || sys->my_map[y2 * 8 + x2] != '.') {
		return (84);
	}
	sys->my_map[(y1 * 8) + x1] = nb + 48;
	sys->my_map[y2 * 8 + x2] = nb + 48;
	for (;nb > 2 && x1 < x2; x1 += 1) {
		sys->my_map[(y1 * 8) + x1] = nb + 48;
	}
	for (;nb > 2 && y1 < y2; y1 += 1) {
		sys->my_map[(y1 * 8) + x1] = nb + 48;
	}
	nb += 1;
	return (0);
}

int map_fill(sys_t *sys)
{
	int i = 0;
	int r = 0;

	for (i = 0; i < 64; i++) {
		sys->my_map[i] = '.';
		sys->ennemy_map[i] = '.';
	}
	for (int i = 2; i < 30 && r == 0; i += 8) {
		r = placement_ship_in_map(sys, i);
		printf("r = %d\n", r);
	}
	return (r);
}
