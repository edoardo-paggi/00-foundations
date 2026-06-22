/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: modify the program interests.c to calculate compound interest monthly 
         instead of annually. The output format should not change; the balance 
         should still be displayed in annual intervals.
*/

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void) {

    int low_rate, num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (int i = 0; i < NUM_RATES; i++) {
        printf("%10d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d  ", year);
        for (int i = 0; i < NUM_RATES; i++) {
            for (int j = 1; j <= 12; j++) {
                value[i] += (low_rate + i) / 100.0 * value[i];
            }
            printf("%11.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}