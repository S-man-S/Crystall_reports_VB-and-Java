/*------------------------------------
    Здравствуй, человек!
    Чтобы получить ключ
    поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

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
    int length, buffer[NMAX], numbers[NMAX];
    input(buffer, &length);
    if (length != 0) {
        int number = sum_numbers(buffer, length);
        if (number != 0) {
            int len = find_numbers(buffer, length, number, numbers);
            printf("%d\n", number);
            output(numbers, len);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
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
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int len = 0;
    for (int *p = buffer; p - buffer < length; p++)
        if (*p != 0 && number % *p == 0) {
            numbers[len] = *p;
            len++;
        }
    return len;
}

void input(int *buffer, int *length) {
    if (scanf("%d", length) == 1 && *length > 0 && *length <= NMAX) {
        for (int *p = buffer; p - buffer < *length; p++)
            if (scanf("%d", p) != 1) {
                length = 0;
                break;
            }
    } else
        length = 0;
}
void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer < length - 1) printf(" ");
    }
}
