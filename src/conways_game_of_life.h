#ifndef SRC_CONWAYS_GAME_OF_LIFE_H_
#define SRC_CONWAYS_GAME_OF_LIFE_H_

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80

int input_data(int matrix[HEIGHT][WIDTH]);
void output(int matrix[HEIGHT][WIDTH]);
void count_life_neighbours(int dot[HEIGHT][WIDTH], int life[HEIGHT][WIDTH]);
void occur_life_by_rules(int dot[HEIGHT][WIDTH], int life[HEIGHT][WIDTH]);
void set_delay(int *sleep_time);
int check_stop_condition(int matrix1[HEIGHT][WIDTH],
                         int matrix2[HEIGHT][WIDTH]);
void condition_modul(int matrix1[HEIGHT][WIDTH], int matrix2[HEIGHT][WIDTH]);

#endif  // SRC_CONWAYS_GAME_OF_LIFE_H_