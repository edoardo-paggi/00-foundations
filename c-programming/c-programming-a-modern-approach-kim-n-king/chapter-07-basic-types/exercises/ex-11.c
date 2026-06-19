/*
 * Name: ex-11.c
 * Author: Edoardo Paggi
 * Task: write a program that takes a first and last name entered and prints 
         the last name, a comma, and the first initial followed by a period:
         
         Enter a first and last name: Lloyd Fosdick
         Fosdick, L.
         
         User input may contain additional spaces before the first name, 
         between the first name and last name, and after the last name.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch, init_name, init_surname;

    printf("Enter a first and last name: "); // buf = ..Lloyd...Fosdick...\n
    scanf(" %c", &init_name); // buf = loyd...Fosdick...\n

    while (getchar() != ' ') // Skip the other letters of the name
        ;

    scanf(" %c", &init_surname); // buf = osdick...\n

    putchar(toupper(init_surname));

    ch = getchar();
    while (ch != ' ' && ch != '\n') {
        putchar(tolower(ch));
        ch = getchar();
    }

    printf(", %c.\n", init_name);

    return 0;
}