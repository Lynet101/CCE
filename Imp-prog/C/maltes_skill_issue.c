#include <stdio.h>

//open a .txt file and write "hello world" to it


int main() {
    FILE *fp;
    char filename[] = "example.txt";

    fp = fopen(filename, "w"); //open file in write mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Hello, world!\n"); //write to file

    fclose(fp); //close the file

    return 0;
}