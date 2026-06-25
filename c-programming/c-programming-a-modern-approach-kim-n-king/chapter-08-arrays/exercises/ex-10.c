/*
 * Name: ex-10.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 8 in Chapter 5 so that departure times are  
         stored in one array and arrival times are stored in a second array 
         (the times are integers representing the number of minutes since 
         midnight). The program should use a loop to search the departure times 
         array for the one closest to the time entered by the user.
*/

#include <stdio.h>

#define SIZE 8
#define D1 (8 * 60)
#define D2 (9 * 60 + 43)
#define D3 (11 * 60 + 19)
#define D4 (12 * 60 + 47)
#define D5 (14 * 60)
#define D6 (15 * 60 + 45)
#define D7 (19 * 60)
#define D8 (21 * 60 + 45)
#define A1 (10 * 60 + 16)
#define A2 (11 * 60 + 52)
#define A3 (13 * 60 + 31)
#define A4 (15 * 60)
#define A5 (16 * 60 + 8)
#define A6 (17 * 60 + 55)
#define A7 (21 * 60 + 20)
#define A8 (23 * 60 + 58)
#define MIDNIGHT (24 * 60)

int main(void) {

    int dep[SIZE] = {D1, D2, D3, D4, D5, D6, D7, D8};
    int arr[SIZE] = {A1, A2, A3, A4, A5, A6, A7, A8};
    int hours, minutes, time_minutes, time_dep, time_arr,
        hours_dep, minutes_dep, hours_arr, minutes_arr;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    time_minutes = hours * 60 + minutes;

    printf("Closest departure time is ");

    /* 9:45 pm <=> 8:00 am
       (MIDNIGHT - D8) minutes pass from 9:45 pm to 12:00 am
       D1 minutes pass from 12:00 am to 8:00 am
       Total minutes spent: MIDNIGHT - D8 + D1
       Half the minutes passed: (MIDNIGHT - D8 + D1) / 2

       Half is 307 minutes.
       minutes. D1 - 307 = 480 - 173 = 2:52 am.

       D2 - D1 = 103 / 2 = 51.
       D1 + 51 = 480 + 51 = 531 = 8:51 am

       First interval: 2:52 am <=> 8:51 am
    */

    int i;

    if (time_minutes < dep[0] - (MIDNIGHT - dep[SIZE - 1] + dep[0]) / 2) {
        time_dep = dep[SIZE - 1];
        time_arr = arr[SIZE - 1];
    } else {
        for (i = 0; i < SIZE - 1; i++) {
            if (time_minutes <= dep[i] + (dep[i + 1] - dep[i]) / 2) {
                time_dep = dep[i];
                time_arr = arr[i];
                break;
            }
        }

        /* If it hasn't exited the cycle, it means that the time is after the 
           last midpoint. */
        if (i == SIZE - 1) {
            time_dep = dep[SIZE - 1];
            time_arr = arr[SIZE - 1];
        }
    }

    // Convert hours
    hours_dep = time_dep / 60;
    minutes_dep = time_dep % 60;
    hours_arr = time_arr / 60;
    minutes_arr = time_arr % 60;

    printf("%d:%02d, arriving at %d:%02d\n", hours_dep, minutes_dep,
           hours_arr, minutes_arr);

    return 0;
}