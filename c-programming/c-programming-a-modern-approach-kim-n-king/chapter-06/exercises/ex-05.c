/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: Programming Project 1 in Chapter 4 asked you to write a program that 
         displays a two-digit number by reversing the order of the digits. 
         Generalize the program so that the number can have one, two, three, or 
         more digits.
*/

#include <stdio.h>

int main(void) {

    int number, digit, reversal = 0;

    printf("Enter a number: "); // 12345 => 54321
    scanf("%d", &number);

    do {
        digit = number % 10;
        number /= 10;
        reversal = reversal * 10 + digit;
    } while (number > 0);

    printf("The reversal is: %d\n", reversal);

    return 0;
}