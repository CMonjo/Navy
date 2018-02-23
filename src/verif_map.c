/*
** EPITECH PROJECT, 2017
** navy
** File description:
** .c
*/

#include "main.h"

int verif_all_ship(int *n1, int *n2, int *n3, int *n4)
{
	if ((n1[0] != n1[1] && n1[0] + 1 != n1[1] && n1[0] - 1 != n1[1]) ||
	(n2[0] != n2[1] && n2[0] + 2 != n2[1] && n2[0] - 2 != n2[1]) ||
	(n3[0] != n3[1] && n3[0] + 3 != n3[1] && n3[0] - 3 != n3[1]) ||
	(n4[0] != n4[1] && n4[0] + 4 != n4[1] && n4[0] - 4 != n4[1]))
	return (84);
	if ((n1[0] != n1[1] && n1[2] - 1 != n1[3]) ||
	(n2[0] != n2[1] && n2[2] - 2 != n2[3]) ||
	(n3[0] != n3[1] && n3[2] - 3 != n3[3]) ||
	(n4[0] != n4[1] && n4[2] - 4 != n4[3]))
	return (84);
	return (0);
}

int verif_number_and_point(sys_t *sys)
{
	int a = 0;

	if (sys->file[0] != '2' || sys->file[8] != '3'||
	sys->file[14] != '4' || sys->file[24] != '5')
		return (84);
	// C'EST ICI QUE LE PROGRAMME RETURN 
	for (int i = 1; i < 30;) {
		if (sys->file[i] != ':')
			return (84);
		if (a == 1) {
			i += 5;
			a = 0;
		} else if (a == 0) {
			i += 3;
			a = 1;
		}
	}
	return (0);
}

int verif_pos(sys_t *sys)
{
	int a = verif_number_and_point(sys);
	// ICI LE A RETURN 84 ??
	int n1[4] = {convert_letter(sys->file[2]),
		convert_letter(sys->file[5]),
		sys->file[3] - 47, sys->file[6] - 48};
	int n2[4] = {convert_letter(sys->file[10]),
		convert_letter(sys->file[13]),
		sys->file[11] - 46, sys->file[14] - 48};
	int n3[4] = {convert_letter(sys->file[18]),
		convert_letter(sys->file[21]),
		sys->file[19] - 45, sys->file[22] - 48};
	int n4[4] = {convert_letter(sys->file[26]),
		convert_letter(sys->file[29]),
		sys->file[27] - 44, sys->file[30] - 48};

	if ((n1[0] == n1[1] && n1[2] != n1[3]) ||
	(n2[0] == n2[1] && n2[2] != n2[3]) || (n3[0] == n3[1] && n3[2] != n3[3])
	|| (n4[0] == n4[1] && n4[2] != n4[3]) || a == 84)
		return (84);
	a = verif_all_ship(n1, n2, n3, n4);
	return (a);
}
