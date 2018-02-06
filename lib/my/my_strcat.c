/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** .c
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, char const *src)
{
	char *new = malloc(sizeof(char) *
	(my_strlen(dest) + my_strlen(src) + 1));

	if (!new)
		exit(EXIT_FAILURE);
	int i = 0;
	int e = 0;

	for (; dest[e] != '\0';) {
		if (dest[e] != ' ') {
			new[e] = dest[e];
			e++;
		}
	}
	for (; src[i] != '\0'; i++) {
		for (int j = 0; src[i] != ' ' && j == 0; j++, e++)
			new[e] = src[i];
	}
	new[e] = '\0';
	return (new);
}
