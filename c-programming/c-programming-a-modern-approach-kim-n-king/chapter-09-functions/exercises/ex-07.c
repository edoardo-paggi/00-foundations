/*
 * Name: ex-07.c
 * Author: Edoardo Paggi
 * Task: the power function can be speeded up by calculating x^n in a different 
         way. First, note that if n is a power of 2, then x^n can be calculated 
         by squaring. For example, x^4 is the square of x^2, so x^4 can be 
         calculated with just two multiplications instead of three. This 
         technique can also be used when n is not a power of 2. If n is even, 
         then we use the formula x^n = (x^(n/2))^2. If n is odd, then x^n = x 
         times x^(n-1). Then, write a recursive function that calculates x^n 
         (the recursion ends when n = 0, in which case the function returns a 
         1). To test your function, write a program that prompts the user for 
         values ​​for x and n, calls the power function to calculate x^n, and 
         then prints the value returned by the function.
*/

#include <stdio.h>

int power(int x, int n);

int main(void) {
    int base, exp;

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exp);

    printf("%d^%d = %d\n", base, exp, power(base, exp));

    return 0;
}

int power(int x, int n) {
    int half;

    if (n == 0)
        return 1;
    else if (n % 2 == 0) {
        half = power(x, n / 2);
        return half * half;
    } else 
        return x * power(x, n - 1);
}