/*  Circumference calculator for polynomium with n-sides
    08-10-2024 @ 10:56
    n-gon_calc.c v1.3.0
    
    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <math.h>

double calc(double sides[][2], int n);
void get_points(double sides[][2], int n);

int main(void) {
    int n;
    printf("Enter amount of n-gons: ");
    if (scanf("%d", &n) != 1 || n < 3) {
        printf("Invalid input. Please enter a number greater than 2.");
        return 1;
    }

    double sides[n][2];
    get_points(sides, n);
    
    printf("%lf", calc(sides, n));
    return 0;
}

void get_points(double sides[][2], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates of vertex %d: ", i + 1);
        if (scanf("%lf, %lf", &sides[i][0], &sides[i][1]) != 2) {
            printf("Invalid input. Please enter valid coordinates.\n");
            i--;
            continue;
        }
        
        if (i > 0 && sides[i][0] == sides[i - 1][0] && sides[i][1] == sides[i - 1][1]) {
            printf("Duplicate vertex coordinates. Please enter unique values.\n");
            i--;
        }
    }
}

double calc(double sides[][2], int n) {
    double accumulator = 0.0;
    int j;
    for (int i = 0; i < n; i++) {
        int delta_x, delta_y;
        if (i == n - 1) {j = 0;}
        else {j = i + 1;}

        delta_x = sides[j][0] - sides[i][0];
        delta_y = sides[j][1] - sides[i][1];
        accumulator += sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    }
    return accumulator;
}