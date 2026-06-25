/*
 * Name: ex-12.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 5 from Chapter 7 so that the Scrabble 
         letter values ​​are stored in an array. This array will have 26 elements corresponding to the 26 letters of the alphabet. For example, element 0 of the array will contain a 1 (because the value of the letter A is 1), element 1 will contain a 3 (because the value of the letter B is 3), and so on. When a character from the input word is read, the program should use the array to determine the value. Use an initializer to construct the array.
*/

#include <stdio.h>
#include <ctype.h>

#define LETTERS 26

int main(void) {

    char ch;
    int letter_values[LETTERS] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1,
                                  3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int index, value = 0;

    printf("\nEnter a word: ");

    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        index = ch - 'A';
        value += letter_values[index];
    }
    
    printf("Scrabble value: %d\n\n", value);

    return 0;
}