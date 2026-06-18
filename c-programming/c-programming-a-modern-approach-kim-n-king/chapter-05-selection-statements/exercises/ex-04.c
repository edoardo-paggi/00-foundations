/*
 * Name: ex-04.c
 * Author: Edoardo Paggi
 * Task: here is a simplified version of the Beaufourt scale that is used to 
         determine wind strength:
         
         Speed ​​(knots)    Description
         Less than 1      Calm
         1 - 3            Breath of wind
         4 - 27           Breeze
         28 - 47          Storm
         48 - 63          Tempest
         Over 63          Hurricane

         Write a program that prompts the user for a wind speed (in knots) and displays the corresponding description.
*/

#include <stdio.h>

int main(void) {

    int speed;

    printf("Enter a wind speed (in knots): ");
    scanf("%d", &speed);

    printf("Speed description: ");

    if (speed < 1) 
        printf("Calm\n");
    else if (speed < 4)
        printf("Breath of wind\n");
    else if (speed < 28)
        printf("Breeze\n");
    else if (speed < 48)
        printf("Storm\n");
    else if (speed < 64)
        printf("Tempest\n");
    else
        printf("Hurricane\n");
    
    return 0;
    
}