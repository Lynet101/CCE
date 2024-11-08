/*  A program that sorts cards based on type and value
    15/11/24 @ 07:35
    card_sorter v0.1

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Card {
    int type;
    int value;
};

typedef enum{
    clubs = 1,
    spades = 4,
}card_type;

typedef enum{
    two = 1,
    ace = 13,
}card_value;

int combine_card(card_type type, card_value value);
int compare(const void* a, const void* b);
void sorter(struct Card *deck);
struct Card decombine_card(int combined);

#define deck_len 55

int main(){
    srand(time(NULL));
    struct Card deck[deck_len];
    int index = 3;
    char* card_values[] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace", "joker"};
    char* card_types[] = {"clubs", "diamonds", "hearts", "spades", "null"};


    deck[0].type=5; deck[0].value=14;
    deck[1].type=5; deck[1].value=14;
    deck[2].type=5; deck[2].value=14;

    for (card_type type = spades; type >= clubs; type--) {
        for (card_value value = ace; value >= two; value--) {
            deck[index].type = type;
            deck[index].value = value;
            index++;
        }
    }

    printf("Original Deck:\n");
    printf("------------------\n");
    for (int i = 0; i < deck_len; i++) {
        printf("%s of %s | ", card_types[deck[i].type - 1], card_values[deck[i].value - 1]);
    }

    sorter(deck);

    printf("\n\nFinal deck:\n");
    printf("------------------\n");
    for (int i = 0; i < deck_len; i++) {
        printf("%s of %s | ", card_types[deck[i].type - 1], card_values[deck[i].value - 1]);
    }

    return 0;
}

int combine_card(card_type type, card_value value) {
    return type * 100 + value;
}

void sorter(struct Card *deck){
    int combined_deck[deck_len];
    for (int i = 0; i < deck_len; i++) {
        combined_deck[i] = combine_card(deck[i].type, deck[i].value);
    }

    qsort(combined_deck, deck_len, sizeof(int), compare);

    for (int i = 0; i <deck_len; i++){
        deck[i] = decombine_card(combined_deck[i]);
    }
}

int compare(const void* a, const void* b) {
    //used for qsort
    return (*(int*)a - *(int*)b);
}

struct Card decombine_card(int combined) {
    struct Card card;
    card.type = combined / 100;
    card.value = combined % 100;
    return card;
}
