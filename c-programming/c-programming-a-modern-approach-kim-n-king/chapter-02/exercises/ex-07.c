/*
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: write a program that asks the user to enter a dollar amount and then
         shows how to pay it using the fewest number of $20, $10, $5, and $1
         bills.

         Enter a dollar amount: 93
         $20 bills: 4
         $10 bills: 1
         $5 bills: 0
         $1 bills: 3

 */

#include <stdio.h>

#define ONE_DOLLAR 1
#define FIVE_DOLLARS 5
#define TEN_DOLLARS 10
#define TWENTY_DOLLARS 20

int main(void) {

    int amount, oneDollarBill, fiveDollarsBill, tenDollarsBill,
        twentyDollarsBill, remaining;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    twentyDollarsBill = amount / TWENTY_DOLLARS;
    remaining = amount - twentyDollarsBill * TWENTY_DOLLARS;

    tenDollarsBill = remaining / TEN_DOLLARS;
    remaining = remaining - tenDollarsBill * TEN_DOLLARS;

    fiveDollarsBill = remaining / FIVE_DOLLARS;
    remaining = remaining - fiveDollarsBill * FIVE_DOLLARS;

    oneDollarBill = remaining / ONE_DOLLAR;
    remaining = remaining - oneDollarBill * ONE_DOLLAR;

    printf("$20 bills: %d\n", twentyDollarsBill);
    printf("$10 bills: %d\n", tenDollarsBill);
    printf("$5 bills: %d\n", fiveDollarsBill);
    printf("$1 bills: %d\n", oneDollarBill);

    return 0;
}