/*
** EPITECH PROJECT, 2017
** C
** File description:
** my_swap.c
*/
void	my_putchar(char);

void	my_swap(int *a, int *b)
{
	int	c = 0;

	c = *b;
	*b = *a;
	*a = c;
}
