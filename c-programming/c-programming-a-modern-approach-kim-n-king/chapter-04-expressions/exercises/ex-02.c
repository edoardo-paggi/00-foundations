/*
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: extend the program in Programming Project 1 to handle three-digit 
         numbers.
*/

#include <stdio.h>

#define TENS 10
#define HUNDREDS 100

int main(void) {

    int number, units, tens, hundreds, reversal;

    printf("Enter a three-digit number: "); // 123 => 321
    scanf("%d", &number);

    units = number / HUNDREDS;
    tens = (number / TENS) % TENS;
    hundreds = (number % HUNDREDS) % TENS;

    reversal = hundreds * HUNDREDS + tens * TENS + units;

    printf("The reversal is: %d\n", reversal);

    return 0;
}