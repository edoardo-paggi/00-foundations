/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a value for x and
         displays the value of the following polynomial.

         3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

 */

#include <stdio.h>

int main(void) {

    float x, value;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    value = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) -
            (x * x) + (7 * x) - 6;

    printf("Value of the polynomial = %f\n", value);

    return 0;
}