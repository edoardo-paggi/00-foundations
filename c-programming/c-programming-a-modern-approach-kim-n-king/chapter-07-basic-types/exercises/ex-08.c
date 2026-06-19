/*
 * Name: ex-08.c
 * Author: Edoardo Paggi
 * Task: modify the Programming Project in Chapter 5 so that the user enters a 
         time in 12-hour format. The input must be in the form hours:minutes 
         followed by A, P, AM, or PM (either lowercase or uppercase). Blank 
         spaces between the hour and the AM/PM indicator are permitted (but not 
         required). Here are some examples of valid input:
         
         1:15P
         1:15PM
         1:15p
         1:15pm
         1:15 P
         1:15 PM
         1:15 p
         1:15 pm
         
         You can assume that the input has one of these forms; there is no need 
         to test for possible errors.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ante_post;
    int hours, minutes;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hours, &minutes, &ante_post); 

    ante_post = toupper(ante_post);

    printf("Time: ");
    if (ante_post == 'A')
        printf("%d:%.2d AM\n", hours, minutes);
    else
        printf("%d:%.2d PM\n", hours, minutes);

    return 0;
}