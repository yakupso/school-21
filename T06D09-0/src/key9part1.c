/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/
#include <stdio.h>

#define MAX_SZ 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int num);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int *number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int n, arr[MAX_SZ];
    if (input(arr, &n)) {
        printf("n/a");
        return 0;
    }
    int sum_numbers_v = sum_numbers(arr, n);
    int new_arr[MAX_SZ];
    int new_len = find_numbers(arr, n, &sum_numbers_v, new_arr);
    output(new_arr, new_len, sum_numbers_v);
    return 0;
}

int input(int *buffer, int *length) {
    char c;
    if (scanf("%d%c", length, &c) == 2 && c == '\n' && *length <= MAX_SZ) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d%c", p, &c) != 2 || (c != '\n' && c != ' ')) {
                return 1;
            }
        }
    } else {
        return 1;
    }
    return 0;
}

void output(int *buffer, int length, int num) {
    printf("%d\n", num);
    for (int i = 0; i < length; i++) {
        if (i != length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
    }
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int *number, int* numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (*number % buffer[i] == 0) {
                numbers[j] = buffer[i];
                j++;
            }
        }
    }
    return j;
}
