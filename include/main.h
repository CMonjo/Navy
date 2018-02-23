/*
** EPITECH PROJECT, 2017
** my
** File description:
** c
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#define READ_SIZE (1)

	// INCLUDES
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <math.h>
	#include <fcntl.h>
	#include <time.h>
	#include <string.h>
	#include <signal.h>
	#include <sys/types.h>
	#include <sys/stat.h>

	// STRUCT
	typedef struct sys_s {
		char *my_map;
		char *ennemy_map;
		char *file;
		int win;
		int pos;
		int hit;
		int freturn;
		int en_hit;
		int get_hit;
	} sys_t;

	typedef struct signal_s {
		int pid;
		int sig1;
		int sig2;
	} signal_t;

	signal_t sig;

	// PROTOTYPES
	int verif_number_and_point(sys_t *sys);
	int verif_pos(sys_t *sys);
	int convert_letter(char letter);
	int set_position(sys_t *sys, int ac, char **av);
	int map_fill(sys_t *sys);
	void display_maps(sys_t *sys);
	int game_loop();
	int open_pos1();
	int open_pos2();
	void display_rules();
	int init(sys_t *sys);
	void my_putchar(char c);
	int my_put_nbr(int nb);
	int turn_attack(sys_t *sys);
	void set_connection(int pid);
	void connection(int ac, char **av);
	void turn_defence(sys_t *sys);
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	int my_getnbr(char const *str);
	char *get_next_line(int fd);
	int hit_enemy(void);
	int check_attack(void);
	void send_attack(int pos);
#endif
