#include <stdio.h>

/* copy input to output */
int main(void) {

    int c = getchar();

    // printf("%d\n", (getchar() != EOF));
    printf("%d\n", EOF);
    printf("\nyerp\n");

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("donzo\n");
}