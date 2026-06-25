/*
 * Name: ex-13.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 11 from Chapter 7 so that the program 
         labels its output:
         
         Enter a first and last name: Lloyd Fosdick
         You entered the name: Fosdick, L.
         
         The program will need to store the last name (but not the first name) in a character array until it's printed. You can assume the last name is no longer than 20 characters.
*/

#include <stdio.h>
#include <ctype.h>

#define BUFFER 20

int main(void) {

    char ch, name_init;
    char surname[BUFFER] = {0};

    printf("Enter a first and last name: ");

    ch = getchar();
    if (ch == ' ') {
        while (ch == ' ') {
            ch = getchar();
        }
    } 
    
    name_init = ch;

    while ((ch = getchar()) != ' ')
        ;

    while (ch == ' ') {
        ch = getchar();
    }

    surname[0] = toupper(ch);
    ch = getchar();
    for (int i = 1; ch != '\n'; i++) {
        surname[i] = tolower(ch);
        ch = getchar();
    }

    // Print
    printf("You entered the name: ");
    for (int i = 0; i < BUFFER; i++) {
        if (surname[i] == 0)
            break;
        
        printf("%c", surname[i]);
    }
    printf(", %c.\n", toupper(name_init));     

    return 0;
}