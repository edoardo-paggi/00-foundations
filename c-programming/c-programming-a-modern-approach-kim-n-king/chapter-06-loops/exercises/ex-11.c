/*
 * Name: ex-11.c
 * Author: Edoardo Paggi
 * Task: the value of the mathematical constant e can be expressed as an 
         infinite series: 
         
         e = 1 + 1/1! + 1/2! + 1/3! + ...
         
         Write a program that approximates e by calculating the value of
        
         1 + 1/1! + 1/2! + 1/3! + 1/n!

         where n is an integer entered by the user.
*/

#include <stdio.h>

int main(void) {

    float e = 1.0f;
    int n, factorial = 1;

    printf("Enter the number of addends: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;

        e += (1.0f / factorial);
    }

    printf("The value of e = %f\n", e);

    return 0;
}