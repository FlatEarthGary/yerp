#include <stdio.h>

#define MAXSIZE 1000

int readInput(char s[], int lim);
void detab(char str[], int size);
void copy(char in[], char out[]);

/* test start point */
int main(void) {
    char input[MAXSIZE];

    readInput(input, MAXSIZE);
    detab(input, MAXSIZE);
    printf("%s\n", input);
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

/* transforms tabs into the appropiate amount of spaces */
void detab(char str[], int max) {
    char copied_str[max];               /* stores a copy of the provided string */
    int c_index, o_index;               /* copied's and original's string index */
    int amount;                         /*  */
    int amount_index;
    int sub;

    copy(copied_str, str);

    c_index = 0;
    o_index = 0;
    amount_index = 0;
    sub = -1;

    while (copied_str[c_index] != '\0') {       /* checks if end of string has been reached */
        if (copied_str[c_index] == '\t'         /* if a tab has been detected */
            && o_index+(8-amount+1) < max) {    /* and the string can store the amount of spaces */
                amount = ((o_index-sub) % 8)-1;
                printf("AMOUNT: %d\n", amount);
                for (int j = 0; j < (8-amount); ++j)
                    str[o_index+j] = ' ';
            
                o_index += 8-amount;
                amount_index = o_index;
        }
        else if (copied_str[c_index] == '\n') {
            sub = o_index;

            str[o_index] = copied_str[c_index];
            ++o_index;
        }
        else {
            str[o_index] = copied_str[c_index];
            ++o_index;
        }

        ++c_index;

    }

    str[o_index] = '\0';

}