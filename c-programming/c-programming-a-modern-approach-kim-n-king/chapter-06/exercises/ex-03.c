/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a fraction and then 
         reduces that fraction to its lowest terms:
         
         Enter a fraction: 6/12
         In lowest terms: 1/2
         
*/

#include <stdio.h>

int main(void) {

    int num, den, m, n, rest, gcf;

    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &den);

    // Euclid's Algorithm
    if (den > num) {
        int temp = num;
        m = den;
        n = temp;
    }

    for (;;) {
        if (n == 0) {
            gcf = m;
            break;
        } else
            rest = m % n;

        m = n;
        n = rest;
    }

    // Solve
    num /= gcf;
    den /= gcf;

    printf("In lowest terms: %d/%d\n", num, den);

    return 0;
}