#include <stdio.h>

void converter(int* weeks,int* days,int* hours,int* minutes,int* seconds);

int main(void) {
    int weeks, days, hours, minutes, seconds;
    printf("enter amount of seconds please: ");
    scanf("%d", &seconds);
    if (seconds < 0) {
        printf("Error: Input must be a possitive integer!");
        return 1;
    }

    converter(&weeks, &days, &hours, &minutes, &seconds);

    printf("Weeks: %d\nDays: %d\nHours: %d\nMinutes: %d\nSeconds: %d", weeks, days, hours, minutes, seconds);

    return 0;
}

void converter(int* weeks,int* days,int* hours,int* minutes,int* seconds) {
    // 1 week = 604800 seconds
    *weeks = *seconds / 604800;
    *seconds = *seconds % 604800;

    // 1 day = 86400 seconds
    *days = *seconds / 86400;
    *seconds = *seconds % 86400;

    //1 hour = 3600 seconds
    *hours = *seconds / 3600;
    *seconds = *seconds % 3600;

    //1 minute = 60 seconds
    *minutes = *seconds / 60;
    *seconds = *seconds % 60;
}