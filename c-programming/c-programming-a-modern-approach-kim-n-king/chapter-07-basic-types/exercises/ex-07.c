/*
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 6 in Chapter 3 so that it adds, subtracts, 
         multips, or divides two fractions by entering +, -, *, or / between the fractions.
*/

#include <stdio.h>

int main(void) {

    char op;
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter two fractions separated by an operator sign: ");
    scanf("%d / %d %c %d / %d", &num1, &denom1, &op, &num2, &denom2);

    switch(op) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
        case '/':
            result_num = num1 * denom2;
            result_denom = denom1 * num2;
            break;
    }

    int m = result_num, n = result_denom, gcd, rest;

    // Hypothesis: m > n
    if (n > m) {
        int temp = m;
        m = n;
        n = temp;
    }

    // Euclid's Algorithm
    for (;;) {
        if (n == 0) {
            gcd = m;
            break;
        } else
            rest = m % n;

        m = n;
        n = rest;
    }

    result_num /= gcd;
    result_denom /= gcd;

    if (result_denom == 1)
        printf("The result is %d\n", result_num);
    else    
        printf("The result is %d/%d\n", result_num, result_denom);

    return 0;
}