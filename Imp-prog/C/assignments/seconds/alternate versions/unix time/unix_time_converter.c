/*  Unix Time Converter
    September 09 - 2024 @ 07:56
    unix_time_converter.c - V0.5

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
void converter(int seconds, int* data);

int main(void) {
    int seconds;
    int data[6]; //[years, months, days, hours, minutes, seconds]
    data[0]=1970;
    data[1]=1;
    data[2]=1;

    printf("please enter the amount of seconds to convert: ");
    if (scanf("%d", &seconds) != 1 || seconds < 0) { 
        printf("Error: Invalid input. Please enter a valid positive integer.");
        return 1;}

    converter(seconds, data);
    printf("Year: %d\nMonth: %d\nDay: %d\nHour: %d\nMinute: %d\nSecond: %d", data[0], data[1], data[2], data[3], data[4], data[5]);
    return 0;
}

void converter(int remaining_seconds, int* data) {
    //constants are seconds in period
    data[0] += remaining_seconds / 31536000;
    remaining_seconds %= 31536000;

    data[1] += remaining_seconds / 2635200;
    remaining_seconds %= 2635200;

    data[2] += remaining_seconds / 86400;
    remaining_seconds %= 86400;

    data[3] = remaining_seconds / 3600;
    remaining_seconds %= 3600;

    data[4] = remaining_seconds / 60;
    data[5] = remaining_seconds % 60;
}
