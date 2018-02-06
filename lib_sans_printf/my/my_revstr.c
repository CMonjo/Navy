/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
*/

int		my_strlen(char const *str)
{
	int		i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_revstr(char *str)
{
	int		j = my_strlen(str) -1;
	char	temp = 0;
	int		i = temp;

	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}
