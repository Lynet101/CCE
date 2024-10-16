/*  Rock-paper-scissors game in C with SP and MP capabilities
    Sep 18 2024 @ 09:30
    rock_paper_scissors.c v2.3

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input(int player);
int bot_choice(void);
void win_function(int opponent_choice, int your_choice);

int main(void) {
    int game_mode;
    printf("Welcome to the Rock-Paper-Scissors game!\n");
    printf("Please enter Game Mode (1)Singleplayer, (2)Multiplayer: ");
    scanf("%d", &game_mode);

    if (game_mode == 1) {win_function(input(1), bot_choice()); return 0;}
    else if (game_mode == 2) {win_function(input(1), input(2)); return 0;}
    else {printf("Invalid input. Please enter a number between 1 and 2.\n"); main();}

	return 0;
}

int input(int player) {
    int your_choice;
    printf("P%d; Please enter your choice below; (1)Rock, (2)Papper, (3)Scissors: ", player);
	if (scanf("%d", &your_choice) == 1 && your_choice >= 1 && your_choice <= 3) {return your_choice;}
    else {printf("Invalid input. Please enter a number between 1 and 3.\n"); input(player);}
}

int bot_choice(void) {
    srand(time(NULL));
	int bot_choice = rand() % (3 - 1 + 1) + 1;
    return bot_choice;
}

void win_function(int opponent_choice, int your_choice) {
    if (opponent_choice == your_choice) {printf("Tie"); return;}
    printf("Opponent choice: %d\n", opponent_choice);
    switch(your_choice){
        case 1:
            if (opponent_choice == 2) {printf("P2 win");}
            if (opponent_choice == 3) {printf("P1 win");}
            break;

        case 2:
            if (opponent_choice == 1) {printf("P1 win");}
            if (opponent_choice == 3) {printf("P2 win");}
            break;

        case 3:
            if (opponent_choice == 1) {printf("P2 win");}
            if (opponent_choice == 2) {printf("P1 win");}
            break;}
}