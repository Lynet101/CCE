/*  Opgave 2.5 - "Uger, dage, timer, minutter og sekunder "
    September 12 - 2024 @ 14:15
    seconds_basic.c - V1

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>

int main(void) {
    int seconds, minutes, hours, days, weeks;
    int remaining_seconds;

    printf("please enter the amount of seconds to convert: ");
    scanf("%d", &remaining_seconds);

    weeks = remaining_seconds / 604800;
    remaining_seconds %= 604800;

    days = remaining_seconds / 86400;
    remaining_seconds %= 86400;

    hours = remaining_seconds / 3600;
    remaining_seconds %= 3600;

    minutes = remaining_seconds / 60;
    seconds = remaining_seconds % 60;

    printf("Weeks: %d, Days: %d, Hours: %d, Minutes: %d, Seconds: %d", weeks, days, hours, minutes, seconds);
    return 0;
}
