/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
*/
#include <unistd.h>
#include "../../include/my.h"

int		my_putnbr_base(int nb, char const *base)
{
	int len = my_strlen_const(base);
	int	right;
	char left;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	left = base[nb % len];
	right = nb / len;
	if (right != 0)
		my_putnbr_base(right, base);
	my_putchar(left);
	return (0);
}
