/*
 * Name: ex-10.c
 * Author: Edoardo Paggi
 * Task: use the switch statement to write a program that converts a numerical 
         grade to a letter grade:
         
         Enter numerical grade: 84
         Letter grade: B
         
         Use the following scale: A = 90-100, B = 80-89, C = 70-79, D = 60-69, 
         F = 0-59. Print an error message if the score is greater than 100 or 
         less than 0.
*/

#include <stdio.h>

int main(void) {

    int grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade < 0 || grade > 100) {
        printf("ERROR! The grade must be between 0 and 100.\n");
        return 0;
    }

    printf("Letter grade: ");

    switch (grade / 10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("F\n");
            break;
        case 6:
            printf("D\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 9:
        case 10:
            printf("A\n");
            break;
    }

    return 0;
}