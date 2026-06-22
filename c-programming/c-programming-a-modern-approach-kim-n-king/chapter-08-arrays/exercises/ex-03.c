/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: modify the repdigit.c program so that the user can enter more than one 
         number to be scanned for repeating digits. The program should terminate when the user enters a number less than or equal to 0.
*/

#include <stdio.h>

int main(void) {

    int digit;
    long n, s;

    for (;;) {
        init_cicle:
            printf("Enter a number: ");
            scanf("%ld", &n);

            if (n <= 0)
                break;

            s = n;

            int digit_seen[10] = {0};

            while (s > 0) {
                digit = s % 10;
                digit_seen[digit]++;
                s /= 10;
            }

            for (int i = 0; i < 10; i++) {
                if (digit_seen[i] > 1) {
                    printf("Repeated digit(s): ");
                    for (int j = 0; j < 10; j++) {
                        if (digit_seen[j] > 1)
                            printf("%d ", j);
                    }
                    printf("\n");
                    goto init_cicle;
                }
            }

            printf("NO repeated digits!\n");
    }

    return 0;
}