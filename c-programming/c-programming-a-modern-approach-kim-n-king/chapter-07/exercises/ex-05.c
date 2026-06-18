/*
 * Name: ex-05.c
 * Author: Edoardo Paggi
 * Task: in the game of SCRABBLE, players form words using small tiles, each 
         containing a letter and a value. The values ​​of these tiles vary from 
         letter to letter based on the rarity of the letter itself (the letter 
         values ​​in the English version of the game are: 1:AEILNORSTU, 2:DG, 
         3:BCMP, 4:FHVWY, 5:K, 8:JX, 10:QZ). Write a program that calculates 
         the value of a word by adding the values ​​associated with its 
         letters:
         
         Enter a word: pitfall
         Scrabble value: 12
         
         Your program must allow a mixture of lowercase and uppercase letters 
         within the word.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch;
    int value = 0;

    printf("\nEnter a word: ");

    while ((ch = getchar()) != '\n') {
        switch(toupper(ch)) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case 'O': case 'R': case 'S': case 'T': case 'U':
                value += 1; break;

            case 'D': case 'G': 
                value += 2; break;

            case 'B': case 'C': case 'M': case 'P':
                value += 3; break;

            case 'F': case 'H': case 'V': case 'W': case 'Y':
                value += 4; break;

            case 'K':
                value += 5; break;

            case 'J': case 'X':
                value += 8; break;

            case 'Q': case 'Z':
                value += 10; break;
        }
    }

    printf("Scrabble value: %d\n\n", value);

    return 0;
}