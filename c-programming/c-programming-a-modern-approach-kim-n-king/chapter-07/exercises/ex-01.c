/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: the program square2.c will fail (typically print strange results) if 
         i * i exceeds the maximum int value. Run the program and determine the 
         smallest value of n that causes the problem. Try changing the type of 
         i to the short type and run the program again (don't forget to update 
         the conversion specification in the printf call!). Then try the long 
         type. What can you conclude from these experiments about the number of 
         bits used to store different integer types on your machine?
*/

#include <stdio.h>

int main(void) {

    long i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld", &n);

    for (i = 1; i <= n; i++)
        printf("%20ld%20ld\n", i, i * i);

    return 0;
}

/* 
    The smallest value of n (int) that causes the problem is 46341.
    If n is a short int the smallest number that causes the problem is 182.
    If n is a long int the smallest number causing the problem is 3037000500,
    since 9.223.372.036.854.775.807 = 2^63 - 1
          3.037.000.499^2 = 9.223.372.030.926.249.001 < 2^63 - 1
          3.037.000.500^2 = 9.223.372.037.000.250.000 > 2^63 - 1
    I can conclude that shorts have 16 bits, ints 32 bits and longs 64 bits (Linux WSL, while on Windows they have 32 bits).
*/