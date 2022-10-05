unsigned int s21_strlen(const char *str) {
    unsigned int str_len = 0;
    for (; *(str + str_len); str_len++) {}
    return str_len;
}

int s21_strcmp(const char *str_1, const char *str_2) {
    for (; *str_1 && *str_1 == *str_2; str_1++, str_2++) {}
    return *str_1 - *str_2;
}

char *s21_strcpy(char *str_in, const char* str_out) {
    for (unsigned int i = 0; i < s21_strlen(str_out); i++) {
        str_in[i] = str_out[i];
    }
    str_in[s21_strlen(str_out)] = '\0';
    return str_in;
}

char *s21_strcat(char *str_1, const char *str_2) {
    char *new_str = str_1;
    while (*str_1 != '\0') {
        str_1++;
    }
    while (*str_2 != '\0') {
        *str_1 = *str_2;
        str_1++;
        str_2++;
    }
    *str_1 = '\0';
    return new_str;
}

char *s21_strchr(const char *str, int ch) {
    char *result;
    int i = 0;
    while (str[i] != '\0' && str[i] != ch) {
        i++;
    }
    *(str + i) == ch ? result = (char*) str + i : 0;
    return result;
}
