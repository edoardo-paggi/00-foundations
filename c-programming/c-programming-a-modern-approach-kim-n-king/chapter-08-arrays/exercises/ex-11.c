/*
 * Name: ex-11.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 4 from Chapter 7 so that the program labels 
         its output:
         
         Enter phone number: 1-800-COL-LECT
         In numeric form: 1-800-265-5328
         
         The program will need to store the phone number (both in its original 
         and numeric form) in a character array until it can be printed. You 
         can assume the phone number is no longer than 15 characters.
*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 15

int main(void) {

    char original_phone[SIZE] = {0};
    char modified_phone[SIZE] = {0};
    char ch;

    printf("Enter phone number: ");

    ch = getchar();
    for (int i = 0; ch != '\n'; i++) {
        original_phone[i] = ch;
        ch = getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        ch = original_phone[i];
        ch = toupper(ch);
        
        switch (ch) {
            case 'A': case 'B': case 'C': ch = '2'; break;
            case 'D': case 'E': case 'F': ch = '3'; break;
            case 'G': case 'H': case 'I': ch = '4'; break;
            case 'J': case 'K': case 'L': ch = '5'; break;
            case 'M': case 'N': case 'O': ch = '6'; break;
            case 'P': case 'R': case 'S': ch = '7'; break;
            case 'T': case 'U': case 'V': ch = '8'; break;
            case 'W': case 'X': case 'Y': ch = '9'; break;
        }

        modified_phone[i] = ch;
    }

    for (int i = 0; i < SIZE; i++) {
        if (modified_phone[i] == 0)
            break;
        printf("%c", modified_phone[i]);
    }
    printf("\n");

    return 0;
}