/*  Basic ass increment and decrement
    September 11th 2+24 @ 09:05
    main.c - V.1

    Sebastian Lindau-Skands / @Lynet_101
    slinda24@student.aau.dk */

#include <stdio.h>

int main(void) {
  
  int i = 3, j = 4, k = 5; //declaring and initialising I, J and K to their respective values
  int res1, res2, res3; //declaring but not initialising res1, res2 and res3
  
  i++; j--; ++k; //incrementing i, decrementing j, and incrementing k
  printf("i: %d, j: %d, k: %d\n", i,j,k); //printing the new value of i, j, and k in that order

  res1 = --i; //decrementing i (thereby returning it to the original value) and storing it in res1
  res2 = j++; //incre,incrememting j (thereby returning it to the original value) and storing it in res2
  res3 = --k; //decrementing k (thereby returning it to the original value) and storing it in res3

  printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3); //printing the values of res1, res2 and res3 in that order
  printf("i: %d, j: %d, k: %d\n", i,j,k); //printing the (still incremented) value of i, j, and k in that order
  
  return 0; //returning 0 indicating successful termination
}