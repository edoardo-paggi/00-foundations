/*
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: rite a program that finds the minimum and maximum of four numbers 
         entered by the user:
         
         Enter four integers: 21 43 10 35
         Largest: 43
         Smallest: 10
         
         Use as few instructions as possible.
*/

#include <stdio.h>

int main(void) {

    int n1, n2, n3, n4, smallest, largest;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    smallest = n1;
    largest = n4;

    if (n2 < n1 && n2 < n3 && n2 < n4)
        smallest = n2;
    else if (n3 < n1 && n3 < n2 && n3 < n4)
        smallest = n3;
    else if (n4 < n1 && n4 < n2 && n4 < n3)
        smallest = n4;

    if (n1 > n2 && n1 > n3 && n1 > n4)
        largest = n1;
    else if (n2 > n1 && n2 > n3 && n2 > n4)
        largest = n2;
    else if (n3 > n1 && n3 > n2 && n3 > n4)
        largest = n3;

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}