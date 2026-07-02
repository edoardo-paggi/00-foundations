/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 7 in Chapter 2 to include the following 
         function:
         
         void play_amount(int dollars, int *twenties, int *tens, int *fives,
                          int *ones);
                          
         The function determines the smallest number of $20, $10, $5, and $1 
         bills needed to pay the sum represented by the dollars parameter. The 
         twenties parameter points to a variable in which the function will 
         save the required number of $20 bills. The tens, fives, and ones 
         parameters have similar functions.
*/

#include <stdio.h>

#define ONE_DOLLAR 1
#define FIVE_DOLLARS 5
#define TEN_DOLLARS 10
#define TWENTY_DOLLARS 20

void play_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {

    int amount, one_dollar_bill, five_dollars_bill, ten_dollars_bill,
        twenty_dollars_bill;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    play_amount(amount, &twenty_dollars_bill, &ten_dollars_bill,
                &five_dollars_bill, &one_dollar_bill);

    printf("$20 bills: %d\n", twenty_dollars_bill);
    printf("$10 bills: %d\n", ten_dollars_bill);
    printf("$5 bills: %d\n", five_dollars_bill);
    printf("$1 bills: %d\n", one_dollar_bill);

    return 0;
}

void play_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    int remaining;
    
    *twenties = dollars / TWENTY_DOLLARS;
    remaining = dollars - (*twenties * TWENTY_DOLLARS);

    *tens = remaining / TEN_DOLLARS;
    remaining = remaining - (*tens * TEN_DOLLARS);

    *fives = remaining / FIVE_DOLLARS;
    remaining = remaining - (*fives * FIVE_DOLLARS);

    *ones = remaining / ONE_DOLLAR;
}