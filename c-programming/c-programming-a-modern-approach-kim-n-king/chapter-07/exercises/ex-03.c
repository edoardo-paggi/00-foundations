/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: modify the sum 2.c program to add a series of double numbers.
*/

#include <stdio.h>

int main(void) {

    double n, sum = 0.0;

    printf("\nThis program sums a series of doubles.\n");
    printf("Enter doubles (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }

    printf("The sum is: %f\n\n", sum);

    return 0;
}