#include <stdio.h>

void converter(int seconds, int* data);

int main(void) {
    int seconds;
    int data[5]; //[weeks, days, hours, minutes, seconds]
    printf("please enter the amount of seconds to convert: ");
    if (scanf("%d", &seconds) != 1 || seconds < 0) {
        printf("Error: Invalid input. Please enter a valid positive integer.");
        return 1; 
    }

    converter(seconds, data);

    printf("Weeks: %d\nDays: %d\nHours: %d\nMinutes: %d\nSeconds: %d", data[0], data[1], data[2], data[3], data[4]);
    return 0;
}

void converter(int remaining_seconds, int* data) {
    // 1 week = 604800 seconds
    data[0] = remaining_seconds / 604800;
    remaining_seconds %= 604800;

    // 1 day = 86400 seconds
    data[1] = remaining_seconds / 86400;
    remaining_seconds %= 86400;

    //1 hour = 3600 seconds
    data[2] = remaining_seconds / 3600;
    remaining_seconds %= 3600;
    
    //1 minute = 60 seconds
    data[3] = remaining_seconds / 60;
    data[4] = remaining_seconds % 60;
}