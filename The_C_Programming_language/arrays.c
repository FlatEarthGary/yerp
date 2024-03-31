#include <stdio.h>

#define ALPH_LENGTH 26
#define START 97

#define IN 1
#define OUT 0

void counter(void);
void horizontal_historgram(void);
void word_histogram(void);

/* count digits, white space, others */
void main(void) {
    word_histogram();
}

void counter(void) {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
        nwhite, nother);

}

void word_histogram(void) {
    int c;
    int word[ALPH_LENGTH];
    int wordIndex;
    int status;

    wordIndex = 0;
    status = OUT;
    for (int i = 0; i < ALPH_LENGTH; ++i) {
        word[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {

            for (int i = 0; i < (20 - word[wordIndex]); ++i)
                putchar(' ');

            for (int i = 0; i < word[wordIndex]; ++i)
                putchar('-');
            putchar('\n');
            ++wordIndex;
        }
        else {
            ++word[wordIndex];
            putchar(c);
        }

    }

    

}

void horizontal_historgram(void) {
    int c;
    int historgram[ALPH_LENGTH];

    for (int i = 0; i < ALPH_LENGTH; ++i)
        historgram[i] = 0;


    while ((c = getchar()) != EOF) {
        if (c >= START && c <= (START + ALPH_LENGTH))
            ++historgram[c-START];
    }

    for (int i = 0; i < ALPH_LENGTH; ++i) {
        printf("\t%c\t", (START + i));
        for (int j = 0; j < historgram[i]; ++j) 
            putchar('-');
        putchar('\n');
    }
}

/* not done */
void vertical_histogram(void) {
    int c;
    int historgram[ALPH_LENGTH];
    int sorted_histogram[ALPH_LENGTH];

    for (int i = 0; i < ALPH_LENGTH; ++i)
        historgram[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= START && c <= (START + ALPH_LENGTH))
            ++historgram[c-START];
    }

    for (int i = 0; i < ALPH_LENGTH; ++i) {

    }

    //printf("%c\t", (START + i));
    //for (int j = 0; j < historgram[i]; ++j) 
        //putchar('-');
    //putchar('\n');
    //}
}