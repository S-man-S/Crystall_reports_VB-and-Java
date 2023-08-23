#include "master_status_events.h"

void select_S() {
    int c;
    printf(
        "Please choose a column:\n1. Event ID\n2. Module ID\n3. New module status\n4. Status change date\n5. "
        "Status change time\n");
    if (scanf("%d", &c) == 1 && c >= 1 && c <= 5)
        out_S(c);
    else
        printf("n/a");
}

void out_S(int stolb) {
    FILE *file = fopen("master_status_events.db", "rb");
    int flag = 1;
    int num;
    char str[11];
    while (flag) {
        if (fread(&num, sizeof(int), 1, file) != 0) {
            if (stolb == 1 || stolb == 6) printf("%d", num);
            if (stolb == 6) printf(" ");
            fread(&num, sizeof(int), 1, file);
            if (stolb == 2 || stolb == 6) printf("%d", num);
            if (stolb == 6) printf(" ");
            fread(&num, sizeof(int), 1, file);
            if (stolb == 3 || stolb == 6) printf("%d", num);
            if (stolb == 6) printf(" ");
            fread(str, sizeof(char), 11, file);
            if (stolb == 4 || stolb == 6) printf("%s", str);
            if (stolb == 6) printf(" ");
            fread(str, sizeof(char), 9, file);
            if (stolb == 5 || stolb == 6) printf("%s", str);
            printf("\n");
        } else
            flag = 0;
    }
    fclose(file);
}
