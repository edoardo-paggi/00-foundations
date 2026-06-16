/*
 * Name: ex-06.c
 * Author: Edoardo Paggi
 * Task: write a program that prompts the user to enter a number n and then 
         prints all even squares between 1 and n. For example, if the user 
         enters 100, the program should print the following result:
         
           4
          16
          36
          64
         100
         
*/

#include <stdio.h>

int main(void) {

    int n;

    printf("Enter a number n: ");
    scanf("%d", &n);

    for (int i = 1; i * i <= n; i++) {

        if ((i * i) % 2 != 0)
            continue;

        printf("%d\n", i * i);
    }

    return 0;
}