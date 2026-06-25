/*
 * Name: ex-15.c
 * Author: Edoardo Paggi
 * Task: the Caesar cipher, attributed to Julius Caesar, is one of the oldest 
         cryptographic techniques and is based on replacing each letter in a 
         message with another letter a fixed number of positions further down 
         the alphabet. (If shifting a letter past Z causes the cipher to "roll 
         up," starting again at the beginning of the alphabet. For example, if 
         each letter is replaced by the one two positions further down, then Y 
         would be replaced by A, while Z would be replaced by B.) Write a 
         program that encrypts a message using the Caesar cipher. The user will 
         enter the message to be encrypted and the shift (the number of 
         positions through which the letters should be shifted):
         
         Enter message to be encrypted: Go ahead, make my day.
         Enter shift amount (1-25): 3
         Encrypted message: Jr dkhdg, pdnh pb gdb.
         
         Note that the program can decrypt the message if the user enters a 
         value equal to 26 minus the original key:
         
         Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
         Enter shift amount (1-25): 23
         Encrypted message: Go ahead, make my day.
         
         You can assume the message doesn't exceed 80 characters. Non-letter 
         characters should be left as is. Lowercase letters remain lowercase 
         even when encrypted, and uppercase letters remain uppercase.
*/

#include <stdio.h>

#define BUFFER 80

int main(void) {

    char ch;
    char message[BUFFER] = {0};
    int key;

    printf("Enter message to be encrypted: ");

    ch = getchar();
    for (int i = 0; i < BUFFER; i++) {
        message[i] = ch;

        if (ch == '\n')
            break;

        ch = getchar();
    }

    printf("Enter shift amount (1-25): ");

    for (;;) {
        scanf("%d", &key);

        if (key < 1 || key > 25) 
            printf("ERROR! The key must be between 1 and 25. Try again: ");
        else
            break;
    }

    // Solve
    for (int i = 0; i < BUFFER; i++) {
        if (message[i] == '\n')
            break;

        if (message[i] >= 'A' && message[i] <= 'Z') 
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        else if (message[i] >= 'a' && message[i] <= 'z')
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
    }

    printf("Encrypted message: ");
    for (int i = 0; i < BUFFER; i++) {

        if (message[i] == '\n' || message[i] == 0)
            break;

        putchar(message[i]);
    }
    putchar('\n');

    return 0;
}