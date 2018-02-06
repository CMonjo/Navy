/*
** EPITECH PROJECT, 2017
** c
** File description:
** 
*/

#include <unistd.h>
#include "my.h"

int		my_strlen_const(char const *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int		my_unsigned_putnbr_base(unsigned int nb, char const *base)
{
	int len = my_strlen_const(base);
	int	right;
	char left;

	left = base[nb % len];
	right = nb / len;
	if (right != 0)
		my_putnbr_base(right, base);
	my_putchar(left);
	return (0);
}
