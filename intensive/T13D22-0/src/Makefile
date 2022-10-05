CC=gcc
FLAGS=-Werror -Wextra -Wall
CFLAGS=-c -Werror -Wextra -Wall
OUT=../build

all: cipher

rebuild: clean all

clean:
	rm ./../build/*
    
cipher: cipher.c
	$(CC) $(FLAGS) cipher.c -o $(OUT)/cipher

