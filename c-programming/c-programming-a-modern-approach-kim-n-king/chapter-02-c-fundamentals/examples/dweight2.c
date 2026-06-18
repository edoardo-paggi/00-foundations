/*
 * Name: dweight2.c
 * Author: Edoardo Paggi
 * Purpose: calculate the dimensional weight of a package from user input.
 */

#include <stdio.h>

int main(void) {

    int height, length, width, volume, weight;

    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);
    volume = height * length * width;
    weight = (volume + 165) / 166;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}