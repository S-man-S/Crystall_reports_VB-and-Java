#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sort(int *a);
void swap(int *a, int *b);

int main() {
    int data[NMAX];
    if (input(data) == 1) {
        sort(data);
        output(data);
    } else
        printf("n/a");
    return 0;
}

int input(int *a) {
    int flag = 1;
    for (int *p = a; p - a < NMAX; p++)
        if (scanf("%d", p) != 1) {
            flag = 0;
            break;
        }
    return flag;
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d", *p);
        if (p - a < NMAX - 1) printf(" ");
    }
}
void sort(int *a) {
    for (int *p = a; p - a < NMAX - 1; p++) {
        for (int *p2 = p + 1; p2 - a < NMAX; p2++) {
            if (*p > *p2) swap(p, p2);
        }
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
