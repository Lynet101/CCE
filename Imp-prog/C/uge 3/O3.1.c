/*	A program to find if an (x, y) coordinate is inside, outside or on the periferal of a circle
 *	September 18 24 @ 11:00
 *	inside_outside.c V1.0
 *
 *	Sebastian Lindau-Skands
 *	slinda24@student.aau.dk */

#include <stdio.h>
#include <math.h>

int main(void) {
	double r, x, y;
	double delta = 0.1;

	printf("Please enter a radius: ");
	if (scanf("%lf", &r) != 1 || r <= 0) {
		printf("Please input a single positive number as radius"); 
		return 1;}

	getchar(); //Consumes the newline char left in buffer from previous scanf

	printf("Please enter a coordinate set (x, y): ");
	if (scanf("(%lf, %lf)", &x, &y) != 2) {
		printf("Please input 2 coordinates"); 
		return 2;}

	double accumulator = sqrt(pow(x-0, 2)+pow(y-0, 2));
	if (accumulator == (r + delta) || accumulator == (r - delta)) {printf("Point is on the periferal of the circle");}
	else if (accumulator < r) {printf("Point is inside of circle");}
	else if (accumulator > r) {printf("Point is outside of circle");}
	
	return 0;
}
