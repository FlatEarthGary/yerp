
#include <stdio.h>

#define MAXLINE 1000

int reverse(char s[], int size);
int getLine(char s[], int lim);
void copy(char to[], char from[]);

int main(void) {
    int len;                /*  current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* curent input line */
    char longest[MAXLINE];  /* longest line saved here */

    while ((len = getLine(line, MAXLINE)) > 0) {
        printf("LINE: %s\n", line);
        reverse(line, len);
        printf("REVERSE: %s\n", line);
    }

    return 0;
}

int getLine(char s[], int lim) {
    int c;
    int i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int reverse(char s[], int size) {
    char copied_string[size];

    copy(copied_string, s);

    size = size-1;

    for (int i = 0; i < size; ++i) {
        s[i] = copied_string[size-1-i];
    }

    s[size] = '\0';
}