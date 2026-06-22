/*
 * Name: ex-04.c
 * Author: Edoardo Paggi
 * Task: modify the reverse.c program to use the (int) sizeof(a) / sizeof(a[0]) 
         expression (or a macro with this value) to get the length of the 
         vector.
*/

#include <stdio.h>

#define N 10
#define SIZE ((int) sizeof(a) / sizeof(a[0]))

int main(void) {

    int a[N];

    printf("Enter %ld numbers: ", SIZE);
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");
    for (int i = SIZE - 1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}