/*
** EPITECH PROJECT, 2017
** my_stdarg
** File description:
** my_printf_bootstrap
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "array_fonction.h"

static struct t_ptr_fonction base[12] = {
	{'c', &my_char},
	{'s', &my_string},
	{'d', &my_int},
	{'i', &my_int},
	{'o', &my_oct},
	{'u', &my_dec},
	{'x', &my_hexa},
	{'X', &my_HEXA},
	{'b', &my_bin},
	{'p', &my_adress},
	{'%', &my_modulo},
	{0, NULL}
};

int		my_printf(char *str, ...)
{
	va_list ma_list;
	int		i = 0;
	int 	a = 0;
	int compteur = 0;
	va_start(ma_list, str);

	while (str[i] != '\0') {
		if (str[i] == '%') {
			i++;
			for (; base[a].balise != 0; a++)
				str[i] == base[a].balise ? base[a].ptr(ma_list) : 0;
			a = 0;
		} else
			my_putchar (str[i]);
		i++;
		compteur++;
	}
	va_end(ma_list);
	return (compteur);
}

int main()
{
	return (0);
}
