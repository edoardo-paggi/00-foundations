/* 
 * Name: ex-14.c
 * Author: Edoardo Paggi
 * Task: write a program that uses Newton's method to calculate the square root 
         of a positive floating-point number:
         
         Enter a positive number: 3
         Square root: 1.73205
         
         Let x be a user-entered number. Newton's method requires an initial 
         estimate of y from the square root of x (we'll use y = 1). Subsequent 
         estimates are found by averaging y and x/y. The following table 
         illustrates how the square root of 3 is found:
         
         x          y           x/y         Average of y and x/y
         ---------------------------------------------------
         3          1           3           2
         3          2           1.5         1.75
         3          1.75        1.71429     1.73214
         3          1.73214     1.73196     1.73205
         3          1.73205     1.73205     1.73205
         
         Notice that the y values ​​get progressively closer to the true root of
         x. For greater precision, your program should use double variables 
         instead of float variables. The program should terminate when the 
         absolute value of the difference between the old y value and the new y 
         value is less than the product of 0.00001 and y. Hint: Use the fabs 
         function to find the absolute value of a double. (To use the fabs 
         function, you'll need to include the <math.h> header at the beginning 
         of your program).       
*/       

#include <stdio.h>
#include <math.h>

int main(void) {

    double x, y = 1.0, ratio, average;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    ratio = x / y; 
    average = (y + ratio) / 2; 

    while (fabs(y - average) >= 0.00001 * y) { 
        y = average; 
        ratio = x / y; 
        average = (y + ratio) / 2;
    }

    printf("Square root: %.15f\n", average);

    return 0;
}