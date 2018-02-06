/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
*/

#include <unistd.h>

char	*my_strstr(char const *str, char const *to_find)
{
	int    	i = 0;
	int    	j = 0;

	while (str[i] != '\0') {
		while (str[i + j] == to_find[j]) {
			if (to_find[j + 1] == '\0')
				return (char *)(str + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
