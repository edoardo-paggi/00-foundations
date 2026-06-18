/* 
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: fix the square3.c program so that the for loop initializes, checks, 
         and increments the variable i. Do not rewrite the program, and in 
         particular, do not use any multiplication.
*/

#include <stdio.h>

int main(void) {

    int n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    odd = 3;
    for (int i = 1, square = 1; i <= n; i++, odd += 2) {
        printf("%10d%10d\n", i, square);
        square += odd;
    }

    return 0;
}