#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>

#define HEIGHT 25
#define WIDTH 80
#define DEAD_CELL ' '
#define ALIVE_CELL '#'
#define MAX_SPEED 1000
#define MIN_SPEED 0

void input_field(char field[HEIGHT][WIDTH]);
void clear_field(char field[HEIGHT][WIDTH]);
void render_field(char field[HEIGHT][WIDTH], unsigned long long generation,
                  int speed);
void clear_screen(void);
void render_border(void);
void next_generation(char field[HEIGHT][WIDTH], unsigned long long *generation);
int count_neighbors(char field[HEIGHT][WIDTH], int x, int y);
int max(int a, int b);
int min(int a, int b);
void speed_up(int *speed);
void slow_down(int *speed);
void game_of_life(void);

int main() {
  game_of_life();
  return 0;
}

void game_of_life() {
  char field[HEIGHT][WIDTH];
  char c = 0;
  unsigned long long generation = 0;
  int speed = 1;
  int tick_count = 0;
  int tick_border = 1000;

  clear_field(field);
  input_field(field);

  system("stty -icanon");

  clear_screen();
  render_field(field, generation, speed);

  while (c != 'q' && c != 'Q') {
    clock_t tick_start = clock();
    int bytes_to_read = 0;

    c = 0;
    if (ioctl(0, FIONREAD, &bytes_to_read) == 0 && bytes_to_read > 0) {
      c = getchar();
    }
    if (c == 'a' || c == 'A') {
      speed_up(&speed);
    } else if (c == 'z' || c == 'Z') {
      slow_down(&speed);
    }

    if (tick_count > tick_border) {
      tick_count = 0;
      next_generation(field, &generation);
    }

    clear_screen();
    render_field(field, generation, speed);

    tick_count += speed;

    while (clock() < tick_start + 1000) {
    }
  }
}

void clear_field(char field[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      field[i][j] = DEAD_CELL;
    }
  }
}

void input_field(char field[HEIGHT][WIDTH]) {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    field[x][y] = ALIVE_CELL;
  }
}

void clear_screen(void) { printf("\033[2J\033[H"); }

void render_border(void) {
  for (int i = 0; i < WIDTH + 2; ++i) {
    printf(".");
  }
  printf("\n");
}

void render_field(char field[HEIGHT][WIDTH], unsigned long long generation,
                  int speed) {
  render_border();
  for (int i = 0; i < HEIGHT; ++i) {
    printf(".");
    for (int j = 0; j < WIDTH; ++j) {
      printf("%c", field[i][j]);
    }
    printf(".\n");
  }
  render_border();
  printf("a - speed up (max %d) | z - slow down (min %d) | q - exit\n",
         MAX_SPEED, MIN_SPEED);
  printf("Generation: %llu\n", generation);
  printf("Generations per second: %d\n", speed);
}

void next_generation(char field[HEIGHT][WIDTH],
                     unsigned long long *generation) {
  int neighbors_count[HEIGHT][WIDTH];
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      neighbors_count[i][j] = count_neighbors(field, i, j);
    }
  }

  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      if (neighbors_count[i][j] == 3) {
        field[i][j] = ALIVE_CELL;
      } else if (neighbors_count[i][j] > 3 || neighbors_count[i][j] < 2) {
        field[i][j] = DEAD_CELL;
      }
    }
  }

  ++*generation;
}

int count_neighbors(char field[HEIGHT][WIDTH], int x, int y) {
  int neighbours_count = 0;

  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      if (dx != 0 || dy != 0) {
        int i = (x + dx + HEIGHT) % HEIGHT;
        int j = (y + dy + WIDTH) % WIDTH;
        if (field[i][j] == ALIVE_CELL) {
          ++neighbours_count;
        }
      }
    }
  }

  return neighbours_count;
}

void speed_up(int *speed) { *speed = min(MAX_SPEED, *speed + 1); }

void slow_down(int *speed) { *speed = max(MIN_SPEED, *speed - 1); }

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
