gcc -Wall -Werror -Wextra game_of_life.c
stty -icanon && cat input_2.txt - | ./a.out
