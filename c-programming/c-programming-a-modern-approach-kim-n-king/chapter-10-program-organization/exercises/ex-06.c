/*
 * Name: ex-06.c
 * Author: Edoardo Paggi
 * Task: some calculators (particularly those from Hewlett-Packard) use a 
         system for writing mathematical expressions known as Reverse Polish 
         Notation (RPN). In this notation, operators are placed after the 
         operands, not between them. For example, in RPN, 1 + 2 would be 
         written as 1 2 +, while 1 + 2 * 3 would be written as 1 2 3 * +. RPN 
         expressions can be easily calculated using a stack. The algorithm 
         involves reading the operators and operands within an expression in 
         left-to-right order, as well as the following operations:

             when an operand is encountered, it must be pushed onto the stack.

             When an operator is encountered, its operands must be removed from 
             the stack, the operation performed on those operands, and then the 
             result pushed onto the stack.

         Write a program that calculates RPN expressions. The operands will be 
         single-digit integers. The operators are: +, -, *, /, and =. The = 
         operator displays the top element of the stack, clears the stack, and 
         prompts the user for another expression. This process continues until 
         the user enters a character that is not an operator or operand:
         
         Enter an RPN expression: 1 2 3 * + =
         Value of expression: 7
         Enter an RPN expression: 5 8 * 4 9 - / =
         Value of expression: -8
         Enter an RPN expression: q
         
         If the stack overflows, the program should print the message 
         "Expression is too complex" and then exit. If the stack underflows 
         (due to an expression like 1 2 + +), the program should display the 
         message "Not enough operands in expression" and exit.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char buffer[STACK_SIZE];
int stack[STACK_SIZE];
int top = 0;

bool is_empty(void);
bool is_full(void);
void make_empty(void);
void fill_buffer();
void push(int n);
int pop(void);

int main(void) {
    char ch, first, second, result;

    for (;;) {
        printf("Enter an RPN expression: ");

        fill_buffer();

        for (int i = 0; i < STACK_SIZE; i++) {
            ch = buffer[i];

            if (ch >= '0' && ch <= '9') 
                push(ch - '0');
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                second = pop();
                first = pop();

                switch (ch) {
                    case '+': result = first + second; break;
                    case '-': result = first - second; break;
                    case '*': result = first * second; break;
                    case '/': result = first / second; break;
                }

                push(result);
            }
            
            if (ch == '=') {
                printf("Value of expression: %d\n", pop());
                make_empty();
                break;
            }
        }
    }

    return 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void make_empty(void) {
    top = 0;
}

void fill_buffer() {
    for (int i = 0; i < STACK_SIZE; i++) {
        buffer[i] = 0;
        stack[i] = 0;
    }
    top = 0;

    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n') {
        if ((ch >= '0' && ch <= '9') ||
            (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')) {
                buffer[i] = ch;
                i++;
            } else if (ch == ' ')
                continue;
            else exit(EXIT_SUCCESS);
    }
}

void push(int n) {
    if (is_full()) {
        printf("Expression is too complex!\n");
        exit(EXIT_FAILURE);
    } else {
        stack[top] = n;
        top++;
    }
}

int pop(void) {
    if (is_empty()) {
        printf("Not enough operands in expression!\n");
        exit(EXIT_FAILURE);
    } else {
        top--;
        return stack[top];
    }
}