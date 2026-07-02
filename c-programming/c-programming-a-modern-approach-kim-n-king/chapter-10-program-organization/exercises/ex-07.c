/*
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a number and then 
         displays that number using characters to simulate the effect of a seven-segment display:
         
         Enter a number: 491-9014
              _      _   _
         |_| |_|  | |_| | |  | |_|
           |  _|  |  _| |_|  |   |
         
         Characters other than digits should be ignored. Write the program so 
         that the maximum number of digits is controlled by the MAX_DIGITS 
         macro, which should have a value of 10. If the number to be displayed 
         contains more than this number, the extra digits should be ignored.
*/

#include <stdio.h>

#define MAX_DIGITS 10
#define ROWS 3
#define SEGMENTS 7

char segment_array[MAX_DIGITS][SEGMENTS] = 
    {{'_', '|', '|', '_', '|', '|', ' '},   // 0
     {' ', '|', '|', ' ', ' ', ' ', ' '},   // 1
     {'_', '|', ' ', '_', '|', ' ', '_'},   // 2
     {'_', '|', '|', '_', ' ', ' ', '_'},   // 3
     {' ', '|', '|', ' ', ' ', '|', '_'},   // 4
     {'_', ' ', '|', '_', ' ', '|', '_'},   // 5
     {'_', ' ', '|', '_', '|', '|', '_'},   // 6
     {'_', '|', '|', ' ', ' ', ' ', ' '},   // 7
     {'_', '|', '|', '_', '|', '|', '_'},   // 8
     {'_', '|', '|', '_', ' ', '|', '_'}};  // 9
     
char digits[ROWS][MAX_DIGITS * (ROWS + 1)];
int buffer[MAX_DIGITS];

void clear_digits_array(void);
void process_digit();
void print_digits_array(void);

int main(void) {

    printf("Enter a number: ");

    clear_digits_array();

    process_digit();

    print_digits_array();

    return 0;
}

void clear_digits_array(void) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < MAX_DIGITS * (ROWS + 1); j++) 
            digits[i][j] = ' ';
}

void process_digit() {
    char ch, ch_pos;
    int offset = 0, count_buffer = 0;
    int digit;

    int i = 0;
    while ((ch = getchar()) != '\n' && i < MAX_DIGITS) {
        if (ch >= '0' && ch <= '9') {
            buffer[i] = ch - '0';
            i++;
            count_buffer++;
        }
    }

    for (int i = 0; i < count_buffer; i++) {
        digit = buffer[i];

        for (int j = 0; j < ROWS; j++) {
            for (int k = offset; k < (ROWS + 1 + offset); k++) {
                if (j == 0 && k == offset + 1)
                    ch_pos = 0;
                else if (j == 1 && k == offset)
                    ch_pos = 5;
                else if (j == 1 && k == offset + 1)
                    ch_pos = 6;
                else if (j == 1 && k == offset + 2)
                    ch_pos = 1;
                else if (j == 2 && k == offset)
                    ch_pos = 4;
                else if (j == 2 && k == offset + 1)
                    ch_pos = 3;
                else if (j == 2 && k == offset + 2)
                    ch_pos = 2;
                else 
                    continue;

                digits[j][k] = segment_array[digit][ch_pos];
            }
        }

        offset += 4;
    }
}

void print_digits_array(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < MAX_DIGITS * (ROWS + 1); j++) {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}