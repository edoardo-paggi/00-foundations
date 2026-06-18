/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: write a program that accepts data from the user in mm/dd/yyyy format
         and then prints it in yyyymmdd format:

         Enter a date (mm/dd/yyyy): 2/17/2011
         You entered the date 20110217

 */

#include <stdio.h>

int main(void) {

    int mm, dd, yyyy;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("You entered the date %.4d%.2d%.2d\n", yyyy, mm, dd);

    return 0;
}