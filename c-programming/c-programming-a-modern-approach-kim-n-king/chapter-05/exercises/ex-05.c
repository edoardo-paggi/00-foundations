/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: in a State, residents are subject to the following income taxes:
         
        Income                Tax amount
        Not exceeding $750    1% of income 
        $750 - $2,250         $7.50 plus 2% of the fee above $750
        $2,250 - $3,750       $37.50 plus 3% of the fee above $2,250
        $3,750 - $5,250       $82,50 plus 4% of the fee above $3,750
        $5,250 - $7,000       $142,50 plus 5% of the fee above $5,250
        Over $7,000           $230,00 plus 6% of the fee above $7,000

        Write a program that prompts the user to enter their taxable income and 
        then displays the tax due.
*/

#include <stdio.h>

int main(void) {

    float income, tax;

    printf("Enter a taxable income: ");
    scanf("%f", &income);

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

    printf("Tax due: %.2f\n", tax);

    return 0;
}