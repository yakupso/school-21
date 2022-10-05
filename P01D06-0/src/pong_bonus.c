#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

const int WIDTH = 80;
const int HEIGHT = 25;
const int ROCKET_SIZE = 3;
const int BALL_SIZE = 1;
const int VICTORY_SCORE = 21;
const int POS_X_PLAYER_1 = 2;
const int POS_X_PLAYER_2 = 78;
// score
int F_CURR_SCORE = 0;
int S_CURR_SCORE = 0;
// player first
int player_f_coord_x = POS_X_PLAYER_1;
int player_f_coord_y = HEIGHT / 2;  // Появляется в середине поля слева или справа
// player second
int player_s_coord_x = POS_X_PLAYER_2;
int player_s_coord_y = HEIGHT / 2;  // Появляется в середине поля слева или справа
// ball
int ball_coord_x = WIDTH / 2;
int ball_coord_y = HEIGHT / 2;
int ball_dir_x = 1;
int ball_dir_y = 1;
// game status
int is_active = 1;

int move_player(int player_coord_y, int par);
void move_ball();
void frame();

int main() {
    initscr();
    nodelay(stdscr, true);
    noecho();
    // main loop
    while (F_CURR_SCORE < VICTORY_SCORE && S_CURR_SCORE < VICTORY_SCORE) {
        int choice;
        usleep(100000);
        clear();
        refresh();
        frame(ball_coord_x, ball_coord_y,
               player_f_coord_y, player_s_coord_y);
        if (F_CURR_SCORE == VICTORY_SCORE && S_CURR_SCORE == VICTORY_SCORE) {
            break;
        }
        choice = getch();
        if (!(choice == ERR)) {
            if (choice == 112) {
                is_active = -is_active;
                move_ball();
            }
            if (is_active == -1)
                continue;
            if (choice == 97) {
                player_f_coord_y = move_player(player_f_coord_y, 0);
                move_ball();
            }
            if (choice == 122) {
                player_f_coord_y = move_player(player_f_coord_y, 1);
                move_ball();
            }
            if (choice == 107) {
                player_s_coord_y = move_player(player_s_coord_y, 0);
                move_ball();
            }
            if (choice == 109) {
                player_s_coord_y = move_player(player_s_coord_y, 1);
                move_ball();
            }
        } else  if (is_active > 0) {
            move_ball();
        }
    }
    frame(ball_coord_x, ball_coord_y,
           player_f_coord_y, player_s_coord_y);
    endwin();
    return 0;
}

int move_player(int player_coord_y, int par) {
        if (par && player_coord_y < HEIGHT - 2) {
            player_coord_y++;
        } else if (!par && player_coord_y > 2) {
            player_coord_y--;
        }
    return player_coord_y;
}

void move_ball() {
     if (ball_coord_y == 1 || ball_coord_y == HEIGHT - 1) {
        // Если ударяется в верхнюю или нижнюю грань
        ball_dir_y = -ball_dir_y;
     } else if (ball_coord_x == 2 &&
                (ball_coord_y == player_f_coord_y ||
                 ball_coord_y == player_f_coord_y + 1 ||
                 ball_coord_y == player_f_coord_y - 1)) {
         // Если ударяется о ракетку первого игрока
         ball_dir_x = -ball_dir_x;
     } else if (ball_coord_x == WIDTH - 2 &&
               (ball_coord_y == player_s_coord_y ||
                ball_coord_y == player_s_coord_y + 1 ||
                ball_coord_y == player_s_coord_y - 1)) {
         // Если ударяется о ракетку второго игрока
         ball_dir_x = -ball_dir_x;
    } else if (ball_coord_x == 0) {
      // Если ударяется о левую грань (второй игрок выиграл очко)
         ball_coord_x = WIDTH / 2;
         ball_coord_y = HEIGHT / 2;
         S_CURR_SCORE++;
         ball_dir_x = -1;
     } else if (ball_coord_x == WIDTH) {
         // Если ударяется о правую грань (первый игрок выиграл очко)
         ball_coord_x = WIDTH / 2;
         ball_coord_y = HEIGHT / 2;
         F_CURR_SCORE++;
         ball_dir_x = 1;
     }
    ball_coord_x += ball_dir_x;
    ball_coord_y += ball_dir_y;
}

