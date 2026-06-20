/* 
 * Name: ex-15.c
 * Author: Edoardo Paggi
 * Task: write a program that calculates the factorial of a positive integer:
         
         Enter a positive integer: 6
         Factorial of 6: 720
         
         a) Use a short variable to store the factorial value. What is the      
            largest number n for which the program correctly calculates the 
            factorial?
         b) Repeat part (a) using an int variable.
         c) Repeat part (a) using a long variable.
         d) Repeat part (a) using a long long variable.
         e) Repeat part (a) using a float variable.
         f) Repeat part (a) using a double variable.
         g) Repeat part (a) using a long double variable.
         
         In cases (e) to (g) the program will display an approximation of the 
         factorial, not necessarily the exact value.
*/

#include <stdio.h>

int main(void) {

    long double n, fact = 1.0;

    printf("Enter a positive integer: ");
    scanf("%Lf", &n);

    for (long double i = 1.0; i <= n; i++) {
        printf("%Lf\t", i);
        fact *= i;
        printf("%Lf\n", fact);
    }

    printf("Factorial of %Lf: %Lf\n", n, fact);

    return 0;
}

/*
 * SOLUTION
 *       short: max value is 7
 *         int: max value is 15 
 *        long: max value is 20 
 *   long long: max value is 20 
 *       float: max value is 34.0  
 *      double: max value is 170.0
 * long double: max value is 1754.0
*/