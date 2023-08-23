#include "shared.h"

int main() {
    int c, flag = 1;
    while (flag) {
        printf(
            "Please choose one operation:\n1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n5. Output db\n6. "
            "Magic\n7. Exit\n");
        if (scanf("%d", &c) == 1) {
            switch (c) {
                case 1:
                    select();
                    break;
                case 2:
                    insert();
                    break;
                case 3:
                    printf("Not ready yet");
                    break;
                case 4:
                    delete ();
                    break;
                case 5:
                    out();
                    break;
                case 6:
                    printf("<3\n");
                    break;
                case 7:
                    flag = 0;
                    break;
                default:
                    printf("n/a\n");
                    break;
            }
        } else
            printf("n/a\n");
        rewind(stdin);
    }
}
