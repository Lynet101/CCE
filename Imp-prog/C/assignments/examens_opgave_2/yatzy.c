/*  Yatzy game with "n" dices
    05/11/24 @ 08:01
    yatzy.c v0.2

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int number_of_dices(int *n);
void dice_thrower(int *dices, int n);
void single_digits(int *gamestate, int n);
bool bonus_checker(int *gamestate);
void x_pair(int *gamestate, int x);
void x_of_a_kind(int *gamestate, int x);
void sl_straight(int *gamestate, int x);
void full_house(int *gamestate);
void chance(int *gamestate);
void yatsy(int *gamestate);

int main() {
    int gamestate[16]; //[1, 2, 3, 4, 5, 6, bonus, pair, 2-pair, 3-of-a-kind, 4-of-a-kind, s. straight, l. straight, f. house, chance, yatsy]
    int n;
    while(true) {
        if (number_of_dices(&n) == 0) {break;}
    }

    single_digits(gamestate, n);
    if (bonus_checker(gamestate) == true) {
        printf("bonus earned");
        gamestate[6] = 50; //maybe change
    }
    else{gamestate[6]=0;}

    return 0;
}

int number_of_dices(int *n) {
    printf("Enter the number of dices (n): ");
    scanf("%d", n);
    if (*n < 1) {
        printf("Please enter one positive integer of dices\n");
        return -1;
    }
    return 0;
}

void dice_thrower(int *dices, int n) {
    int dice_value;
    for (int i = 0; i < n; i++){
        dice_value = rand() % 6 + 1; // Generates a random number between 1 and 6
        printf(" %d ", dice_value);
        dices[i] = dice_value;
    }
}

void single_digits(int *gamestate, int n) {
    int dices[n];
    int sum;
    for (int i = 0; i<6; i++) {
        sum = 0;
        dice_thrower(dices, n);
        for (int j = 0; j < n; j++) {sum += dices[j];}
        printf("| %d\n", sum);
        gamestate[i]=sum;
    }
}

bool bonus_checker(int *gamestate) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += gamestate[i];
    }
    if (sum > 50) {return true;} //maybe change
    else {return false;}
}