/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a two-digit number and 
         then prints the number with the digits reversed. A program session should look like this:
         
         Enter a two-digit number: 28
         The reversal is: 82
         
         Read the number using the %d specification and then divide into two digits.
*/

#include <stdio.h>

int main(void) {

    int number, units, tens, reversal;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    units = number / 10;
    tens = number % 10;
    reversal = tens * 10 + units;

    printf("The reversal is: %d\n", reversal);

    return 0;
}