/*
 * Name: ex-06.c
 * Auhtor: Edoardo Paggi
 * Task: write a program that prints the values ​​sizeof(int), sizeof(short),
         sizeof(long), sizeof(float), sizeof(double) and sizeof(long double).
*/

#include <stdio.h>

int main(void) {

    printf("\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n\n", sizeof(long double));

    return 0;
}