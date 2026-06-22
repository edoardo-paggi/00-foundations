/*
 * Name: ex-06.c
 * Author: Edoardo Paggi
 * Task: the stereotype of an Internet newbie is a guy named B1FF, who has only 
         one way of writing messages. Here's a typical B1FF post:
         
         H3Y DUD3, C 15 R1LLY COOL!!!!!!!!!!
         
         Write a "B1FF filter" that reads a user-entered message and translates 
         it into B1FF's typing:
         
         Enter a message: Hey dude, C is rilly cool
         In B1FF-speak: H3Y DUD3, C 15 R1LLY COOL!!!!!!!!!!
         
         The program must convert the message to uppercase letters and replace 
         certain letters with digits (A=>4, B=>8, E=>3, I=>1, O=>0, S=>5). Ten 
         exclamation points must be inserted at the end of the message.
*/

#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 25

int main(void) {

    char message[BUF_SIZE] = {0};
    char ch;

    printf("Enter a message: ");
    int i = 0;
    while ((ch = getchar()) != '\n') {
        message[i] = ch;
        i++;
    }
    message[i] = ch;

    printf("In B1FF-speak: ");
    for (int i = 0; message[i] != '\n'; i++) {
        message[i] = toupper(message[i]);
        switch(message[i]) {
            case 'A': message[i] = '4'; break;
            case 'B': message[i] = '8'; break;
            case 'E': message[i] = '3'; break;
            case 'I': message[i] = '1'; break;
            case 'O': message[i] = '0'; break;
            case 'S': message[i] = '5'; break;
        }
        putchar(message[i]);
    }
    printf("!!!!!!!!!!\n");

    return 0;
}