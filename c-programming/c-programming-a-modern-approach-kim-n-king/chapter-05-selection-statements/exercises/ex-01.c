/* 
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: write a program that calculates how many digits are in a number:
         
         Enter a number: 374;
         The number 374 has 3 digits
         
         You can assume that the number has no more than four digits.
*/

#include <stdio.h>

int main(void) {

    int number, digits;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 10)
        digits = 1;
    else if (number < 100)
        digits = 2;
    else if (number < 1000)
        digits = 3;
    else
        digits = 4;

    if (digits == 1)
        printf("The number %d has %d digit\n", number, digits);
    else
        printf("The number %d has %d digits\n", number, digits);

    return 0;
}