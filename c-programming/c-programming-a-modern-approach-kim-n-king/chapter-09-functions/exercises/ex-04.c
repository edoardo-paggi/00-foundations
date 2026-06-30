/*
 * Name: ex-04.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 16 in Chapter 8 to use the following 
         functions:
         
         void read_word(int counts[26]);
         bool equal_array(int counts1[26], int counts2[26]);
         
         The main program will need to call read_word twice: once for each word 
         the user enters. As read_word reads the word, it uses the letters from 
         the word to update the counts vector as described in the original 
         project. (The main program declares two vectors, one for each word. 
         These vectors are used to track how many occurrences of each letter 
         exist within the words.) Next, the main program will need to call the 
         equal_array function, passing the two vectors to it. This function 
         will return true if the elements in the two vectors are the same 
         (indicating that the two words entered by the user are anagrams); 
         otherwise, it will return false.
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LETTERS 26

void read_word(int counts[]);
bool equal_array(int counts1[], int counts2[]);

int main(void) {
    int word1[LETTERS] = {0};
    int word2[LETTERS] = {0};

    printf("Enter first word: ");
    read_word(word1);
    printf("Enter second word: ");
    read_word(word2);

    printf("The words are ");

    if (equal_array(word1, word2))
        printf("anagrams.\n");
    else    
        printf("not anagrams.\n");

    return 0;
}

void read_word(int counts[]) {
    char ch;

    while ((ch = getchar()) != '\n') 
        counts[(tolower(ch) - 'a')]++;
}

bool equal_array(int counts1[], int counts2[]) {
    for (int i = 0; i < LETTERS; i++)
        if (counts1[i] != counts2[i])
            return false;

    return true;
} 