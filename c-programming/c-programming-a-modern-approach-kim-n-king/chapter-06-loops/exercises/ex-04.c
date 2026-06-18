/*
 * Name: ex-04.c
 * Author: Edoardo Paggi
 * Task: add a loop to the broker.c program so that the user can enter more     
         than one trade and the program calculates the commission for each. The 
         program should terminate when the user enters 0 as the trade value:
         
         Enter value of trade: 30000
         Commission: $166.00
         
         Enter value of trade: 20000
         Commission: $144.00
         
         Enter value of trade: 0
         
*/

#include <stdio.h>

int main(void) {

    float commission, value;

    for (;;) {
        printf("Enter value of trade: ");
        scanf("%f", &value);

        if (value == 0)
            break;

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

        printf("Commission: $%.2f\n\n", commission);
    }

    return 0;
}