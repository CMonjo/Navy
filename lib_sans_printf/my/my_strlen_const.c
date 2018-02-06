/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
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
