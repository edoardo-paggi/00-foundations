/* 
 * Name: ex-08.c
 * Author: Edoardo Paggi
 * Task: write a program that prints a calendar for a month. The user must 
         specify the number of days in the month and the day of the week on which the month begins:
         
         Enter number of days in month: 31
         Enter starting day of the week (1=Sun, 7=Sat): 3
         
                      1     2     3     4     5
          6     7     8     9    10    11    12
         13    14    15    16    17    18    19
         20    21    22    23    24    25    26
         27    28    29    30    31
         
*/

#include <stdio.h>

int main(void) {

    int number_days, day_week, last_day;

    printf("\nEnter number of days in month: ");
    scanf("%d", &number_days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &day_week);

    last_day = 7 - day_week + 1;

    // First line
    for (int j = 1; j < day_week; j++)
        printf("  \t");

    // Solve
    for (int i = 1; i <= number_days; i++) {
        printf("%2d\t", i);

        if (i == last_day || i == last_day + 7 || i == last_day + 14 ||
            i == last_day + 21 || i == last_day + 28)
            printf("\n");
    }
    printf("\n");

    return 0;
}