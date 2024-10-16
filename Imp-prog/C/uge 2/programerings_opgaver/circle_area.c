#include <stdio.h>

#define PI 3.1415926

int main(void){
	double radius;
	printf("please enter the radius of the circle > ");
	if (scanf("%lf", &radius) != 1 || radius < 0) {
		printf("error whilst recieving input, please try again and make sure it's a positive number");
		return 1;
	}
	printf("the area of the circle is %lf", radius*radius*PI);
	return 0;
}
