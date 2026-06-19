/*
 * Name: ex-10.c
 * Author: Edoardo Paggi
 * Task: write a program that counts the number of vowels in a sentence:
         
         Enter a sentence: And that's the way it is.
         Your sentence contains 6 vowels.
         
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch;
    int count = 0;

    printf("Enter a sentence: ");

    while ((ch = toupper(getchar())) != '\n') {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
            count++;
    }

    printf("Your sentence contains ");
    if (count == 1)
        printf("1 vowel.\n");
    else 
        printf("%d vowels.\n", count);

    return 0;
}