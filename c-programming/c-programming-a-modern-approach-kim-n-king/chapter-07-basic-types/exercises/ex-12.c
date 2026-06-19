/* 
 * Name: ex-12.c
 * Author: Edoardo Paggi
 * Task: write a program that evaluates an expression:
         
         Enter an expression: 1+2.5*3
         Value of expression: 10.5
         
         The operands of the expression are floating-point numbers. The 
         operators are +, -, *, and /. The expression is evaluated from left to 
         right (no operator takes precedence over the others). Numbers and 
         operators without spaces.
*/

#include <stdio.h>

int main(void) {

    char op;
    float number, result = 0.0f;

    printf("Enter an expression: "); 

    scanf("%f", &number); 
    result += number;

    for (;;) {
        op = getchar(); 

        if (op == '\n')
            break;

        scanf("%f", &number);

        switch (op) {
            case '+': result += number; break;
            case '-': result -= number; break;
            case '*': result *= number; break;
            case '/': result /= number; break;
        }
    }

    printf("Value of expression: %g\n", result);

    return 0;
}