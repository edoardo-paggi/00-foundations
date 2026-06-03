/*
 * Name: ex-05
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter the numbers 1 through 
         16 (in any order) and then displays them in a 4 x 4 matrix. The matrix should be followed by the sum of the rows, columns, and diagonals.
         
         Enter the numbers from 1 to 16 in any order:
         16 3 2 13 5 10 11 8 9  7 12 4 15 14 1
         16  3  2 13
          5 10 11  8
          9  6  7 12
          4 15 14  1

         Row sums: 34 34 34 34
         Column sums: 34 34 34 34
         Diagonal sums: 34 34

         If the sums of the rows, columns, and diagonals are identical (as in this example), the numbers are said to form a so-called magic square. The magic square illustrated in the example appears in a 1514 engraving by the artist and mathematician Albrecht Dürer (note that the central numbers in the last row correspond to the date of the engraving).
 */

#include <stdio.h>

int main(void) {

    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
    int r1, r2, r3, r4, c1, c2, c3, c4, d1, d2;

    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &n1, &n2, &n3, &n4,
          &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);

    printf("%d %d %d %d\n", n1, n2, n3, n4);
    printf("%d %d %d %d\n", n5, n6, n7, n8);
    printf("%d %d %d %d\n", n9, n10, n11, n12);
    printf("%d %d %d %d\n", n13, n14, n15, n16);

    r1 = n1 + n2 + n3 + n4;
    r2 = n5 + n6 + n7 + n8;
    r3 = n9 + n10 + n11 + n12;
    r4 = n13 + n14 + n15 + n16;

    c1 = n1 + n5 + n9 + n13;
    c2 = n2 + n6 + n10 + n14;
    c3 = n3 + n7 + n11 + n15;
    c4 = n4 + n8 + n12 + n16;

    d1 = n1 + n6 + n11 + n16;
    d2 = n4 + n7 + n10 + n13;

    printf("\nRow sums: %d %d %d %d\n", r1, r2, r3, r4);
    printf("Column sums: %d %d %d %d\n", c1, c2, c3, c4);
    printf("Diagonal sums: %d %d\n", d1, d2);

    return 0;
}