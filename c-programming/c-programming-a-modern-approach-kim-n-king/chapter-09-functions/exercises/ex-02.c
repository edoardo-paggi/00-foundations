/*
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: modify Programming project 5 in Chapter 5 to use a function to 
         calculate the income tax amount. When passed the taxable income amount, the function should return the tax due.
*/

#include <stdio.h>

float calculate_tax(float income);

int main(void) {

    float income;

    printf("Enter a taxable income: ");
    scanf("%f", &income);

    printf("Tax due: %.2f\n", calculate_tax(income));

    return 0;
}

float calculate_tax(float income) {
    float tax;

    if (income < 750)
        tax = 0.01f * income;
    else if (income < 2250)
        tax = 7.5f + 0.02f * (income - 750);
    else if (income < 3750)
        tax = 37.5f + 0.03f * (income - 2250);
    else if (income < 5250)
        tax = 82.5f + 0.04f * (income - 3750);
    else if (income < 7000)
        tax = 142.5f + 0.05f * (income - 5250);
    else
        tax = 230.0f + 0.06f * (income - 7000);

    return tax;
}