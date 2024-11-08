/*  Yatzy game with n-dices
    12/11/2024 @ 09:35
    yatzy.final.c V1.3
    Sebastian Lindau-Skands
    slinda24@student.aau.dk */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false=1, true} bool;
typedef enum {small=1, large} straight;

int number_of_dices(int *n);
void dice_thrower(int n, int *dices);
int update_gamestate(int (*func)(int, int*, int), int n, int *dices, int special_arg);
void single_digits(int *gamestate, int n, int *dices);
bool bonus_checker(int *gamestate);
int pair(int n, int *dices, int x);
int two_pairs(int n, int *dices, int x);
int x_similar(int n, int *dices, int x);
int sl_straight(int n, int *dices, int x);
int full_house(int n, int *dices, int x);
int chance(int n, int *dices, int x);
void removeElement(int *dices,int n, int x);
int compare(const void *a, const void *b);
void print_result(int *gamestate);

int update_gamestate(int (*func)(int, int*, int), int n, int *dices, int special_arg){
    //special arg is not needed in most cases and is therefore 0
    dice_thrower(n, dices);
    return func(n, dices, special_arg);
}

int main(){
    //init
    srand((unsigned int)time(NULL)); //random number seed
    int gamestate[16] = {0};
    int n = 0;
    while (true){if (number_of_dices(&n) == 0){break;}}
    int *dices = malloc(n * sizeof(int)); //freed correctly
    if (!dices){printf("mem alloc failed!"); return -1;}

    //game
    single_digits(gamestate, n, dices);
    gamestate[7] = update_gamestate(pair, n, dices, 0) * 2;
    gamestate[8] = update_gamestate(two_pairs, n, dices, 0);
    gamestate[9] = update_gamestate(x_similar, n, dices, 3) * 3; //3 of a kind
    gamestate[10] = update_gamestate(x_similar, n, dices, 4) * 4; //4 of a kind
    if (update_gamestate(sl_straight, n, dices, small) == true) {gamestate[11] = 15;}
    if (update_gamestate(sl_straight, n, dices, large) == true) {gamestate[12] = 20;}
    gamestate[13] = update_gamestate(full_house, n, dices, 0);
    gamestate[14] = update_gamestate(chance, n, dices, 0);
    gamestate[15] = update_gamestate(x_similar, n, dices, 5) * 5; //yatzy
    if (gamestate[15] != 0) {gamestate[15] += 50;} //yatzy bonus
    print_result(gamestate);

    //close
    free(dices);
    return 0;
}

int number_of_dices(int *n) {
    printf("Enter the number of dices (n): ");
    scanf("%d", n);
    if (*n < 5) {
        printf("Amount of dices must be at least 5\n");
        return -1;
    }
    return 0;
}

void dice_thrower(int n, int *dices) {
    int dice_value;
    for (int i = 0; i < n; i++){
        dice_value = rand() % 6 + 1;
        dices[i] = dice_value;
    }
}

void single_digits(int *gamestate, int n, int *dices) {
    int sum;
    int counter;

    for (int i = 0; i<6; i++) {
        //iterate through the 6 single digits
        counter = 0;
        sum = 0;
        dice_thrower(n, dices);
        for (int j = 0; j < n; j++) {
            if (dices[j] == i+1 && counter < 5) {
                sum += dices[j];
                counter++;
            }
        }
        gamestate[i]=sum;
    }
    if (bonus_checker(gamestate) == true) { //for single_digit bonus
        gamestate[6] = 50;
    }
}

bool bonus_checker(int *gamestate) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += gamestate[i];
    }

    if (sum > 63) {return true;}
    else {return false;}
}

int pair(int n, int *dices, int x) {
    int result = x_similar(n, dices, 2);
    if (result != 0) {return result;}
    else {return 0;}
}

int two_pairs(int n, int *dices, int x) {
    int pair_1 = pair(n, dices, 0);
    removeElement(dices, n, pair_1);
    int pair_2 = pair(n, dices, 0);
    return (pair_1 * 2) + (pair_2 * 2);
}

int x_similar(int n, int *dices, int x) {
    // returns 0 if "x of a kind" is not found, else returns the value of which "x of a kind" is found
    int counter = 0;
    int previous = 0;
    qsort(dices, n, sizeof(int), compare);

    for (int i = n-1; i >= 0; i--) {
        if (counter == x){return previous;}
        if (dices[i] == previous) {counter ++; }
        else {
            counter = 1;
            previous = dices[i];
        }
    }
    return 0;
}

