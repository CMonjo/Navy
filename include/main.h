/*
** EPITECH PROJECT, 2017
** my
** File description:
** c
*/

#ifndef MAIN_H_
	#define MAIN_H_

	// INCLUDES

	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <math.h>
	#include <fcntl.h>
	#include <time.h>
	#include <signal.h>

	// STRUCT

	typedef struct sys_s {
		char *my_map;
		char *ennemy_map;
		char *coordone_my_ship;
		char *coordone_ennemy_ship;
		int win;
	} sys_t;

	typedef struct signal_s {
		int pid;
		int sig1;
		int sig2;
	} signal_t;

	signal_t sig;

	// PROTOTYPES

	int verif_pos1(sys_t *sys);
	int verif_pos2(sys_t *sys);
	int convert_letter(char letter);
	int set_position(sys_t *sys, int ac, char **av);
	void map_fill(sys_t *sys);
	void display_maps(sys_t *sys);
	void game_loop(sys_t *sys);
	int open_pos1();
	int open_pos2();
	void display_rules();
	int init(sys_t *sys);
	int malloc_my_map(sys_t *sys);
	int malloc_ennemys_map(sys_t *sys);
	void my_putchar(char c);
	int my_isneg(int nb);
	int my_put_nbr(int nb);
	void my_swap();
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	int my_getnbr(char const *str);
	char **my_str_to_word_array(char *str, char separator);
	char *my_strncpy(char *dest, char const *src, int n);
	char *my_revstr(char *str);
	int my_strcmp(char const *s1, char const *s2);
	char *my_strcat(char *dest, char const *src);

#endif
