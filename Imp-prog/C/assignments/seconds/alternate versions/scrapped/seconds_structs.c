#include <stdio.h>

struct data {
    int weeks, days, hours, minutes, seconds;
};

typedef struct data Struct;

Struct converter(int seconds) { 
    Struct s;
    // 1 week = 604800 seconds
    s.weeks = seconds / 604800;
    seconds %= 604800;

    // 1 day = 86400 seconds
    s.days = seconds / 86400;
    seconds %= 86400;

    //1 hour = 3600 seconds
    s.hours = seconds / 3600;
    seconds %= 3600;
    
    //1 minute = 60 seconds
    s.minutes = seconds / 60;
    s.seconds = seconds % 60;

    return s;
}

int main(void) {
    int seconds;
    Struct accumulator;

    printf("please enter the amount of seconds to convert: ");
    scanf("%d", &seconds);
    if (seconds < 0) {
        printf("Error: Input must be a possitive integer!");
        return 1;
    }

    accumulator = converter(seconds);

    printf("Weeks: %d\nDays: %d\nHours: %d\nMinutes: %d\nSeconds: %d", accumulator.weeks, accumulator.days, accumulator.hours, accumulator.minutes, accumulator.seconds);
    return 0;
}