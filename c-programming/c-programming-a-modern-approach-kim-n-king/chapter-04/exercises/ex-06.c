/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: European countries use a 13-digit code called the European Article 
         Number (EAN) instead of the 12-digit Universal Product Code (UPC) used in North America. Each EAN ends with a check digit, just like UPC codes. The technique for calculating the check digit is similar:

         Add the second, fourth, sixth, eighth, tenth, and twelfth digits.
         Add the first, third, fifth, seventh, ninth, and eleventh digits.
         Multiply the first sum by 3 and add it to the second sum.
         Calculate the remainder obtained when the modified total is divided by 10.
         Subtract the remainder from 9.

         Your task is to modify the upc.c program to calculate the check digit of an EAN code. The user will enter the first 12 digits of the EAN code as a single number:
         
         Enter the first 12 digits of an EAN: 869148426000
         Check digit: 8
         
*/

#include <stdio.h>

int main(void) {

    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, first_sum,
        second_sum, total, result;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6,
          &n7, &n8, &n9, &n10, &n11, &n12);

    first_sum = n2 + n4 + n6 + n8 + n10 + n12;
    second_sum = n1 + n3 + n5 + n7 + n9 + n11;
    total = first_sum * 3 + second_sum;
    result = 9 - (total - 1) % 10;

    printf("Check digit: %d\n", result);

    return 0;
}