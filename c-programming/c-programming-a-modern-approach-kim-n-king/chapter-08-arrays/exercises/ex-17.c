/*
 * Name: ex-17.c
 * Author: Edoardo Paggi
 * Task: Write a program that prints an n x n magic square (a square of numbers 
         1, 2, ..., n^2 where the sum of the rows, columns, and diagonals is always the same). The user will specify the value of n:
         
         This program creates a magic square of a specific size.
         The size must be an odd number between 1 and 99.
         Enter the size of magic square: 5
         17  24   1   8  15
         23   5   7  14  16
          4   6  13  20  22
         10  12  19  21   3
         11  18  25   2   9
         
         Store the magic square in a two-dimensional array. Start by placing 
         the number 1 in the middle of row 0. Arrange the remaining numbers 2, 
         3, ..., n^2 by moving up one row and one column. Any attempt to go 
         outside the bounds of the array must "roll" onto the opposite face of 
         the array. For example, instead of storing the next number in row -1, 
         we would store it in row n - 1 (the last row). Instead of storing the 
         next number in column n, we would store it in column 0. If a 
         particular array element is already occupied, place the number 
         immediately below the previously stored number. If your compiler 
         supports variable-length arrays, declare an array with n rows and n 
         columns. Otherwise, declare the array to have 99 rows and 99 columns.
*/

#include <stdio.h>

int main(void) {

    int n, value = 1;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd numebr between 1 and 99.\n");
    printf("Enter the size of magic square: ");
    
    for (;;) {
        scanf("%d", &n);
        if (n % 2 == 0 || n < 1 || n > 99) 
            printf("ERROR! The size must be an odd number between 1 and 99. "
                   "Try again: ");
        else 
            break;
    }

    // Initialize square
    int square[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = 0;
        }
    }

    // Solve
    square[0][n / 2] = value;
    value++;

    for (int i = 0, j = n / 2; value <= n * n; ) {
        i--;
        j++;
        
        if (i < 0) i = n - 1;
        if (j > n - 1) j = 0;

        if (square[i][j] != 0) {
            if (i == n - 1) i = 0;
            else i++;

            if (j == 0) j = n - 1;
            else j--;

            i++;
            square[i][j] = value;
            
            value++;
        } else {
            square[i][j] = value;
            value++;
        }
    }

    // Print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d  ", square[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}