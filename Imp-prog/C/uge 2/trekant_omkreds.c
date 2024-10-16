/*  Triangle circumference calculator
    September 11 2024 @ 13:00
    trekant_omkreds.c v1
    
    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <math.h>

int main(void) {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates for the triangle (x1, y1) (x2, y2) (x3, y3): ");
    scanf("(%lf,%lf) (%lf,%lf) (%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3);

    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    printf("The circumference of the triangle is: %.2lf\n", side1 + side2 + side3);
    return 0;
}