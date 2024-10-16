/*  Opgave 2.7
    September 11 2024 @ 11:00
    2.7 v.1 BROKEN

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // The variable groups is uninitialized
    int groups, average_pr_group, average_pr_course;
    int classes = 2;
    int students = 280;
    
    average_pr_group = students / groups;
    average_pr_course = students / classes;

    printf("Classes: %d, Groups: %d, Students: %d \n", classes, groups, students);
    printf("There are %d students pr. group.\n", average_pr_group);
    printf("There are %d students pr. class.\n", average_pr_course);

    return EXIT_SUCCESS;
}