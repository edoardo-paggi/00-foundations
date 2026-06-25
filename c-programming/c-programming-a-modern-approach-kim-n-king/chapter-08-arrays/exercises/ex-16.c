/*
 * Name: ex-16.c
 * Author: Edoardo Paggi
 * Task: write a program that checks whether two words are anagrams (i.e., 
         permutations of the same letters):
         
         Enter first word: smartest
         Enter second word: mattress
         The words are anagrams.
         
         Enter first word: dumbest
         Enter second word: stumble
         The words are not anagrams.
         
         Write a loop that reads the first word character by character, using a 
         vector of 26 integers to keep track of the number of occurrences of 
         each letter. (For example, after the word smartest is read, the vector 
         should contain the values ​​1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 2 2 0 
         0 0 0 0, reflecting the fact that smartest contains one a, one e, one 
         m, one r, two s, and two t's.) Use another loop to read the second 
         word, but this time for each letter read, decrement the corresponding 
         element in the vector. Both loops should ignore non-letter characters, 
         and both should treat uppercase letters the same as lowercase letters. 
         After the second word is read, use a third loop to check if all 
         elements are equal to zero. If so, then the two words are anagrams.
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LETTERS 26

int main(void) {

    char ch;
    bool flag = false;
    int letters[LETTERS] = {0};

    printf("Enter first word: ");

    while ((ch = getchar()) != '\n') 
        letters[(tolower(ch) - 'a')]++;

    printf("Enter second word: "); 

    while ((ch = getchar()) != '\n') 
        letters[(tolower(ch) - 'a')]--;

    printf("The words are ");
    for (int i = 0; i < LETTERS; i++) {
        if (letters[i] != 0) {
            flag = true;
            break;
        }
    }

    if (flag)
        printf("not anagrams.\n");
    else    
        printf("anagrams.\n");

    return 0;
}