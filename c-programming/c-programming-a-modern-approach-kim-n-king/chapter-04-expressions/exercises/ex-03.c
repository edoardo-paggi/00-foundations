/* 
 * Name: ex-03.c
 * Auhtor: Edoardo Paggi
 * Task: rewrite the program in Programming Project 2 so that it prints the 
         reverse of a three-digit number without any arithmetic to divide the number into digits.
*/

#include <stdio.h>

int main(void) {

    int units, tens, hundreds;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &units, &tens, &hundreds);

    printf("The reversal is: %d%d%d\n", hundreds, tens, units);

    return 0;
}