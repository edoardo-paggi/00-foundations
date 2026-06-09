/*
 * Name: ex-08.c
 * Author: Edoardo Paggi
 * Task: the following table shows the daily flights between two cities:
 
         Departure time    Arrival time
          8:00 a.m.        10:16 a.m.
          9:43 a.m.        11:52 a.m.
         11:19 a.m.         1:31 p.m.
         12:47 p.m.         3:00 p.m.
          2:00 p.m.         4:08 p.m.
          3:45 p.m.         5:55 p.m.
          7:00 p.m.         9:20 p.m.
          9:45 p.m.         11:58 p.m.

          Write a program that prompts the user for a time (expressed in hours 
          and minutes using the 24-hour clock). The program should display the 
          departure and arrival times of the flight whose departure time is 
          closest to the time entered by the user:

          Enter a 24-hour time: 13:15
          Closest departure time is 12:47 p.m., arriving at 3:00 p.m.

*/

#include <stdio.h>

#define D1 (8 * 60)
#define D2 (9 * 60 + 43)
#define D3 (11 * 60 + 19)
#define D4 (12 * 60 + 47)
#define D5 (14 * 60)
#define D6 (15 * 60 + 45)
#define D7 (19 * 60)
#define D8 (21 * 60 + 45)
#define MIDNIGHT (24 * 60)

int main(void) {

    int hours, minutes, time_minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    time_minutes = hours * 60 + minutes;

    printf("Closest departure time is ");

    /* 9:45 pm <=> 8:am
       (MIDNIGHT - D8) minutes pass from 9:45 pm to 12:00 am
       D1 minutes pass from 12:00 am to 8:00 am
       Total minutes spent: MIDNIGHT - D8 + D1
       Half the minutes passed: (MIDNIGHT - D8 + D1) / 2

       Half is 307 minutes. MIDNIGHT - D8 equals 135 
       minutes. 307 - 135 = 172 = 2:52 am.

       D2 - D1 = 103 / 2 = 51.
       D1 + 51 = 480 + 51 = 531 = 8:51 am

       First interval: 2:52 am <=> 8:51 am
    */

    if (time_minutes >= 0 &&
        time_minutes < (MIDNIGHT - D8 + D1) / 2 - (MIDNIGHT - D8))
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
    else if (time_minutes < D1 + (D2 - D1) / 2)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (time_minutes < D2 + (D3 - D2) / 2)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (time_minutes < D3 + (D4 - D3) / 2)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (time_minutes < D4 + (D5 - D4) / 2)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (time_minutes < D5 + (D6 - D5) / 2)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (time_minutes < D6 + (D7 - D6) / 2)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (time_minutes < D7 + (D8 - D7) / 2)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}