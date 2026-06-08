/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: modify the program broker.c by making the following changes:
         a) Ask the user to enter a number of shares and the price per share    
            instead of asking for the trade value.
         b) Add instructions to calculate a rival broker's commission ($33 and  
            3 cents per share for volume less than 2,000 shares, $33 and 2 
            cents per share for volume equal to or greater than 2,000 shares). 
            Display both the rival's commission and the original broker's 
            commission.
*/

#include <stdio.h>

int main(void) {

    int number_shares;
    float price_share, commission, commission_rival, value;

    printf("Enter the number of shares: ");
    scanf("%d", &number_shares);
    printf("Enter the price per share: ");
    scanf("%f", &price_share);

    value = number_shares * price_share;

    if (value < 2500.0f)
        commission = 30.0f + 0.017f * value;
    else if (value < 6250.0f)
        commission = 56.0f + 0.0066f * value;
    else if (value < 20000.0f)
        commission = 76.0f + 0.0034f * value;
    else if (value < 50000.0f)
        commission = 100.0f + 0.0022f * value;
    else if (value < 500000.0f)
        commission = 155.0f + 0.0011f * value;
    else
        commission = 255.0f + 0.0009f * value;

    if (commission < 39.0f)
        commission = 39.0f;

    if (number_shares < 2000)
        commission_rival = 33 + 0.03 * number_shares;
    else
        commission_rival = 33 + 0.02 * number_shares;

    printf("\nCommission:              $%.2f\n", commission);
    printf("Rival Broker Commission: $%.2f\n\n", commission_rival);

    return 0;
}