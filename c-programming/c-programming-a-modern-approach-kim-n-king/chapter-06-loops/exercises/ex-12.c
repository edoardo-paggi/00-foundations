/* 
 * Name: ex-12.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 11 so that the program continues adding     
         terms until the current term becomes less than epsilon, where epsilon 
         is a small number (floating point) entered by the user.
*/

#include <stdio.h>

int main(void) {

    float e = 1.0f, epsilon, term;
    int factorial = 1;

    printf("Enter the epsilon number: ");
    scanf("%f", &epsilon);

    for (int i = 1;; i++) {
        factorial *= i;
        term = 1.0f / factorial;

        if (term < epsilon)
            break;

        e += term;
    }

    printf("The value of e = %f\n", e);

    return 0;
}