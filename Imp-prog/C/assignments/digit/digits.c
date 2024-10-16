/*	Simple program to calculate occurences of C from 0 to N
	01/10/2024 @ 08:24
	digit.c v1.0.7

	Sebastian Lindau-Skands
	slinda24@student.aau.dk */

#include <stdio.h>

int input(int *n, int *c);

int main(void) {
	int c, n;
	int c_in_n = 0;
	
	while (input(&n, &c) == -1) {
		getchar();//consume newline character
		continue;
    }

	//nested for loops 🤮
	for (int i = 0; i <= n; i++){
		for (int j = i; j>0; j= j/10) {
			if (j % 10 == c) {
				c_in_n++;
				break; //early break to avoid counting for the same number more than once. eg 55 contains 5 twice
			}
		}
	}

	printf("from 0 to %d, %d numbers have %d present at least once\n", n, c_in_n, c);
	return 0;
}

int input(int *n, int *c) {
	printf("Enter a number (n): ");
	if (scanf("%d", n) != 1 || *n < 0) {
		printf("Invalid input. Please enter a valid positive integer for n\n");
		return -1;
	}

	getchar(); //consume newline character
	
	printf("Enter a digit (c): ");
	if (scanf("%d", c) != 1 || *c < 0 || *c > 9) {
		printf("Invalid input. Please enter a positive integer between 0 and 9\n");
		return -1;
	}
	return 0;
}

/*	Currently, a string input in n or c, will accumulator in a few seconds of spamming "invalid input"
	Reasoning for this remains unknown	*/