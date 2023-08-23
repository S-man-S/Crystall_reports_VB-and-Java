#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sort1(int *a, int n);
void sort2(int *a, int n);
void swap(int *a, int *b);
void heapform(int *a, int n, int i);

void out(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a < n - 1) printf(" ");
    }
}

int main() {
    int data1[NMAX];
    if (input(data1) == 1) {
        int data2[NMAX];
        for (int i = 0; i < NMAX; i++) data2[i] = data1[i];
        sort1(data1, NMAX);
        sort2(data2, NMAX);
        output(data1);
        printf("\n");
        output(data2);
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

void sort1(int *a, int n) {
    int *left = a, *right = a + n - 1;
    int *mid = a + n / 2;
    int flagl = 0, flagr = 0;
    while (left != mid || right != mid) {
        if (flagl == 0 && left != mid) {
            if (*left > *mid)
                flagl = 1;
            else
                left++;
        }
        if (flagr == 0 && right != mid) {
            if (*right < *mid)
                flagr = 1;
            else
                right--;
        }
        if (flagl == 1 && right == mid) {
            swap(left, mid);
            mid = left;
            flagl = 1;
            flagr = 0;
        }
        if (flagr == 1 && left == mid) {
            swap(right, mid);
            mid = right;
            flagr = 1;
            flagl = 0;
        }
        if (flagl == 1 && flagr == 1) {
            swap(left, right);
            flagl = 0;
            flagr = 0;
        }
    }
    if (mid - a > 1) sort1(a, mid - a);
    if (a + n - 1 - mid > 1) sort1(mid + 1, a + n - 1 - mid);
}

void sort2(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapform(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a, a + i);
        heapform(a, i, 0);
    }
}

void heapform(int *a, int n, int i) {
    int big = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && a[l] > a[big]) big = l;
    if (r < n && a[r] > a[big]) big = r;
    if (big != i) {
        swap(a + i, a + big);
        heapform(a, n, big);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
