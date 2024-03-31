#include <stdio.h>

#define MAXSIZE 1000

int readInput(char s[], int lim);
void copy(char dst[], char src[]);
int fold(char str[], int limit, int max);

int main(void) {
    char in[MAXSIZE];

    readInput(in, MAXSIZE);
    fold(in, 6, MAXSIZE);
    printf("%s\n", in);
}

int fold(char str[], int limit, int max) {
    char copied_str[max];

    int c_index;
    int back_index;
    int o_index;
    int index;

    c_index = 0;
    o_index = 0;
    index = 0;
    while (copied_str[c_index] != '\0') {
        if (index % limit == 0) {
            str[back_index] = '\n';
        }
        else if (copied_str[c_index] == ' ') {
            back_index = o_index;
        }
    }

    str[o_index] = '\0';

}

/* function to read from input and store it in provided string with the limit lim */
int readInput(char in[], int lim) {
    int c;
    int i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF; ++i) {
        in[i] = c;
    }

    in[i] = '\0';

    return i;
}

/* copies string from src to dst, assumes dst is large enough to store src */
void copy(char dst[], char src[]) {
    int i;

    i = 0;
    while ((dst[i] = src[i]) != '\0') {
        ++i;
    }
}
