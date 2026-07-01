/*
 * Name: ex-01.c
 * Author: Edoardo Paggi
 * Task: modify the stack example so that it stores characters instead of 
         integers. Then add a main function that prompts the user for a series of parentheses and/or braces. The program should indicate whether the parentheses are nested appropriately or not:
         
         Enter parentheses and/or braces: ((){}{()})
         Parentheses/braces are nested properly
         
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;

bool is_empty(void);
bool is_full(void);
void make_empty(void);
void push(char brace);
char pop(void);

int main(void) {
    char ch, brace;

    printf("Enter parentheses and/or braces: "); // ((){}{()})\n

    while ((ch = getchar()) != '\n') {
        if (ch == '(' || ch == '{')
            push(ch);
        
        if (ch == ')' || ch == '}') {
            brace = pop();
        }

        if ((ch == ')' && brace != '(') || (ch == '}' && brace != '{')) {
            printf("Parentheses/braces are not nested properly\n");
            return 0;
        }
    }

    printf("Parentheses/braces are ");
    if (is_empty)
        printf("nested properly\n");
    else 
        printf("not nested properly\n");

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

void push(char brace) { 
    if (is_full()) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    else {
        stack[top] = brace;
        top++;
    }
}

char pop(void) {
    if (is_empty()) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    } else {
        top--;
        return stack[top];
    }
} 