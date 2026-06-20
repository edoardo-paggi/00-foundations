/*
 * Name: ex-13.c
 * Author: Edoardo Paggi
 * Task: write a program that calculates the average length of words in a 
         sentence:
         
         Enter a sentence: It was deja vu all over again.
         Average word length: 3.4
         
         For simplicity, the program should treat a punctuation mark as part of 
         the word to which it is attached. Print the average word length to one 
         decimal place.
*/

#include <stdio.h>

int main(void) { 

    char ch;
    int chars_not_spaces = 0, number_of_words = 0; 
    float word_lenght = 0.0f;

    printf("Enter a sentence: "); 

    ch = getchar(); 
    if (ch == ' ') {
        while ((ch = getchar()) == ' ') 
            ;
    }

    while (ch != '\n') { 
        while (ch != ' ' && ch != '\n') {
            chars_not_spaces++; 
            ch = getchar(); 
        }

        number_of_words++; 

        while (ch == ' ') { 
            ch = getchar(); 
        }
    }

    word_lenght = (float) chars_not_spaces / number_of_words;

    printf("Average word lenght: %.1f\n", word_lenght);

    return 0;
}