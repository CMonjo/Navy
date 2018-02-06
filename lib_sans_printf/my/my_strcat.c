/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** c
*/

#include <stdlib.h>

int		my_strlen(char const *str);

char	*my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = my_strlen(dest);

	while (src[i] != '\0') {
		dest[i + j] = src[i];
		i += 1;
	}
	dest[j + i] = '\0';
	return (dest);
}
