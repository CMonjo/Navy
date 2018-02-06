/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
*/

#include <unistd.h>

int		my_isneg(int n)
{
	if (n >= 0)
		write(1, "P", 1);
	else
		write(1, "N", 1);
	return (0);
}
