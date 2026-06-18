/* 
 * Name: ex-04.c
 * Author: Edoardo Paggi
 * Task: write a program that reads a user-entered integer and displays it in 
         octal (base 8):

         Enter a number between 0 and 32767: 1953
         In octal, your number is: 03641

         The output should be displayed using five digits even if fewer would suffice.
*/

#include <stdio.h>

#define OCTAL 8

int main(void) {

    /* 
        1953 % 8 = 1 => n1
         244 % 8 = 4 => n2
          30 % 8 = 6 => n3
           3 % 8 = 3 => n4
           0 % 8 = 0 => n5
          
        1953 = (03641)_8
    */

    int number, n1, n2, n3, n4, n5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);

    n1 = number % OCTAL;
    number /= OCTAL;
    n2 = number % OCTAL;
    number /= OCTAL;
    n3 = number % OCTAL;
    number /= OCTAL;
    n4 = number % OCTAL;
    number /= OCTAL;
    n5 = number % OCTAL;
    number /= OCTAL;

    printf("In octal, your number is: %d%d%d%d%d\n", n5, n4, n3, n2, n1);

    return 0;
}