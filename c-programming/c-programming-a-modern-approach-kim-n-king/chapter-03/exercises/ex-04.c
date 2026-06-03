/*
 * Name: ex-04.c 
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a phone number in the 
         form (xxx) xxx-xxxx and then prints the number in the form 
         xxx.xxx.xxxx:
         
         Enter phone numer [ (xxx) xxx-xxxx ]: (404) 817-6900
         You entered 404.817.6900

 */

#include <stdio.h>

int main(void) {

    int area, centralOffice, line;

    printf("Enter phone number [ (xxx) xxx-xxxx ]: ");
    scanf("(%d) %d-%d", &area, &centralOffice, &line);

    /* the digits must necessarily be 3, 3 and 4 and area and centralOffice     
       cannot start with zero */
    printf("You entered %d.%d.%.4d\n", area, centralOffice, line);

    return 0;
}