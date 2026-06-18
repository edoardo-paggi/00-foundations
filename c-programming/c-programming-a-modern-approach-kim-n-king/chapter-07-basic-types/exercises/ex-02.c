/* 
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: modify the program square2.c so that it pauses every 24 squares and 
         displays the following message:
         
         Press Enter to continue...
         
         After displaying the message, the program must use getchar to read a 
         character. The getchar function will prevent the program from 
         continuing until the user presses Enter.
*/

#include <stdio.h>

int main(void) {

    int n;

    printf("\nThis program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    while (getchar() != '\n')
        ; // Reads the entire line and flushes the buffer

    printf("\n");

    for (int i = 1; i <= n; i++) {
        if (i % 25 == 0) {
            printf("\nPress Enter to continue...");

            while (getchar() != '\n')
                ;

            printf("\n");
        }

        printf("%20d%20d\n", i, i * i);
    }

    return 0;
}