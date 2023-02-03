#include "conways_game_of_life.h"

int main() {
  // To run this program:
  // bash: gcc -Wall -Werror -Wextra -lncurses game_of_life.c
  // bash: ./a.out 0 < your_init_file.txt
  int dot[HEIGHT][WIDTH];
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, 1);
  scrollok(stdscr, 1);
  curs_set(0);
  input_data(dot);
  output(dot);
  int ch;
  if (freopen("/dev/tty", "r", stdin) != NULL) {
    int life[HEIGHT][WIDTH];
    int dot1[HEIGHT][WIDTH];
    int sleep_time = 200000;
    while (check_stop_condition(dot, dot1) == 0) {
      condition_modul(dot, dot1);
      clear();
      count_life_neighbours(dot, life);
      occur_life_by_rules(dot, life);
      output(dot);
      set_delay(&sleep_time);
      usleep(sleep_time);
      refresh();
      if ((ch = getch()) == 'q') break;
    }
  } else {
    printf("n/a");
  }
  endwin();
  if (ch != 'q') printf("GAME OVER\n");
  return 0;
}

int input_data(int matrix[HEIGHT][WIDTH]) {
  for (int i = 1; i < HEIGHT - 1; i++)
    for (int j = 1; j < WIDTH - 1; j++) scanf("%d", &matrix[i][j]);
  return 0;
}

void output(int matrix[HEIGHT][WIDTH]) {
  for (int i = 0; i < WIDTH; i++) printw("#");
  printw("\n");
  for (int i = 1; i < HEIGHT - 1; i++) {
    printw("#");
    for (int j = 1; j < WIDTH - 1; j++) {
      if (matrix[i][j] == 0) {
        printw(" ");
      } else {
        printw("@");
      }
    }
    printw("#");
    printw("\n");
  }
  for (int i = 0; i < WIDTH; i++) printw("#");
}

void count_life_neighbours(int dot[HEIGHT][WIDTH], int life[HEIGHT][WIDTH]) {
  for (int i = 2; i < HEIGHT - 2; i++) {
    for (int j = 2; j < WIDTH - 2; j++) {
      life[i][j] = dot[i][j - 1] + dot[i - 1][j - 1] + dot[i - 1][j] +
                   dot[i - 1][j + 1] + dot[i][j + 1] + dot[i + 1][j + 1] +
                   dot[i + 1][j] + dot[i + 1][j - 1];
    }
  }
  for (int i = 2; i < HEIGHT - 3; i++)
    life[i][WIDTH - 2] =
        (dot[i - 1][WIDTH - 3] + dot[i][WIDTH - 3] + dot[i + 1][WIDTH - 3]) +
        (dot[i - 1][WIDTH - 2] + dot[i + 1][WIDTH - 2]) +
        (dot[i - 1][1] + dot[i][1] + dot[i + 1][1]);
  for (int i = 2; i < HEIGHT - 3; i++)
    life[i][1] =
        (dot[i - 1][WIDTH - 2] + dot[i][WIDTH - 2] + dot[i + 1][WIDTH - 2]) +
        (dot[i - 1][1] + dot[i + 1][1]) +
        (dot[i - 1][2] + dot[i][2] + dot[i + 1][2]);
  for (int i = 2; i < WIDTH - 3; i++)
    life[1][i] = (dot[HEIGHT - 2][i - 1] + dot[1][i - 1] + dot[2][i - 1]) +
                 (dot[HEIGHT - 2][i] + dot[2][i]) +
                 (dot[HEIGHT - 2][i + 1] + dot[1][i + 1] + dot[2][i + 1]);
  for (int i = 2; i < WIDTH - 3; i++)
    life[HEIGHT - 2][i] =
        (dot[HEIGHT - 3][i - 1] + dot[HEIGHT - 2][i - 1] + dot[1][i - 1]) +
        (dot[HEIGHT - 3][i] + dot[1][i]) +
        (dot[HEIGHT - 3][i + 1] + dot[HEIGHT - 2][i + 1] + dot[1][i + 1]);
  // corners:
  life[1][1] =
      (dot[HEIGHT - 2][WIDTH - 2] + dot[1][WIDTH - 2] + dot[2][WIDTH - 2]) +
      (dot[HEIGHT - 2][1] + dot[2][1]) +
      (dot[HEIGHT - 2][2] + dot[1][2] + dot[2][2]);
  life[1][WIDTH - 2] =
      (dot[HEIGHT - 2][WIDTH - 3] + dot[1][WIDTH - 3] + dot[2][WIDTH - 3]) +
      (dot[HEIGHT - 2][WIDTH - 2] + dot[2][WIDTH - 2]) +
      (dot[HEIGHT - 2][1] + dot[1][1] + dot[2][1]);
  life[HEIGHT - 2][1] = (dot[HEIGHT - 3][WIDTH - 2] +
                         dot[HEIGHT - 2][WIDTH - 2] + dot[1][WIDTH - 2]) +
                        (dot[HEIGHT - 3][1] + dot[1][1]) +
                        (dot[HEIGHT - 3][2] + dot[HEIGHT - 2][2] + dot[1][2]);
  life[HEIGHT - 2][HEIGHT - 2] =
      (dot[HEIGHT - 3][WIDTH - 3] + dot[HEIGHT - 2][WIDTH - 3] +
       dot[1][WIDTH - 3]) +
      (dot[HEIGHT - 3][WIDTH - 2] + dot[1][WIDTH - 2]) +
      (dot[HEIGHT - 3][1] + dot[HEIGHT - 2][1] + dot[1][1]);
}

void occur_life_by_rules(int dot[HEIGHT][WIDTH], int life[HEIGHT][WIDTH]) {
  for (int i = 1; i < HEIGHT - 1; i++) {
    for (int j = 1; j < WIDTH - 1; j++) {
      if (dot[i][j] == 0 && life[i][j] == 3)
        dot[i][j] = 1;
      else if (dot[i][j] == 1 && life[i][j] < 2)
        dot[i][j] = 0;
      else if (dot[i][j] == 1 && life[i][j] > 3)
        dot[i][j] = 0;
    }
  }
}

void set_delay(int *sleep_time) {
  int ch;
  ch = getch();
  if (ch == '-' && *sleep_time <= 1000000) {
    *sleep_time += 10000;
  }
  if (ch == '+' && *sleep_time > 100000) {
    *sleep_time -= 10000;
  }
}

int check_stop_condition(int matrix1[HEIGHT][WIDTH],
                         int matrix2[HEIGHT][WIDTH]) {
  int state = 0, count = 0;
  for (int i = 1; i < HEIGHT - 1; i++) {
    for (int j = 1; j < WIDTH - 1; j++) {
      if (matrix2[i][j] == matrix1[i][j]) count++;
    }
  }
  if (count == 1794) state = 1;
  return state;
}

void condition_modul(int matrix1[HEIGHT][WIDTH], int matrix2[HEIGHT][WIDTH]) {
  for (int i = 1; i < HEIGHT - 1; i++)
    for (int j = 1; j < WIDTH - 1; j++) matrix2[i][j] = matrix1[i][j];
}
