/*
** EPITECH PROJECT, 2017
** my
** File description:
** c
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

int vmatch (struct match *sb);

int scndverif(struct match *sb, int a, char *temp);

int verif_temp(char *temp);

void pusr(struct match *sb);

int ia_reflexion(struct match *sb);

void match_rest(struct match *sb);

int verif_win(struct match *sb);

void remove_from_map(struct match *sb);

int verif_removing(struct match *sb);

void print_map(struct match *sb);

int display(struct match *sb);

int my_turn(struct match *sb);

void ai_turn(struct match *sb);

int game(struct match *sb);

void my_else(struct match *sb, int i, int a);

void printstars(struct match *sb, int i);

void init_map(struct match *sb);

char *fs_cat_x_bytes(char const *filepath, int x);

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap();

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char * my_strcpy(char *dest, char const *src);

char **my_str_to_word_array(char *str, char separator);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

#endif
