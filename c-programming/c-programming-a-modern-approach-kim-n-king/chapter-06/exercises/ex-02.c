/*
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter two integers and then 
         calculates and displays their greatest common divisor (GCF).
         
         Enter two integers: 12 28
         Greatest common divisor: 4
         
*/

#include <stdio.h>

int main(void) {

    int m, n, gcf, rest;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    // Hypothesis: m > n
    if (n > m) {
        int temp = m;
        m = n;
        n = temp;
    }

    // Euclid's Algorithm
    for (;;) {
        if (n == 0) {
            gcf = m;
            break;
        } else
            rest = m % n;

        m = n;
        n = rest;
    }

    printf("Greatest common divisor: %d\n", gcf);

    return 0;
}