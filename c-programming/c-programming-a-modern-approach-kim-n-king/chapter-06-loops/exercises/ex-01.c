/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: write a program that finds the largest number given a series of 
         numbers entered by the user. The program should prompt the user to 
         enter the numbers one at a time. When the user enters a negative 
         number or zero, the program should display the largest non-negative 
         number entered so far:
         
         Enter a number: 60
         Enter a number: 38.3
         Enter a number: 4.89
         Enter a number: 100.62
         Enter a number: 75.2295
         Enter a number: 0

         The largest number entered was 100.62

         Keep in mind that numbers are not necessarily whole numbers.
*/

#include <stdio.h>

int main(void) {

    float number, max = 0.0f;

    for (;;) {
        printf("Enter a number: ");
        scanf("%f", &number);

        if (number > max)
            max = number;

        if (number <= 0) {
            printf("\nThe largest number entered was %f\n", max);
            break;
        }
    }

    return 0;
}