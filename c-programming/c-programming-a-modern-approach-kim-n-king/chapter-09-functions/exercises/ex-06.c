/*
 * Name: ex-06.c
 * Author: Edoardo Paggi
 * Task: write a function that calculates the value of the following 
         polynomial:
         
         3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
         
         Write a program that prompts the user to enter a value for x, which is 
         then passed to the function for calculation. Finally, the program 
         should display the value returned by the function.
*/

#include <stdio.h>

double calculate_polynomial(double x);

int main(void) {
    double x, ans;
    
    printf("Enter a number: ");
    scanf("%lf", &x);

    ans = calculate_polynomial(x);

    printf("Result: %g\n", ans);

    return 0;
}

double calculate_polynomial(double x) {
    return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6; 
}