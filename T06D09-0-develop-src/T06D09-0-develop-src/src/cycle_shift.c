#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void shifter(int *buffer, int length, int shift, int *numbers);

int main() {
    int length, buffer[NMAX], shift, numbers[NMAX];
    input(buffer, &length, &shift);
    if (length != 0) {
        shifter(buffer, length, shift, numbers);
        output(numbers, length);
    } else
        printf("n/a");
    return 0;
}

void shifter(int *buffer, int length, int shift, int *numbers) {
    for (int i = 0; i < length; i++) {
        int finshift = i + shift;
        while (finshift < 0) finshift += length;
        while (finshift >= length) finshift -= length;
        numbers[i] = buffer[finshift];
    }
}

void input(int *buffer, int *length, int *shift) {
    char c;
    if (scanf("%d", length) == 1 && *length > 0 && *length <= NMAX) {
        for (int *p = buffer; p - buffer < *length; p++)
            if (scanf("%d", p) != 1) {
                length = 0;
                break;
            }
        if (length == 0 || scanf("%d%c", shift, &c) != 2 || c != '\n') length = 0;
    } else
        length = 0;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer < length - 1) printf(" ");
    }
}
