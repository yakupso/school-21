CC=gcc
FLAGS=-Werror -Wextra -Wall
CFLAGS=-c -Werror -Wextra -Wall
OUT=../../build/Quest_3

all: $(OUT)

rebuild: clean all

clean:
	rm *.o *.so *.a ../../build/*

$(OUT): main_executable_module.c data_io.o data_stat.o data_process.o decision.o
	$(CC) $(FLAGS) main_executable_module.c data_io.o data_stat.o data_process.o decision.o -o $(OUT)

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) ../data_module/data_process.c
	
decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) ../yet_another_decision_module/decision.c

data_stat.a: data_stat.o
	ar rc data_stat.a data_stat.o
	ranlib data_stat.a

build_with_static: main_executable_module.c data_io.o data_process.o decision.o data_stat.a
	gcc main_executable_module.c data_stat.a data_io.o data_process.o decision.o -o ../../build/Quest_5

data_process.so:
	gcc -fPIC -c ../data_module/data_process.c -o data_process.o
	gcc -fPIC -c ../data_libs/data_stat.c -o data_stat.o
	gcc -shared -o data_process.so data_process.o data_stat.o
	
build_with_dynamic: main_executable_module.c data_io.o decision.o data_process.so
	gcc $(FLAGS) main_executable_module.c data_io.o decision.o data_process.so -o ../../build/Quest_6 -Wl,-rpath ./data_process.so
