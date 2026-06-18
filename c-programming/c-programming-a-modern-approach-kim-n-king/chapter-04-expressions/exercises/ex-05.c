/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: rewrite the upc.c program so that the user enters 11 digits at once 
         instead of entering the code in groups of one and five digits.
         
         Enter the first 11 digits of a UPC: 01380015173
         Check digit: 5
         
*/

#include <stdio.h>

int main(void) {

    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, first_sum, second_sum,
        total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6,
          &n7, &n8, &n9, &n10, &n11);

    first_sum = n1 + n3 + n5 + n7 + n9 + n11;
    second_sum = n2 + n4 + n6 + n8 + n10;
    total = first_sum * 3 + second_sum;

    printf("Check digit: %d\n", 9 - (total - 1) % 10);

    return 0;
}