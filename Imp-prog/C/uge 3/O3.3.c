#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int ph = rand() % 14;
	printf("%d\n", ph);	
	/*if (ph <= 2)
	     printf("Very acidic");  
	else if (ph < 7) 
	     printf("Acidic");       
	else if (ph == 7)
	     printf("Neutral");      
	else if (ph < 12)
	     printf("Alkaline");     
	else 
	     printf("Very alkaline");*/
	
	if (ph < 12) {
		if (ph < 7) {
			if (ph <= 2) {
				printf("very acidic");
			}
			printf("acidic");
		}
		if (ph == 7) {
			printf("neutral");
		}
		printf("Alkaline");
	}
	else {printf("Very alkaline");}
	
	return 0;
}
