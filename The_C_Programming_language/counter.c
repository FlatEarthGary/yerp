#include <stdio.h>

void lineCounting(void);
void counter(void);
void replace_doubble_whitespace(void);
void replace_ambiguous(void);

/* count characters in input */
int main(void) {
    //double nc;

    //counter();
    //lineCounting();

    //printf("\nyerp\n");

    //for (nc = 0; getchar() != EOF; ++nc)
        //;
    //printf("%.0f\n", nc);

    //replace_doubble_whitespace();
    replace_ambiguous();
}

void lineCounting(void) {
    int c, n1;

    n1 = 0;
    while ((c = getchar()) != EOF) 
        if (c == '\n')
            ++n1;
    
    printf("%d\n", n1);
}

void counter(void) {
    int c;
    int blanks, tabs, newlines;

    blanks, tabs, newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t') {
            ++tabs;
        }
        else if (c == '\n') {
            ++newlines;
        }

    }
}

void replace_doubble_whitespace(void) {
    int c, lc;

    c, lc = 0;
    while ((c = getchar()) != EOF) {
        if (!(c == ' ' && lc == ' '))
            putchar(c);
        lc = c;
    }
}

void replace_ambiguous(void) {
    int c;

    c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') 
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}