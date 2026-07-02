/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 3 in Chapter 6 to include the following 
         function:
         
         void reduce(int numerator, int denominator, int *reduced_numerator,    
                     int *reduced_denominator);
                     
         The numerator and denominator parameters are the numerator and 
         denominator of a fraction, respectively. The reduced_numerator and 
         reduced_denominator parameters are pointers to the variables in which 
         the function will store the numerator and denominator of the fraction 
         after it has been reduced to its lowest terms.
*/

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, 
            int *reduced_denominator);

int main(void) {
    int num, den, red_num, red_den;

    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &den);

    reduce(num, den, &red_num, &red_den);

    printf("In lowest terms: %d/%d\n", red_num, red_den);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, 
            int *reduced_denominator) {
    int m, n, rest, gcd;

    // Euclid's Algorithm to calculate GCF
    m = numerator;
    n = denominator;

    if (n > m) {
        int temp = m;
        m = n;
        n = temp;
    }

    for (;;) {
        if (n == 0) {
            gcd = m;
            break;
        } else
            rest = m % n;

        m = n;
        n = rest;
    }

    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}