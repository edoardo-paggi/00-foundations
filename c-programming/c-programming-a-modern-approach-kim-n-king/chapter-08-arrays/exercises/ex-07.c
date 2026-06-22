/*
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: write a program that reads a 5x5 array of integers and then prints the 
         sum of the rows and columns:
         
         Enter row 1: 8 3 9 0 10
         Enter row 2: 3 5 17 1 1
         Enter row 3: 2 8 6 23 1
         Enter row 4: 15 7 3 2 9
         Enter row 5: 6 14 2 6 0

         Row totals: 30 27 40 36 28
         Column totals: 34 37 37 32 21
         
*/

#include <stdio.h>

#define N 5

int main(void) {

    int a[N][N] = {{0}};
    int rows[N] = {0}, cols[N] = {0};

    for (int i = 0; i < N; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nRow totals: ");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rows[i] += a[i][j];
            cols[i] += a[j][i]; 
        }
        printf("%d ", rows[i]);

    }
    printf("\n");

    printf("Column totals: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", cols[i]);
    }
    printf("\n");

    return 0;
}