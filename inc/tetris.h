/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** tetris.h
*/

#ifndef TETRIS_H_
    #define TETRIS_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <ncurses.h>
    #include <curses.h>
    #include <getopt.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <stdint.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include "my.h"
    #include <time.h>

typedef struct vector vector;
struct vector {
    int x;
    int y;
};

typedef struct flags flags;
struct flags {
    int level;
    int score;
    int hs;
    time_t time;
    int timebase;
    int line;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    vector size;
    int next;
    int debug;
    int combo;
    int pause_id;
};

typedef struct piece {
    int **map;
    int rotate;
    int error;
    int color;
    char *name;
    vector pos;
    vector size;
    struct piece *next;
    vector add;
} piece_t;

int tetris(int argc, char **argv);
int display_part5 (flags *f, piece_t *p);
void read_help (char *bin);

int my_nbrcmp(char *str10, char *str20);
piece_t *alphabetical_sort (piece_t *p);

void free_array (void **array);
int is_nbr (char *str);
char **file_str (char *file_name);
int nbr_of_files (char *dir_name);
int is_in (char *str, char const *to_find, int i);
char *my_strstr(char *str, char const *to_find);
void set_flag2 (flags *f, char opt, char *val);
void set_flag3 (char opt, char *bin);

char **my_ls (char *dir_name);

int is_finished2 (char *map, int i);
int my_strlen2 (char *str);
int display_part1 (flags *f, piece_t *p);
int display_part2 (flags *f, piece_t *p);
int display_part3 (flags *f, piece_t *p);
int display_part4 (flags *f, piece_t *p);
int display_default_key (int i);
int is_finished (int *map, int len, int i);

flags *setup_flags (int argc, char **argv);
void set_flag (flags *f, char opt, char *val, char *bin);
void default_flags (flags *f);

piece_t *get_piece (char **map);
piece_t *link_all_piece (char **files);
int fill_map (piece_t *new, char **map, int nbr);

int get_item_end(const char *str, char sep);
char *my_strncpy(char *dest, const char *src, size_t n);
char **my_2d_array_str_split(const char *str, char sep);
int my_item_count(const char *str, char sep);
char *my_strndup(const char *src, size_t n);

int **add_on_map(int **map, piece_t *p, flags *f);
void transp(piece_t *p, flags *f);
void game_over(flags *f, piece_t *p, int **map);
int check_coli(flags *f, piece_t *p, int ***map);

int graph(flags *f, piece_t *p);
void my_swap(int *a, int *b);

void drop(flags *f, int **map, piece_t *p);
int move_side(flags *f, piece_t *p, int act, int **map);
int check_left_side(flags *f, piece_t *p, int **map);
int check_right_side(flags *f, piece_t *p, int **map);
void game_over(flags *f, piece_t *p, int **map);
int check_line(flags *f, piece_t *p, int **map);
void add_score(flags *f, int combo);
void print_hud(flags *f, piece_t *p);
int clear_line(flags * f, int ***map, int n);
int my_rand (int min, int max);
void clean_rotate(piece_t *p, flags *f);
piece_t *get_random_piece (piece_t *p, piece_t *tmp);
int **printw_pieces(piece_t *p, int **map, flags *f);
int **printw_next(piece_t *p, int **map, flags *f);
void printw_map(int **map, piece_t *p, flags *f);
int **add_on_map(int **map, piece_t *p, flags *f);
void print_all_pieces(piece_t *p);
int **malloc_for_trans(int x, int y);
void check_in_range(piece_t *p, flags *f);
void transp(piece_t *p, flags *f);
int check_coli(flags *f, piece_t *p, int ***map);
int **init_graph (flags *f, piece_t *p);
int printw_all (piece_t *p, flags *f, piece_t *tmp, int **map);
piece_t *graph_cs (piece_t *p, piece_t *tmp, flags *f, int **map);
int **add_on_map2(int **map, piece_t *p, int i, int j);
int **add_on_map3(int **map, piece_t *p, int i, int j);
void printw_map2(int **map, int i, int j);
int the_clear(flags *f, piece_t *p, int **map, int i);
int check_coli_cs(flags *f, piece_t *p, int ***map, vector v);

#endif
