/*
 * Name: ex-09.c
 * Author: Edoardo Paggi
 * Task: in Programming Project 8 of Chapter 2, you were asked to write a 
         program that calculated the remaining debt on a loan after the first, 
         second, and third monthly payments. Modify the program to also prompt 
         the user to enter the number of payments and then display the 
         remaining debt after each of those payments.
*/

#include <stdio.h>

int main(void) {

    int number_payments;
    float loan, interest_rate, monthly_payment, monthly_interest_rate;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter number of payments: ");
    scanf("%d", &number_payments);

    monthly_interest_rate = (interest_rate / 100) / 12;

    for (int i = 1; i <= number_payments; i++) {
        if (i == 1)
            printf("Balance remaining after %d payment: ", i);
        else
            printf("Balance remaining after %d payments: ", i);

        loan = (loan - monthly_payment) + (loan * monthly_interest_rate);

        printf("$%.2f\n", loan);
    }

    return 0;
}