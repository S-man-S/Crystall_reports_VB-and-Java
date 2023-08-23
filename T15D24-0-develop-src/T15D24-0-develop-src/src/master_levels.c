#include "master_levels.h"

#include <stdio.h>

void change_L(int level, int inc) {
    FILE *file = fopen("master_levels.db", "r+b");
    int id, num;
    while (fread(&id, sizeof(int), 1, file) != 0) {
        fread(&num, sizeof(int), 1, file);
        if (id == level) {
            fseek(file, -sizeof(int), SEEK_CUR);
            num += inc;
            fwrite(&num, sizeof(int), 1, file);
            break;
        }
        fread(&num, sizeof(int), 1, file);
        printf("\n");
    }
    fclose(file);
}

void select_L() {
    int c;
    printf(
        "Please choose a column:\n1. Number of memory level\n2. The number of cells on the level\n3. "
        "Protection flag\n");
    if (scanf("%d", &c) == 1 && c >= 1 && c <= 3)
        out_L(c);
    else
        printf("n/a");
}

void out_L(int stolb) {
    FILE *file = fopen("master_levels.db", "rb");
    int num;
    while (fread(&num, sizeof(int), 1, file) != 0) {
        if (stolb == 1 || stolb == 4) printf("%d", num);
        if (stolb == 4) printf(" ");
        fread(&num, sizeof(int), 1, file);
        if (stolb == 2 || stolb == 4) printf("%d", num);
        if (stolb == 4) printf(" ");
        fread(&num, sizeof(int), 1, file);
        if (stolb == 3 || stolb == 4) printf("%d", num);
        printf("\n");
    }
    fclose(file);
}
