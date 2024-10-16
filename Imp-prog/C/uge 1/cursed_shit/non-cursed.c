/*  Opgave 1.9 - "Programmeringsstil"
    September 05 - 2024 @ 12:55
    non-cursed.c - V1

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>  

int main(void){
    float x, y, z;

    printf("Give me three numbers (comma seperated): ");
    scanf("%f, %f, %f", &x, &y, &z);

    printf("The accumulator: %f\n", (x + y + z) / 3.0);

    return 0;
}