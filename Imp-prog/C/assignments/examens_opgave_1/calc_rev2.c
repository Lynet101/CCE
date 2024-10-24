/*  Examens opgave 1 - Imp Prog - AAU CCT-1
    24/10/2024 @ 08:32
    calc_finished.c v1.2.8

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int run_calc();
int scan_data(double *input, char *opt, char valid_opts[]);
int do_next_op(double *result, double input, char opt);
bool is_unary(char *opt);
void help_menu();

int main() {
    run_calc();
    return 0;
}

int run_calc() {
    double input = 0.0;
    double result = 0.0;
    char opt;
    char valid_opts[] = "+-*/^#!hq%%";

    printf("+----------------------------------------------------------------+\n"
        "|            WELCOME TO THE CALCULATOR ABOVE THEM ALL            |\n"
        "+----------------------------------------------------------------+\n");
    while (true) {
        switch(scan_data(&input, &opt, valid_opts)) {
            case 1:
                printf("Final result: %lf\n", result);
                return 0;
            case 2:
                help_menu();
                continue;
        }
        if (do_next_op(&result, input, opt) == -1) {exit(-1);} // exit on return code -1 as this *should* be an impossible condition
        printf("result is now: %lf\n\n", result);
    }
}

void clear_input_buffer() {
    //consume all characters in input buffer, to prevent runaway conditions with scanf()
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int scan_data(double *input, char *opt, char valid_opts[]) {
    //  return -1 on program exit (q)
    //  return 1 on helpmenu
    while (true) {
        printf("Please enter operator: ");
        if (scanf(" %c", opt) != 1) {
            clear_input_buffer();
            printf("Please enter EXACTLY 1 operator\n");
            continue;}

        if (strchr(valid_opts, *opt) == NULL) {
            clear_input_buffer();
            printf("Invalid operator entered... Type 'h' if you need help\n");
            continue;}
        else {break;}
    }

    if (is_unary(opt)) {return 0;}
    if (*opt == 'q') {return 1;}
    if (*opt == 'h') {return 2;}

    while (true) {
        printf("Please enter operand: ");
        if (scanf(" %lf", input) != 1) {
            clear_input_buffer();
            printf("Please enter EXACTLY 1 number\n");
            continue;}
        else {break;}
    }

    return 0;
}

bool is_unary(char *opt) {
    if (*opt == '#' || *opt == '!' || *opt == '%') {return true;}
    else {return false;}
}

int do_next_op(double *result, double input, char opt) {
    /*  Return -1 for failure to match switch case (should be impossible, but good to have)
        Return -2 for invalid inputs to operand (division by zero, sqrt on 0 or negative)*/
    switch (opt) {
        case '+':
            *result += input;
            break;
        case '-':
            *result -= input;
            break;
        case '*':
            *result *= input;
            break;
        case '/':
            if (input == 0.0) {return -2;}
            *result /= input;
            break;
        case '^':
            *result = pow(*result, input);
            break;
        case '#':
            if (*result <= 0.0) {return -2;}
            *result = sqrt(*result);
            break;
        case '%':
            *result *= -1.0;
            break;
        case '!':
            *result = 1 / *result;
            break;
        default:
            return -1;
    }
    return 0;
}

void help_menu() {
    printf("+----------------------------------------------------------------+\n"
        "|                             HELP MENU                          |\n"
        "+----------------------------------------------------------------+\n"
        "Available operators:\n"
        "    + : Addition\n"
        "    - : Subtraction\n"
        "    * : Multiplication\n"
        "    / : Division\n"
        "    ^ : Exponentiation\n"
        "    # : Square root\n"
        "    %% : Negate\n"
        "    ! : Reciprocal\n"
        "    q : Quit\n"
        "+----------------------------------------------------------------+\n");
}