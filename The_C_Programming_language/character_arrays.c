#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int printGreater80(void);
int __main(void);
int removeTrail(void);

/* print longest input line */
int main(void) {

    //printGreater80();
    //removeTrail();
    __main();
    
    return 0;
}

int __main(void) {
    int len;                /*  current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* curent input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    
    if (max > 0)    /* there was a line */
    {
        printf("%d\t%s", max, longest);
    }

    return 0;
}

/* getLine: read a line into s, return length */
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

int printGreater80(void) {
    int len;                /*  current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* curent input line */
    char longest[MAXLINE];  /* longest line saved here */

    while ((len = getLine(line, MAXLINE)) > 0)
        if (len >= 80)
            printf("%s\n", line);
    
    return 0;
}

int removeTrail(void) {
    int len;                /*  current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* curent input line */
    char longest[MAXLINE];  /* longest line saved here */
    
    char character;
    int counter;

    counter = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        character = line[len-counter];
        while (character == ' ' || character == '\t') {
            line[len-counter] = '\0';
            ++counter;
            --len;
        }

        if (len > max) {
            max = len;
            copy(longest, line);
        }

        counter = 0;
    }
    
    if (max > 0)    /* there was a line */
    {
        printf("%d\t%s", max, longest);
    }
    
    return 0;
}
