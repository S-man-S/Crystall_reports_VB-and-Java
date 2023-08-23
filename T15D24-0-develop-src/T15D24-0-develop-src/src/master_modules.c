#include "master_modules.h"

#include <stdio.h>

int delete_M() {
    int id, ret = 0;
    printf("Please enter Module ID (int): ");
    if (scanf("%d", &id) == 1) {
        int flag = 1;
        FILE *file = fopen("master_modules.db", "rb");
        FILE *dest = fopen("master_modules2.db", "ab");
        int num, idn;
        char chr[30];
        while (flag) {
            if (fread(&idn, sizeof(int), 1, file) != 0) {
                if (idn != id) fwrite(&idn, sizeof(int), 1, dest);
                fread(chr, sizeof(char), 30, file);
                if (idn != id) fwrite(chr, sizeof(char), 30, dest);
                fread(&num, sizeof(int), 1, file);
                if (idn != id) fwrite(&num, sizeof(int), 1, dest);
                fread(&num, sizeof(int), 1, file);
                if (idn != id) {
                    fwrite(&num, sizeof(int), 1, dest);
                    ret = num;
                }
                fread(&num, sizeof(int), 1, file);
                if (idn != id) fwrite(&num, sizeof(int), 1, dest);
            } else
                flag = 0;
        }
        fclose(file);
        fclose(dest);
        remove("master_modules.db");
        rename("master_modules2.db", "master_modules.db");
    }
    return ret;
}

int insert_M() {
    int id, num3, num4, del, flag = 0;
    printf("Please enter Module ID (int): ");
    if (scanf("%d", &id) == 1) {
        char name[30];
        rewind(stdin);
        printf("Please enter Module name (char[30]): ");
        fgets(name, 30, stdin);
        printf("Please enter Number of the memory level where the module is located (int): ");
        if (scanf("%d", &num3) == 1) {
            printf("Please enter Number of the cell where the module is located on this level (int): ");
            if (scanf("%d", &num4) == 1 && num4 >= 1 && num4 <= 4) {
                printf("Please enter Deletion flag (int): ");
                if (scanf("%d", &del) == 1 && del >= 0 && del <= 1) {
                    FILE *file = fopen("master_modules.db", "rb");
                    if (check_M(file, id)) {
                        fwrite(&id, sizeof(int), 1, file);
                        fwrite(name, sizeof(char), 30, file);
                        fwrite(&num3, sizeof(int), 1, file);
                        fwrite(&num4, sizeof(int), 1, file);
                        fwrite(&del, sizeof(int), 1, file);
                        flag = num4;
                    }
                    fclose(file);
                }
            }
        }
    }
    return flag;
}

int check_M(FILE *file, int id) {
    int ret = 1;
    int flag = 1;
    int num;
    char chr[30];
    while (flag) {
        if (fread(&num, sizeof(int), 1, file) != 0) {
            if (num == id) ret = 0;
            fread(chr, sizeof(char), 30, file);
            fread(&num, sizeof(int), 1, file);
            fread(&num, sizeof(int), 1, file);
            fread(&num, sizeof(int), 1, file);
        } else
            flag = 0;
    }
    return ret;
}

void select_M() {
    int c;
    printf(
        "Please choose a column:\n1. Module ID\n2. Module name\n3. Number of the memory level where the "
        "module is located\n4. Number of the cell where the module is located on this level\n5. Deletion "
        "flag\n");
    if (scanf("%d", &c) == 1 && c >= 1 && c <= 5)
        out_M(c);
    else
        printf("n/a");
}

void out_M(int stolb) {
    FILE *file = fopen("master_modules.db", "rb");
    int flag = 1;
    int num;
    char chr[30];
    while (flag) {
        if (fread(&num, sizeof(int), 1, file) != 0) {
            if (stolb == 1 || stolb == 6) printf("%d ", num);
            if (stolb == 6) printf(" ");
            fread(chr, sizeof(char), 30, file);
            if (stolb == 2 || stolb == 6) printf("%s ", chr);
            if (stolb == 6) printf(" ");
            fread(&num, sizeof(int), 1, file);
            if (stolb == 3 || stolb == 6) printf("%d ", num);
            if (stolb == 6) printf(" ");
            fread(&num, sizeof(int), 1, file);
            if (stolb == 4 || stolb == 6) printf("%d ", num);
            if (stolb == 6) printf(" ");
            fread(&num, sizeof(int), 1, file);
            if (stolb == 5 || stolb == 6) printf("%d\n", num);
            printf("\n");
        } else
            flag = 0;
    }
    fclose(file);
}
