CC=gcc
FLAGS=-Wall -Wextra -Wall
CFLAGS=-c -Wall -Wextra -Wall


all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

strlen_tests: s21_string_test.c s21_string.o
	$(CC) $(FLAGS) s21_string_test.c s21_string.o -o ../build/Quest_1 -D STRLEN
	
	
strcmp_tests: s21_string_test.c s21_string.o
	$(CC) $(FLAGS) s21_string_test.c s21_string.o -o ../build/Quest_2 -D STRCMP
	
strcpy_tests: s21_string_test.c s21_string.o
	$(CC) $(FLAGS) s21_string_test.c s21_string.o -o ../build/Quest_3 -D STRCPY
	
strcat_tests:
	$(CC) $(FLAGS) s21_string_test.c s21_string.o -o ../build/Quest_4 -D STRCAT
	
strchr_tests:
	$(CC) $(FLAGS) s21_string_test.c s21_string.o -o ../build/Quest_5 -D STRCHR
	
s21_string.o: s21_string.c
	$(CC) $(CFLAGS) s21_string.c -o s21_string.o

