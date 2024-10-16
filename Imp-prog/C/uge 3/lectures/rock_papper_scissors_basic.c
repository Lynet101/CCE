/*  Rock-paper-scissors game in C (against a bot)
    Sep 18 2024 @ 09:30
    rock_paper_scissors.c v1.2

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 3

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;w

typedef struct HashTable {
    Node **table;
} HashTable;

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

HashTable *create_table() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->table = malloc(sizeof(Node *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, const char *key, const char *value) {
    unsigned int index = hash(key);
    Node *newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

char *lookup(HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);
    Node *node = hashTable->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void win_fn(int bot_choice, int your_choice);

int main() {
    HashTable *hashTable = create_table();

    insert(hashTable, "r", 1);
    insert(hashTable, "p", 2);
    insert(hashTable, "s", 3);


    //random number generator
    srand(time(NULL));
	int bot_choice = rand() % (3) + 1;
    int your_choice;
    char input;

    printf("Please enter your choice below; (r)ock, (p)apper, (s)cissors: ");
	if (scanf("%d", &input) != 1) {
        return 1;
    }

    your_choice = hashTable->values[input];
    if (your_choice >= 1 && your_choice <= 3) {
        win_fn(bot_choice, your_choice);
        return 0;
    } 
    else {
        printf("Invalid input. Please enter a number between 1 and 3.\n"); 
        return 1;
    }
}

void win_fn(int bot_choice, int your_choice) {
    //early return if tie
    if (bot_choice == your_choice) {printf("Tie"); return;}
    switch(your_choice){
        case 1:
            if (bot_choice == 2) {printf("Bot win");}
            if (bot_choice == 3) {printf("Player win");}
            break;

        case 2:
            if (bot_choice == 1) {printf("Player win");}
            if (bot_choice == 3) {printf("Bot win");}
            break;

        case 3:
            if (bot_choice == 1) {printf("Bot win");}
            if (bot_choice == 2) {printf("Player win");}
            break;}
    return;
}