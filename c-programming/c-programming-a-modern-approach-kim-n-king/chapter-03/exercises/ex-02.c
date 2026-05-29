/*
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: write a program that formats the information entered by the user. A
         program session should look like this:

         Enter item number: 583
         Enter unit price: 13.5
         Enter purchase date (mm/dd/yyyy): 10/24/2010

         Item           Unit            Purchase
                        Price           Date
         583            $   13.50       10/24/2010

         The item number and purchase date should be left-aligned, while the
         unit price should be right-aligned. Allow dollar amounts up to
         $9,999.99.

 */

#include <stdio.h>

int main(void) {

    int itemNumber, mm, dd, yyyy;
    float unitPrice;

    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    printf("Enter unit price: ");
    scanf("%f", &unitPrice);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("\nItem\t\t\tUnit\t\t\tPurchase\n");
    printf("    \t\t\tPrice\t\t\tDate\n");
    printf("%-d\t\t\t$%8.2f\t\t%.2d/%.2d/%.4d\n", itemNumber, unitPrice, mm, dd,
           yyyy);

    return 0;
}