void frame() {
    char rocket = '|';
    char dig_x = '-';
    char dig_y = rocket;
    char ball_c = '*';
    char space = ' ';
    // Очистить экран
    system("clear");
    // Отрисовка границ и разметки поля, игроков и мяча
    for (int y = 0; y <= HEIGHT; y++) {
        for (int x = 0; x <= WIDTH; x++) {
            if (x == ball_coord_x && y == ball_coord_y) {
                printw("%c", ball_c);
            } else if ((y == player_f_coord_y ||
                       y == player_f_coord_y - 1 ||
                       y == player_f_coord_y + 1) &&
                       x == POS_X_PLAYER_1) {
                printw("%c", rocket);
            } else if ((y == player_s_coord_y ||
                        y == player_s_coord_y - 1 ||
                        y == player_s_coord_y + 1) &&
                        x == POS_X_PLAYER_2) {
                printw("%c", rocket);
            } else if (y == 0 || y == HEIGHT) {
                printw("%c", dig_x);
            } else if (x == 0 || x == WIDTH || x == WIDTH / 2) {
                printw("%c", dig_y);
            } else {
                printw("%c", space);
            }
        }
        printw("\n");
    }
    if (is_active == -1 && F_CURR_SCORE != VICTORY_SCORE && S_CURR_SCORE != VICTORY_SCORE) {
        // Если пауза и никто не выиграл
        printw("%s%s%s%s%d%s%d%s%s%s%s",
               "---------------------------------------------------------------------------------\n",
               "| a/z for player 1    |                         SCORE:                          |\n",
               "| k/m for player 2    |       PLAYER 1:                       PLAYER 2:         |\n",
               "| p for pause/unpause |          ", F_CURR_SCORE,
               "                               ",
               S_CURR_SCORE,
               "              |\n",
               "|---------------------|---------------------------------------------------------|\n",
               "|       PAUSE         |                                                         |\n",
               "---------------------------------------------------------------------------------");
    } else if (is_active == 1 && F_CURR_SCORE != VICTORY_SCORE && S_CURR_SCORE != VICTORY_SCORE) {
        // Если не пауза, и никто не выиграл
        printw("%s%s%s%s%d%s%d%s%s%s%s",
               "---------------------------------------------------------------------------------\n",
               "| a/z for player 1    |                         SCORE:                          |\n",
               "| k/m for player 2    |       PLAYER 1:                       PLAYER 2:         |\n",
               "| p for pause/unpause |          ",
               F_CURR_SCORE,
               "                               ",
               S_CURR_SCORE,
               "              |\n",
               "|---------------------|---------------------------------------------------------|\n",
               "|                     |                                                         |\n",
               "---------------------------------------------------------------------------------");
    } else if (is_active == 1 && F_CURR_SCORE == VICTORY_SCORE) {
        // Если не пауза, и первый игрок выиграл
        printw("%s%s%s%s%d%s%d%s%s%s%s",
               "---------------------------------------------------------------------------------\n",
               "| a/z for player 1    |                         SCORE:                          |\n",
               "| k/m for player 2    |       PLAYER 1:                       PLAYER 2:         |\n",
               "| p for pause/unpause |          ",
               F_CURR_SCORE,
               "                               ",
               S_CURR_SCORE,
               "              |\n",
               "|---------------------|---------------------------------------------------------|\n",
               "|                     |             Congratulations, player 1!                  |\n",
               "---------------------------------------------------------------------------------");
    } else if (is_active == 1 && S_CURR_SCORE == VICTORY_SCORE) {
        // Если не пауза, и второй игрок выиграл
        printw("%s%s%s%s%d%s%d%s%s%s%s  ",
               "---------------------------------------------------------------------------------\n",
               "| a/z for player 1    |                         SCORE:                          |\n",
               "| k/m for player 2    |       PLAYER 1:                       PLAYER 2:         |\n",
               "| p for pause/unpause |          ",
               F_CURR_SCORE,
               "                               ",
               S_CURR_SCORE,
               "              |\n",
               "|---------------------|---------------------------------------------------------|\n",
               "|                     |             Congratulations, player 2!                  |\n",
               "---------------------------------------------------------------------------------");
    }
}
