#include <stdio.h>

#define MAXSIZE 1000

int readInput(char s[], int lim);
void entab(char str[], int size);
void copy(char in[], char out[]);

/* buggar när det blir [tab][*][8*' '][3*char]
    paddingen fuckar inte, men det blir ingen tab utan blir spaces istället 
    fuckar på real.txt */
int main(void) {
    char input[MAXSIZE];

    readInput(input, MAXSIZE);
    entab(input, MAXSIZE);
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
void entab(char str[], int max) {
    char copied_str[max];               /* stores a copy of the provided string */
    int c_index, o_index;               /* copied's and original's string index */
    int counter;
    int space_counter;
    int tab_counter;

    copy(copied_str, str);

    c_index = 0;
    o_index = 0;
    counter = 0;
    space_counter = 0;
    tab_counter = 0;

    while (copied_str[c_index] != '\0') {
        counter += tab_counter;
        if (copied_str[c_index] == ' ') {
            ++counter;
            if (counter % 8 == 0) {
                str[o_index] = '\t';
                ++o_index;
                space_counter = 0;
            }
            else if (copied_str[c_index+1] == '\0') {
                str[o_index] = ' ';
            }
            else {
                ++space_counter;
            }
        }
        else if (copied_str[c_index] == '\n') {
            for (int i = 0; i < space_counter; ++i) {
                str[o_index] = ' ';
                ++o_index;
            }
            counter = 0;
            str[o_index] = copied_str[c_index];
            ++o_index;
            space_counter = 0;
            tab_counter = 0;
        }
        else if (copied_str[c_index] == '\t') {
            tab_counter += counter%8;
            str[o_index] = copied_str[c_index];
            ++o_index;
        }
        else {
            for (int i = 0; i < space_counter; ++i) {
                str[o_index] = ' ';
                ++o_index;
            }
            str[o_index] = copied_str[c_index];
            ++o_index;
            space_counter = 0;
            ++counter;
        }
        ++c_index;
    }

    str[o_index] = '\0';


    //while (copied_str[c_index] != '\0') {       /* checks if end of string has been reached */
        //if (copied_str[c_index] == '\t'         /* if a tab has been detected */
            //&& o_index+(8-amount+1) < max) {    /* and the string can store the amount of spaces */
                //amount = ((o_index-sub) % 8)-1;
                //printf("AMOUNT: %d\n", amount);
                //for (int j = 0; j < (8-amount); ++j)
                    //str[o_index+j] = ' ';
            
                //o_index += 8-amount;
                //amount_index = o_index;
        //}
        //else if (copied_str[c_index] == '\n') {
            //sub = o_index;

            //str[o_index] = copied_str[c_index];
            //++o_index;
        //}
        //else {
            //str[o_index] = copied_str[c_index];
            //++o_index;
        //}

        //++c_index;

    //}

    //str[o_index] = '\0';

}
