/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: modify programming project 2 so that it prompts the user to enter the
         radius of the sphere.
 */

#include <stdio.h>

#define PI 3.141592653f // float => only 3.141593

int main(void) {

    float radius, volume;

    printf("Enter the radius of the sphere in meters: ");
    scanf("%f", &radius);

    volume = (4.0f / 3.0f) * PI * (radius * radius * radius);

    printf("Volume of the sphere = %f\n", volume);

    return 0;
}