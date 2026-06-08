/*
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user for a time in 24-hour format and 
         then displays the same time in 12-hour format:
         
         Enter a 24-hour time: 21:11
         Equivalent 12-hour time: 9:11 PM
         
         Be careful not to display 12:00 as 0:00
*/

#include <stdio.h>

int main(void) {

    int hours, minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    printf("Equivalent 12-hour time: ");

    if (hours == 0)
        printf("12:%.2d AM\n", minutes);
    else if (hours > 0 && hours < 12)
        printf("%d:%.2d AM\n", hours, minutes);
    else if (hours == 12)
        printf("%d:%.2d PM\n", hours, minutes);
    else // [13, 23]
        printf("%d:%.2d PM\n", hours - 12, minutes);

    return 0;
}