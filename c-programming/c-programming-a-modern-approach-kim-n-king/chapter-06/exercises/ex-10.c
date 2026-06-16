/*
 * Name: ex-10.c
 * Author: Edoardo Paggi
 * Task: in the Programming Project in Chapter 5, you were asked to write a 
         program that determines which of two dates comes first in the calendar. Generalize the program so that the user can enter any number of dates. The user should enter 0/0/0 to indicate that they will not enter any more dates:
         
         Enter a date (mm/dd/yy): 3/6/08
         Enter a date (mm/dd/yy): 5/17/07
         Enter a date (mm/dd/yy): 6/3/07
         Enter a date (mm/dd/yy): 0/0/0
         5/17/07 is the earliest date
         
*/

#include <stdio.h>

int main(void) {

    int mm, dd, yy, m_earlier = 12, d_earlier = 31, y_earlier = 99;

    for (;;) {
        printf("Enter first date: ");
        scanf("%d/%d/%d", &mm, &dd, &yy);

        if (mm == 0 && dd == 0 && yy == 0)
            break;

        if (yy > y_earlier)
            continue;
        else if (yy < y_earlier) {
            m_earlier = mm;
            d_earlier = dd;
            y_earlier = yy;
        } else {
            if (mm > m_earlier)
                continue;
            else if (mm < m_earlier) {
                m_earlier = mm;
                d_earlier = dd;
                y_earlier = yy;
            } else {
                if (dd >= d_earlier)
                    continue;
                else {
                    m_earlier = mm;
                    d_earlier = dd;
                    y_earlier = yy;
                }
            }
        }
    }

    printf("%d/%d/%.2d is the earliest date\n", m_earlier, d_earlier,
           y_earlier);

    return 0;
}