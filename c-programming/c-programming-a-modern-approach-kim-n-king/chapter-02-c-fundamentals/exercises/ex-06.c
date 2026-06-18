/*
 * Name: ex-06.c
 * Author: Edoardo Paggi
 * Task: modify the program in programming project 5 so that the polynomial is
         calculated using the following formula.

         ((((3x + 2)x - 5)x - 1)x + 7)x - 6

         Notice that the modified program performs fewer multiplications. This
         technique for calculating polynomials is known as Horner's rule.
 */

#include <stdio.h>

int main(void) {

    float x, value;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    value = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("Value of the polynomial = %f\n", value);

    return 0;
}