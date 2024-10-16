#include <stdio.h>

int main(void) {

  int percent, grade;

  printf("How many percent? ");
  if (scanf("%d",&percent) != 1 || percent < 10) {return 1};

  if (percent >= 90)
    grade = 11;
  if (percent >= 82)
    grade = 10;
  if (percent >= 74)
    grade = 9;
  if (percent >= 66)
    grade = 8;
  if (percent >= 58)
    grade = 7;
  if (percent >= 50)
    grade = 6;
  if (percent >= 40)
    grade = 5;
  if (percent >= 10)
    grade = 3;
  else grade = 0; 

  printf("%d percent corresponds to the Danish grade %d\n\n", 
          percent, grade);
  
  return 0;
}
