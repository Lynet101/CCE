/*  Opgave 1.10 - "Cirkel areal beregner"
    September 05 - 2024 @ 13:20
    radius_calc.c - V2.2

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>

#define PI 3.141592653589793

//function declarations
void area_fn(double radius);
void circumference(double radius);
void sphere(double radius);
void cylinder(double radius);
double get_radius();
double pov(double x, int y);

int main(void){
	printf("///////////////////////////////////////////////\n");
	printf("            Welcome to circle calc!\nYour one stop calculator for everything circular\n");
	printf("///////////////////////////////////////////////\n\n");
	
	int choice;
	printf("(1)Circumference\n(2)Area\n(3)volume of sphere\n(4)volume of cylinder\n");
	printf("Please enter mode: ");
	scanf("%d", &choice);
	double radius = get_radius();

	switch (choice) {
		case 1:
			circumference(radius);
			break;
		case 2:
			area_fn(radius);
			break;
		case 3:
			sphere(radius);
			break;
		case 4:
			cylinder(radius);
			break;
	}
	return 0;
}

double get_radius(void){
	double radius;
	printf("\nPlease enter the radius of the circle: ");
	scanf("%lf", &radius);
	
	if (radius < 0.0) {
		printf("Invalid radius. Please enter a positive number.");
		return 0.0;
	}
	else {return radius;}
}

void area_fn(double radius) {
	printf("\nArea:\nPi * radius²");
	printf(" = %.2f * %.2f²\n", PI, radius);
	printf(" = %.5f", PI * radius * radius);
}

void circumference(double radius) {
	printf("\nCircumference:\n2 * PI * radius");
	printf("= 2 * %.2f * %.2f", PI, radius);
	printf("= %.5f\n", 2 * PI * radius);
}

void sphere(double radius){
	printf("\nSphere:\n4/3 * PI * radius³");
	printf(" = 4/3 * %.2f * %.2f³", PI, radius);
	printf(" = %.5f\n", (4.0/3.0 * PI * pov(radius, 3)));
}

void cylinder(double radius){
	double height;
	printf("\nenter height: \n");
	scanf("%lf", &height);

	printf("\nCylinder:\nPi * radius² * height");
	printf(" = %.2f * %.2f² * %.2f", PI, radius, height);
	printf(" =%.5f", (pov(radius, 2) * height * PI));
}

double pov(double x, int y){
	double accumulator = 1.0;
	for (int i = 0; i < y; i++){accumulator *= x;}
	return accumulator;
}