#include "shared.h"

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"

void out() {
    int c;
    printf("Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n");
    if (scanf("%d", &c) == 1) {
        switch (c) {
            case 1:
                out_M(6);
                break;
            case 2:
                out_L(4);
                break;
            case 3:
                out_S(6);
                break;
            default:
                printf("n/a\n");
                break;
        }
    } else
        printf("n/a\n");
}

void select() {
    int c;
    printf("Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n");
    if (scanf("%d", &c) == 1) {
        switch (c) {
            case 1:
                select_M();
                break;
            case 2:
                select_L();
                break;
            case 3:
                select_S();
                break;
            default:
                printf("n/a\n");
                break;
        }
    } else
        printf("n/a\n");
    rewind(stdin);
}

void insert() {
    int level = insert_M();
    if (level)
        change_L(level, 1);
    else
        printf("n/a\n");
}

void delete () {
    int level = delete_M();
    if (level)
        change_L(level, -1);
    else
        printf("n/a\n");
}
