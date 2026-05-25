/*
 * Name: ex-02.c
 * Author: Edoardo Paggi
 * Task: Write a program that calculates the volume of a sphere with a radius of
         10 meters using the formula v = 4/3PIr^3. Write the fraction 4/3
         as 4.0f/3.0f.
 */

#include <stdio.h>

#define PI 3.141592653f // float => only 3.141593

int main(void) {

    int radius = 10;
    float volume = (4.0f / 3.0f) * PI * (radius * radius * radius);

    printf("Volume of the sphere = %f\n", volume);

    return 0;
}