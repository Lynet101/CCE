/*  Examens opgave 1 - Imp Prog - AAU CCT-1
    17/10/2024 @ 09:40
    calc_prototype.c v1.1.5

    Sebastian Lindau-Skands
    slinda24@student.aau.dk */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int run_calc(double input, double *result, char opt, char valid_opts[]);
int scan_data(double *input);
int scan_opt(char *opt, char valid_opts[]);
int do_next_op(double *accumulator, double input, char opt);
void help_menu();

int main() {
    double input = 0.0;
    double result = 0.0;
    char opt;
    char valid_opts[] = "+-*/^#!hq%%";

    printf("+----------------------------------------------------------------+\n");
    printf("|            WELCOME TO THE CALCULATOR ABOVE THEM ALL            |\n");
    printf("+----------------------------------------------------------------+\n");

    while (true) {
        if (run_calc(input, &result, opt, valid_opts) == 0) {continue;}
        else {break;}
    }

    printf("\n\nFINAL accumulator: %lf", result);
    return 0;
}

int run_calc(double input, double *result, char opt, char valid_opts[]) {
    /*  return -1 on program exit (q)
        return 0 if loop is to be continued*/
    double accumulator = *result;
    bool input_needed = true;
    while (true) {
        printf("Please enter operand (type h for help): ");
        int scan_opt_return_code = scan_opt(&opt, valid_opts);
        if (scan_opt_return_code == -1) {
            printf("Invalid input. Please enter only one operand\n");
            continue;
        }
        if (scan_opt_return_code == -2) {
            printf("Please enter a valid operand!\n");
            printf("Valid operands are: '+', '-', '*', '/', '^', '#', '%%', '!', 'q'\n");
            continue;
        }
        else {break;}  
    }

    switch(opt) {
            case 'h':
                help_menu();
                return 0;
            case 'q':
                return -1;
            case '#':
                input_needed = false;
            case '!':
                input_needed = false;
            case '%':
                input_needed = false;
    }

    while (input_needed) {
        printf("Please enter a number you want to perform the operand on (together with accumulator): ");
        if (scan_data(&input) == -1) {
            printf("Invalid input. Please enter ONLY one number\n");
            continue;
        }
        else {input_needed = false;}
    }

    int do_next_op_return_code = do_next_op(&accumulator, input, opt);
    if (do_next_op_return_code == -1) {
        printf("Unknown error\n");
        return 0;
    }
    else if(do_next_op_return_code == -2) {
        return 0;
    }

    printf("accumulator: %lf\n", accumulator);

    *result = accumulator;
    return 0;
}

int scan_data(double *input) {
    //  return -1 if multiple inputs recieved
    if (scanf(" %lf", input) != 1) {return -1;}
    else {return 0;}
}

int scan_opt(char *opt, char valid_opts[]) {
    /*  Return -1 if multiple inputs recieved
        Return -2 if invalid operand provided*/
    if (scanf(" %c", opt) != 1) {return -1;}
    printf("%c", *opt);
    if (strchr(valid_opts, *opt) == NULL) {return -2;}
    else {return 0;}
}

int do_next_op(double *accumulator, double input, char opt) {
    /*  Return -1 for failure to match switch case (should be impossible, but good to have)
        Return -2 for invalid inputs to operand (division by zero, sqrt on 0 or negative)*/
    switch (opt) {
        case '+':
            *accumulator += input;
            break;
        case '-':
            *accumulator -= input;
            break;
        case '*':
            *accumulator *= input;
            break;
        case '/':
            if (input == 0.0) {
                return -2;
            }
            *accumulator /= input;
            break;
        case '^':
            *accumulator = pow(*accumulator, input);
            break;
        case '#':
            if (*accumulator <= 0.0) {return -2;}
            *accumulator = sqrt(*accumulator);
            break;
        case '%':
            *accumulator *= -1.0;
            break;
        case '!':
            *accumulator = 1 / *accumulator;
            break;
        default:
            return -1;
    }
    return 0;
}

void help_menu() {
    printf("  +    for addition af akkumulatoren med operanden\n");
    printf("  -    for subtraktion af akkumulatoren med operanden\n");
    printf("  *    for multiplikation af akkumulatoren med operanden\n");
    printf("  /    for division af akkumulatoren med operanden\n");
    printf("  ^    for potensopløftning af akkumulatoren med operanden\n");
    printf("  #    for kvadratroden af akkumulatoren\n");
    printf("  %%    for at vende fortegnet af akkumulatoren\n");
    printf("  !    for at dividere 1 med akkumulatoren\n");
    printf("  q    for at afslutte regnemaskinen med slutaccumulatoratet\n");
    printf("  h    for at vise denne menu\n");
}