#include <stdio.h>

#define LOWER 0         /* lower limit of table */
#define UPPER 300       /* upper limit */
#define STEP 20         /* step size */

void celciusToFahrenheit();

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
void main() {

    printf("\nWelcome to the reversed fahrenheit-to-celcius table!\n\n");

    for (int fahr = UPPER; LOWER < fahr; fahr -= STEP) {
        printf("%2d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

    celciusToFahrenheit();

}

void celciusToFahrenheit() {
    float fahr, celcius;
    int lower, upper, step;

    lower = LOWER; 
    upper = UPPER;
    step = STEP;

    printf("\nWelcome to the celcius-to-fahrenheit program!\n\n");

    celcius = lower;
    while (celcius <= upper) {
        fahr = celcius / (5.0/9.0) + 32.0;
        printf("%6.2f\t%3.0f\n", celcius, fahr);
        celcius += step;
    }
}