/*
 * Name: ex-04.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter an amount in dollars and
         cents and then prints it with a 5% tax surcharge.

   Enter an amount: 100.00
   With tax added: $105.00

 */

#include <stdio.h>

#define TAX 0.05f

int main(void) {

    float amount;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    printf("With tax added: $%.2f\n", amount + amount * TAX);

    return 0;
}