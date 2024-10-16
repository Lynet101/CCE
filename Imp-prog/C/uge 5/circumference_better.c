/*  circumference calc with seperate functions (like i didn't do this already 🙄)
    08/10/2024 @ 08:37
    circumference_better.c v1.2
    
    Sebastian Lindau-Skands
    slinda24@student.aau.dk */
#include <stdio.h>

double calculate_circumference(double radius);

int main() {
    double radius;
    printf("Circumference Calculator\nBy Sebastian Lindau-Skands");

    printf("\n\nEnter the radius of the circle: ");
    if (scanf("%lf", &radius) != 1 || radius < 0.0) {
        printf("Invalid input. Please enter a valid positive number.\n");
        return 1;
    }

    printf("The circumference of the circle is %.2f\n", calculate_circumference(radius));
    return 0;
}

double calculate_circumference(double radius) {
    return radius * (2 * 3.14159);
}