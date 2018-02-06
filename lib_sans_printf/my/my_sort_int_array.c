/*
** EPITECH PROJECT, 2017
** day7
** File description:
** day7
*/

#include <unistd.h>

void	my_sort_int_array(int *tab, int size)
{
	int		stock[size];
	int		i = 0;

	while (i < size) {
		if (tab[i] > tab[i + 1] && i + 1 < size) {
			stock[i] = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = stock[i];
			i = -1;
		}
		i++;
	}
}
