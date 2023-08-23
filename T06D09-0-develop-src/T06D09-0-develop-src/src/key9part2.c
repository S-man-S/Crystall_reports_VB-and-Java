#include <stdio.h>

#define LEN 100

void input(int *buffer, int *length);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int minisumsub(int a, int b, int *ms);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buffer1[LEN], len1, buffer2[LEN], len2, buffer3[LEN], len3, buffer4[LEN], len4;
    input(buffer1, &len1);
    if (len1 != 0) {
        input(buffer2, &len2);
        if (len2 != 0) {
            sum(buffer1, len1, buffer2, len2, buffer3, &len3);
            sub(buffer1, len1, buffer2, len2, buffer4, &len4);
            output(buffer3, len3);
            printf("\n");
            output(buffer4, len4);
        }
    }
}

void input(int *buffer, int *length) {
    char c;
    *length = 0;
    while (scanf("%d%c", &buffer[*length], &c) == 2 && (c == ' ' || c == '\n')) {
        if (buffer[*length] < 0 || buffer[*length] > 9 || *length == 100) {
            *length = 0;
            break;
        }
        *length += 1;
        if (c == '\n') break;
    }
}

void output(int *buffer, int length) {
    int flag = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (flag == 0 && *p != 0) flag = 1;
        if (flag == 1) {
            printf("%d", *p);
            if (p - buffer < length - 1) printf(" ");
        }
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    if (len1 >= len2) {
        *result_length = len1;
    } else {
        *result_length = len2;
    }
    for (int i = 0; i < *result_length; i++) {
        int ind = *result_length - 1 - i;
        if (i < len1 && i < len2)
            result[ind] =
                minisumsub(buff1[ind - *result_length + len1], buff2[ind - *result_length + len2], &carry);
        if (i >= len1) result[ind] = minisumsub(0, buff2[ind], &carry);
        if (i >= len2) result[ind] = minisumsub(buff1[ind], 0, &carry);
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    if (len1 >= len2) {
        *result_length = len1;
        for (int i = 0; i < *result_length; i++) {
            int ind = *result_length - 1 - i;
            if (i < len2)
                result[ind] = minisumsub(buff1[ind], -1 * buff2[ind - *result_length + len2], &carry);
            else
                result[ind] = minisumsub(buff1[ind], 0, &carry);
        }
    } else {
        *result_length = 0;
    }
}

int minisumsub(int a, int b, int *ms) {
    int cur = a + b + *ms;
    if (cur >= 10) {
        cur -= 10;
        *ms = 1;
    } else {
        if (cur < 0) {
            cur += 10;
            *ms = -1;
        } else
            *ms = 0;
    }
    return cur;
}
