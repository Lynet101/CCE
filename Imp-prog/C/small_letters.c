#include <string.h>

int main() {
    int sum = 0;
    char sentence[] = "ThE QuIcK BrOwN FoX JuMpS OvEr ThE LaZy DoG.";
    //char sentence[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    int sentence_len = sizeof(sentence) / sizeof(sentence[0]);
    char small_letters[] = "abcdefghijklmnopqrstuvxyzæøå";
    
    for (int i = 0; i < sentence_len; i++) {
        if (strchr(small_letters, sentence[i]) != NULL) {sum++;}
    }

    return sum;
}
