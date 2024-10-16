/*  Opgave 2.4
    September 11 2024 @ 11:55
    2.4 v.1
    
    Sebastian Lindau-Skands
    slinda24@student.aau.dk*/
#include <stdio.h>

int main(void) {

  double d, e, f;

  printf("Enter three real numbers: ");
  scanf("%lf %lf %lf", &d, &e, &f);
  
  printf("The average is: %lf\n", (d + e + f) / 3.0);
    
  return 0;
}