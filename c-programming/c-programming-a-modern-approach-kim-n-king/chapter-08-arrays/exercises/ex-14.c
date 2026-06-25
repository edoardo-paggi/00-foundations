/*
 * Name: ex-14.c
 * Author: Edoardo Paggi
 * Task: write a program that reverses the words in a sentence:
         
         Enter a sentence: you can cage a swallow can't you?
         Reversal of sentence: you can't swallow a cage can you?
         
*/

#include <stdio.h>

#define BUFFER 256

int main(void) {

    char ch, final_char;
    char sentence[BUFFER] = {0};
    char answer[BUFFER] = {0};
    int word_size = 0, index = 0;

    printf("Enter a sentence: "); 

    ch = getchar();
    for (int i = 0; i < BUFFER; i++) {
        if (ch == '\n') 
            break;

        if (ch == '.' || ch == '?' || ch == '!') {
            sentence[i] = ch;
            final_char = ch;
            break;
        }

        sentence[i] = ch;
        ch = getchar();
    }

    for (int i = BUFFER - 1; i >= 0; i--) {
        if (sentence[i] == 0 || sentence[i] == '\n' ||
            sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
                continue;
        
        if (i == 0 && sentence[i] != ' ') {
            int k = 0;
            for (int j = 0; j < word_size + 1; j++) {
                answer[index] = sentence[k];
                index++;
                k++;
            }
            break;
        }

        if (sentence[i] != ' ') {
            word_size++;
            continue;
        } else {
            int k = i + 1;
            for (int j = 0; j < word_size; j++) {
                answer[index] = sentence[k];
                index++;
                k++;
            }
            answer[index] = ' ';
            index++;
        }
        
        word_size = 0;
    }

    // Print
    for (int i = 0; i < BUFFER; i++) {
        if (answer[i] == 0) 
            break;
        
        printf("%c", answer[i]);
    }
    printf("%c\n", final_char);

    return 0;
}