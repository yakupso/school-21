#include "./s21_string.h"
#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif  // STRLEN
#ifdef STRCMP
    s21_strcmp_test();
#endif  // STRCMP
#ifdef STRCPY
    s21_strcpy_test();
#endif  // STRCPY
#ifdef STRCAT
    s21_strcat_test();
#endif  // STRCAT
#ifdef STRCHR
    s21_strchr_test();
#endif  // STRCHR
    return 0;
}

void s21_strlen_test() {
    const char *test_strings[] = {
        "",
        "String",
        "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
    };
    unsigned int test_lenght[] = {0, 6, 52};
    for (int i = 0; i < 3; i++) {
        printf("In: %s\n", test_strings[i]);
        printf("Out: %u\n", s21_strlen(test_strings[i]));
        if (s21_strlen(test_strings[i]) == test_lenght[i])
            printf("Result: SUCCESS");
        else
            printf("Result: FAIL");
        if (i < 2) {
            printf("\n\n");
        }
    }
}

void s21_strcmp_test() {
    const char *test_strings_1[] = {
        "",
        "String",
        "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
    };
    const char *test_strings_2[] = {
        "",
        "Strng",
        "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRRRSsTtUuVvWwXxYyZz"
    };
    int test_outs[] = {0, -5, 32};
    for (int i = 0; i < 3; i++) {
        printf("In: '%s'\n    '%s'\n", test_strings_1[i], test_strings_2[i]);
        printf("Out: %d\n", s21_strcmp(test_strings_1[i], test_strings_2[i]));
        if (s21_strcmp(test_strings_1[i], test_strings_2[i]) == test_outs[i])
            printf("Result: SUCCESS");
        else
            printf("Result: FAIL");
        if (i < 2) {
            printf("\n\n");
        }
    }
}

void s21_strcpy_test() {
    const char *test_strings_1[] = {
        "",
        "String",
        "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
    };
    char *test_strings_2[] = {malloc(101*sizeof(char)), malloc(101*sizeof(char)), malloc(101*sizeof(char))};
    for (int i = 0; i < 3; i++) {
        s21_strcpy(test_strings_2[i], test_strings_1[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("In:  '%s'\n", test_strings_1[i]);
        printf("Out: '%s'\n", test_strings_2[i]);
        int is_equal = 1;
        for (unsigned int j = 0; j < s21_strlen(test_strings_1[i]); j++) {
            if (test_strings_1[i][j] != test_strings_2[i][j])
                is_equal = 0;
        }
        if (is_equal)
            printf("Result: SUCCESS");
        else
            printf("Result: FAIL");
        if (i < 2) {
            printf("\n\n");
        }
    }
    for (int i = 0; i < 3; i++) {
        free(test_strings_2[i]);
    }
}

void s21_strcat_test() {
    char test_strings_1[][101] = {
        "",
        "I'll ",
        "Empty"
    };
    const char *test_strings_2[] = {
        "mt",
        "be back",
        ""
    };
    const char *results[] = {
        "mt",
        "I'll be back",
        "Empty"
    };
    for (int i = 0; i < 3; i++) {
        printf("In: '%s'\n    '%s'\n", test_strings_1[i], test_strings_2[i]);
        s21_strcat(test_strings_1[i], test_strings_2[i]);
        printf("Out: %s\n", test_strings_1[i]);
        int is_equal = 1;
        for (unsigned int j = 0; j < s21_strlen(test_strings_1[i]); j++) {
            if (test_strings_1[i][j] != results[i][j])
                is_equal = 0;
        }
        if (is_equal)
            printf("Result: SUCCESS");
        else
            printf("Result: FAIL");
        if (i < 2) {
            printf("\n\n");
        }
    }
}

void s21_strchr_test() {
    char *test_strings[] = {
        "",
        "I'll ",
        "Empty"
    };
    int test_chars[] = {
        '\0',
        'l',
        't'
    };
    long int test_outs[] = {0, 2, 3};
    for (int i = 1; i < 3; i++) {
        printf("In: '%s'\n    '%c'\n", test_strings[i], test_chars[i]);
        char *result = s21_strchr(test_strings[i], test_chars[i]);
        printf("Out: %s\n", result);
        if ((result - test_strings[i]) == test_outs[i])
            printf("Result: SUCCESS");
        else
            printf("Result: FAIL");
        if (i < 2) {
            printf("\n\n");
        }
    }
}
