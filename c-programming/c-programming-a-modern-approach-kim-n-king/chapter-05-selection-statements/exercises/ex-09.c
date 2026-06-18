/*
 * Name: ex-09.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user for two dates and tells them 
         which one is first in the calendar:
         
         Enter first date (mm/dd/yy): 3/6/08
         Enter second date (mm/dd/yy): 5/17/07
         5/17/07 is earlier than 3/06/08
         
*/

#include <stdio.h>

int main(void) {

    int m1, m2, d1, d2, y1, y2, m_earlier, d_earlier, y_earlier, m_later,
        d_later, y_later;

    printf("Enter first date: ");
    scanf("%d/%d/%d", &m1, &d1, &y1);
    printf("Enter second date: ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (y1 < y2) {
        m_earlier = m1;
        d_earlier = d1;
        y_earlier = y1;
    } else if (y2 < y1) {
        m_earlier = m2;
        d_earlier = d2;
        y_earlier = y2;
    } else { // y1 == y2
        if (m1 < m2) {
            m_earlier = m1;
            d_earlier = d1;
            y_earlier = y1;
        } else if (m2 < m1) {
            m_earlier = m2;
            d_earlier = d2;
            y_earlier = y2;
        } else { // m1 == m2
            if (d1 < d2) {
                m_earlier = m1;
                d_earlier = d1;
                y_earlier = y1;
            } else if (d1 < d1) {
                m_earlier = m2;
                d_earlier = d2;
                y_earlier = y2;
            } else {
                printf("The two dates are the same!\n");
                return 0;
            }
        }
    }

    if (m_earlier == m1) {
        m_later = m2;
        d_later = d2;
        y_later = y2;
    } else {
        m_later = m1;
        d_later = d1;
        y_later = y1;
    }

    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m_earlier, d_earlier,
           y_earlier, m_later, d_later, y_later);

    return 0;
}