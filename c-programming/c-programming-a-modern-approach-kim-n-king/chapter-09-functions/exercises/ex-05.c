/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 17 in Chapter 8 to include the following 
         functions:
         
         void create_magic_square(int n, int magic_square[n][n]);
         void print_magic_square(int n, int magic_square[n][n]);
         
         After getting the number n from the user, the main function must call 
         the create_magic_square function, passing it an n x n vector declared 
         within the main function. The function will fill the vector with the 
         numbers 1, 2, ..., n^2 as described in the original project. Note: If 
         your compiler doesn't support variable-length vectors, then declare 
         the vector in the main function to have dimensions 99 x 99 instead of 
         n x n and use the following prototypes in place of the ones already 
         provided:
         
         void create_magic_square(int n, int magic_square[99][99]);
         void print_magic_square(int n, int magic_square[99][99]);
*/

#include <stdio.h>

void create_magic_square(int n, int magic_square[][n]);
void print_magic_square(int n, int magic_square[][n]);

int main(void) {

    int n;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd numebr between 1 and 99.\n");
    printf("Enter the size of magic square: ");
    
    for (;;) {
        scanf("%d", &n);
        if (n % 2 == 0 || n < 1 || n > 99) 
            printf("ERROR! The size must be an odd number between 1 and 99. "
                   "Try again: ");
        else break;
    }

    int square[n][n];

    create_magic_square(n, square);

    print_magic_square(n, square);

    return 0;
}

void create_magic_square(int n, int magic_square[][n]) {
    int value = 1;

    // Square initialization
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    // Solve
    magic_square[0][n / 2] = value;
    value++;

    for (int i = 0, j = n / 2; value <= n * n; ) {
        i--;
        j++;
        
        if (i < 0) i = n - 1;
        if (j > n - 1) j = 0;

        if (magic_square[i][j] != 0) {
            if (i == n - 1) i = 0;
            else i++;

            if (j == 0) j = n - 1;
            else j--;

            i++;
            magic_square[i][j] = value;
            
            value++;
        } else {
            magic_square[i][j] = value;
            value++;
        }
    }
}

void print_magic_square(int n, int magic_square[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            printf("%2d  ", magic_square[i][j]);

        printf("\n");
    }
    printf("\n");
}