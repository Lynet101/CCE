/*  Yatzy game with "n" dices (not to handle in !!!)
    05/11/24 @ 09:33
    yatzy_rev1.c v0.2

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <stdlib.h>

typedef enum {false=1, true} bool;
typedef enum {small=1, large} straight;

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
    int gamestate[16]; //[1, 2, 3, 4, 5, 6, bonus, pair, 2-pair, 3-of-a-kind, 4-of-a-kind, s. straight, l. straight, f. house, chance, yatsy]
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

int number_of_dices(int *n) {
    printf("Enter the number of dices (n): ");
    scanf("%d", n);
    if (*n < 1) {
        printf("Please enter one positive integer of dices\n");
        return -1;
    }
    return 0;
}

void dice_thrower(int n, int *dices) {
    int dice_value;
    for (int i = 0; i < n; i++){
        dice_value = rand() % 6 + 1;
        printf(" %d ", dice_value);
        dices[i] = dice_value;
    }
}

void single_digits(int *gamestate, int n) {
    int sum = 0;
    int counter = 0;
    int dices[sizeof(int)*n];
    for (int i = 0; i<6; i++) {
        printf("%d |", i+1);
        counter = 0;
        sum = 0;
        dice_thrower(n, dices);
        for (int j = 0; j < n; j++) {
            if (dices[j] == i+1 && counter < 5) {
                sum += dices[j];
                counter++;
            }
        }
        printf("| %d\n", sum);
        gamestate[i]=sum;
    }
    if (bonus_checker(gamestate) == true) { //for single_digit bonus
        printf("bonus earned");
        gamestate[6] = 50;
    }
}

bool bonus_checker(int *gamestate) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += gamestate[i];
    }
    if (sum > 50) {return true;}
    else {return false;}
}

void x_of_a_kind(int *gamestate, int x, int n) {
    int counter, previous, dices[sizeof(int)*n];
    dice_thrower(n, dices);
    qsort(dices, sizeof(dices), sizeof(int), compare);

    for (int i = sizeof(*dices)/sizeof(int); i >= 0; i--) {
        if (counter == x){break;}

        if (dices[i] == previous) {counter ++; }
        else {
            counter = 0;
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
            gamestate[15] = x * previous;
    }
}

void sl_straight(int *gamestate, int type, int n) {
    bool one, two, three, four, five, six = false;
    int dices[sizeof(int)*n];

    for (int i; i<sizeof(dices)/sizeof(int); i++){
        switch (dices[i]) {
            case 1:
                one = true;
                break;
            case 2:
                two = true;
                break;
            case 3:
                three = true;
                break;
            case 4:
                four = true;
                break;
            case 5:
                five = true;
                break;
            case 6:
                six = true;
                break;
        }
    }

    if (two == true && three == true && four == true && five == true) {
        if (type ==small && one == true) {gamestate[12] = 15;}
        else if (type == large && six == true) {gamestate[13] = 20;}
    }
}

void chance(int *gamestate, int n){
    int dices[sizeof(int)*n];
    dice_thrower(n, dices);
    qsort(dices, sizeof(dices), sizeof(int), compare);
    gamestate[14]=(dices[0]+dices[1]+dices[2]+dices[3]+dices[4]);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void print_result(int *gamestate) {
    return;
}
