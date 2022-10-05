CC=gcc
FLAGS=-Werror -Wextra -Wall
CFLAGS=-c -Werror -Wextra -Wall
OUT=../build/graph
all: $(OUT)
rebuild: clean all
clean:
    rm *.o  ../build/*
$(OUT): graph.o data_io.o translate.o list.o stack.o stack_double.o string_parsing.o
    $(CC) $(FLAGS) graph.o data_io.o translate.o list.o stack.o stack_double.o string_parsing.o -o $(OUT)
graph.o:
    $(CC) $(CFLAGS) graph.c
data_io.o:
    $(CC) $(CFLAGS) data_io.c
translate.o:
    $(CC) $(CFLAGS) translate.c
list.o:
    $(CC) $(CFLAGS) list.c
stack.o:
    $(CC) $(CFLAGS) stack.c
stack_double.o:
    $(CC) $(CFLAGS) stack_double.c
string_parsing.o:
    $(CC) $(CFLAGS) string_parsing.c