#include <stdio.h>

int main(void) {
	double first, second, third;
	printf("Please enter 3 numbers > ");
	if (scanf("%lf, %lf, %lf", &first, &second, &third) != 1) {
		printf("an error occured whilst reading the input. Please verify that you provided 3 numbers, seperated by space");
		return 1;
	}

	printf("you entered: %lf, %lf, %lf", first, second, third);
	return 0;
}
