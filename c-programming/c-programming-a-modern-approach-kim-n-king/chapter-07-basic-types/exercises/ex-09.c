/*
 * Name: ex-09.c
 * Auhtor: Edoardo Paggi
 * Task: write a program that prompts the user for a time in 12-hour format and 
         then prints it in 24-hour format:

         Enter a 12-hour time: 9:11 PM
         Equivalent 24-hour time: 21:11

        See Programming Project 8 for a description of the input format.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ante_post;
    int hours, minutes;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hours, &minutes, &ante_post); 

    ante_post = toupper(ante_post);
    printf("%c\n", ante_post);

    printf("Equivalent 24-hour time: ");

    if (ante_post == 'A') {
        if (hours == 12)
            hours -= 12;
    } else {
        if (hours < 12)
            hours += 12;
    }
        
    
    printf("%.2d:%.2d\n", hours, minutes);

    return 0;
}