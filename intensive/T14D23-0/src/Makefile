all: state_sort state_search

state_sort:
	gcc -Werror -Wextra -Wall state_sort.c binary_files_common_functions.c -o ../build/Quest_1
	
state_search:
	gcc -Werror -Wextra -Wall state_search.c binary_files_common_functions.c -o ../build/Quest_2
	
clean:
	rm -rf ../build/*

rebuild: clean all
