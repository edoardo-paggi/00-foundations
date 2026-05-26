/*
 * Name: ex-08.c
 * Author: Edoardo Paggi
 * Task: rite a program that calculates the remaining balance of a loan after
         the first, second, and third monthly payments.

         Enter amount of loan: 20000.00
         Enter interest rate: 6.0
         Enter monthly payment: 386.66
         Balance remaining after first payment: $19713.34
         Balance remaining after second payment: $19425.25
         Balance remaining after third payment: $19135.71

         Display each balance to two decimal places.
 */

#include <stdio.h>

int main(void) {

    float loan, interestRate, monthlyPayment, monthlyInterestRate;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    monthlyInterestRate = (interestRate / 100) / 12;

    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    loan = (loan - monthlyPayment) + (loan * monthlyInterestRate);
    printf("Balance remaining after first payment: $%.2f\n", loan);

    loan = (loan - monthlyPayment) + (loan * monthlyInterestRate);
    printf("Balance remaining after second payment: $%.2f\n", loan);

    loan = (loan - monthlyPayment) + (loan * monthlyInterestRate);
    printf("Balance remaining after third payment: $%.2f\n", loan);

    return 0;
}