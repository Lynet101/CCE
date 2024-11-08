/*  Yatzy game with "n" dices (not to handle in !!!)
    05/11/24 @ 09:33
    yatzy_prot.c v0.2

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int number_of_dices(int *n); //implemented
void dice_thrower(int n, int *dices); //implemeted (with bug)
void single_digits(int *gamestate, int n); //implemented
bool bonus_checker(int *gamestate); //implemented
void x_pair(int *gamestate, int x);
void x_of_a_kind(int *gamestate, int x, int n); //implemented (untested)
void sl_straight(int *gamestate, int type, int n); //implemented (untested)
void full_house(int *gamestate);
void chance(int *gamestate, int n); //implemented (untested)
int compare(const void* a, const void* b); //implemented support func to qsort
void print_result(int *gamestate);


int main() {
    srand((unsigned int)time(NULL));
    int gamestate[16] = {0}; //[1, 2, 3, 4, 5, 6, bonus, pair, 2-pair, 3-of-a-kind, 4-of-a-kind, s. straight, l. straight, f. house, chance, yatsy]
    int n;
    while(true) {
        if (number_of_dices(&n) == 0) {break;}
    }

    single_digits(gamestate, n);
    //x_pair(1)
    //x_pair(2)
    x_of_a_kind(gamestate, 3, n);
    x_of_a_kind(gamestate, 4, n);
    //full houseS
    sl_straight(gamestate, small, n);
    sl_straight(gamestate, large, n);
    chance(gamestate, n);
    x_of_a_kind(gamestate, 5, n);

    print_result(gamestate);
    return 0;
}

void x_of_a_kind(int *gamestate, int x, int n) {
    int counter = 0;
    int previous = 0;
    int dices[sizeof(int)*n];

    dice_thrower(n, dices);
    qsort(dices, n, sizeof(int), compare);

    for (int i = n-1; i >= 0; i--) {
        if (counter == x){break;}
        if (dices[i] == previous) {counter ++; }
        else {
            counter = 1;
            previous = dices[i];
        }
    }

    if (counter != x) {return;}

    switch (x) {
        case 3:
            gamestate[9] = x * previous;
        case 4:
            gamestate[10] = x * previous;
        case 5:
            gamestate[15] = (x * previous) + 50;
    }
}



void chance(int *gamestate, int n){
    int dices[sizeof(int)*n];
    dice_thrower(n, dices);
    qsort(dices, n, sizeof(int), compare);
    gamestate[14]=(dices[n-1]+dices[n-2]+dices[n-3]+dices[n-4]+dices[n-5]);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