int sl_straight(int n, int *dices, int x) {
    bool present[7] = {false};

    for (int i = 0; i < n; i++) {
        if (dices[i] >= 1 && dices[i] <= 6) {
            present[dices[i]] = true;
        }
    }

    if (present[2] && present[3] && present[4] && present[5]) {
        if (x == small && present[1]) {
            return true;
        } else if (x == large && present[6]) {
            return true;
        }
    }

    return false;
}

int full_house(int n, int *dices, int x) {
    int sim_3 = x_similar(n, dices, 3);
    removeElement(dices, n, sim_3);
    int pair = x_similar(n, dices, 2);
    if (sim_3 != 0 && pair != 0) {return (sim_3 * 3) + (pair * 2);}
    else {return 0;}
}

int chance(int n, int *dices, int x) {
    qsort(dices, n, sizeof(int), compare);
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += dices[n - i];
    }
    return sum;
}

void removeElement(int *dices,int n, int x) {
    //removes all presents of element "x" in array "dices" (used for 2 pairs and full_house)
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (dices[i] != x) {
            dices[k] = dices[i];
            k++;
        }
    }

    while (k < n) {
        dices[k] = 0;
        k++;
    }
}

int compare(const void* a, const void* b) {
    //used for qsort
    return (*(int*)a - *(int*)b);
}

void print_result(int *gamestate) {
    //just making the result look a bit nicer
    int sum = 0, total = 0;
    for (int i = 0; i <= 5; i++) {sum += gamestate[i];}
    for (int i = 0; i <= 15; i++) {total += gamestate[i];}
    printf("\n  FINAL SCOREBOARD:\n");
    printf("┏━━━━━━━━━━━━━━━━┬━━━━┓\n");
    printf("┃ones            │  %2d┃\n", gamestate[0]);
    printf("┃────────────────┼────┃\n");
    printf("┃twos            │  %2d┃\n", gamestate[1]);
    printf("┃────────────────┼────┃\n");
    printf("┃threes          │  %2d┃\n", gamestate[2]);
    printf("┃────────────────┼────┃\n");
    printf("┃fours           │  %2d┃\n", gamestate[3]);
    printf("┃────────────────┼────┃\n");
    printf("┃fives           │  %2d┃\n", gamestate[4]);
    printf("┃────────────────┼────┃\n");
    printf("┃sixs            │  %2d┃\n", gamestate[5]);
    printf("┣━━━━━━━━━━━━━━━━┼━━━━┫\n");
    printf("┃Sum             │ %3d┃\n", sum);
    printf("┣━━━━━━━━━━━━━━━━┼━━━━┫\n");
    printf("┃Bonus           │  %2d┃\n", gamestate[6]);
    printf("┣━━━━━━━━━━━━━━━━┼━━━━┫\n");
    printf("┃Pair            │  %2d┃\n", gamestate[7]);
    printf("┃────────────────┼────┃\n");
    printf("┃2 pairs         │  %2d┃\n", gamestate[8]);
    printf("┃────────────────┼────┃\n");
    printf("┃3 of a kind     │  %2d┃\n", gamestate[9]);
    printf("┃────────────────┼────┃\n");
    printf("┃4 of a kind     │  %2d┃\n", gamestate[10]);
    printf("┃────────────────┼────┃\n");
    printf("┃Small straight  │  %2d┃\n", gamestate[11]);
    printf("┃────────────────┼────┃\n");
    printf("┃Large straight  │  %2d┃\n", gamestate[12]);
    printf("┃────────────────┼────┃\n");
    printf("┃Full house      │  %2d┃\n", gamestate[13]);
    printf("┃────────────────┼────┃\n");
    printf("┃Chance          │  %2d┃\n", gamestate[14]);
    printf("┃────────────────┼────┃\n");
    printf("┃Yatzy           │  %2d┃\n", gamestate[15]);
    printf("┣━━━━━━━━━━━━━━━━┼━━━━┫\n");
    printf("┃Total           │ %3d┃\n", total);
    printf("┗━━━━━━━━━━━━━━━━┴━━━━┛\n");
}
