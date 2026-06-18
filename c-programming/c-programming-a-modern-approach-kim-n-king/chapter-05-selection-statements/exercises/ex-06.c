/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: modify the program in upc.c to check whether a UPC code is valid. 
         After the user enters the UPC code, the program should output VALID or 
         NOT VALID.
*/

#include <stdio.h>

int main(void) {

    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, first_sum,
        second_sum, total, check_digit;

    printf("Enter a UPC code (12 digits): ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6,
          &n7, &n8, &n9, &n10, &n11, &n12);

    first_sum = n1 + n3 + n5 + n7 + n9 + n11;
    second_sum = n2 + n4 + n6 + n8 + n10;
    total = first_sum * 3 + second_sum;
    check_digit = 9 - (total - 1) % 10;

    printf("UPC code ");

    if (check_digit == n12)
        printf("VALID!\n");
    else
        printf("NOT VALID!\n");

    return 0;
}