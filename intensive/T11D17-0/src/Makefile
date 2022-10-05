CC=gcc
FLAGS=-Werror -Wextra -Wall
CFLAGS=-c -Werror -Wextra -Wall

all: door_struct list_test stack_test

door_struct:
	$(CC) $(FLAGS) dmanager_module.c -o ./../build/Quest_1

list_test: list_test.o list.o
	$(CC) $(FLAGS) list_test.o list.o -o ./../build/Quest_2
	
stack_test: stack.o stack_test.o
	$(CC) $(FLAGS) stack_test.o stack.o -o ./../build/Quest_3

stack.o:
	$(CC) $(CFLAGS) stack.c

stack_test.o:
	$(CC) $(CFLAGS) stack_test.c
	
list_test.o:
	$(CC) $(CFLAGS) list_test.c
	
list.o:
	$(CC) $(CFLAGS) list.c

clean:
	rm -rf *.o ../build/*

rebuild: clean all
