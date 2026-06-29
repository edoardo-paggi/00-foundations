/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a series of internal 
         numbers (which will be stored in an array) and then sorts them by 
         calling the Selection_sort function. When given an array of n 
         elements, selection_sort should do the following:
         
         I. Find the largest element within the vector and then move it to the 
         last position in the vector.
         
         II. call recursively to sort the first n - 1 elements of the vector.
*/

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void) {

    int a[N];

    printf("Enter %d integer numbers: ", N);
    for (int i = 0; i < N; i++) 
        scanf("%d", &a[i]);

    selection_sort(a, N);

    printf("In sorted order: ");
    for (int i = 0; i < N; i++) 
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n) {
    int max = a[0], index = 0;

    if (n == 1) return;

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }

    // Swap 
    int temp = a[n - 1]; 
    a[n - 1] = a[index]; 
    a[index] = temp;

    selection_sort(a, n - 1);
}