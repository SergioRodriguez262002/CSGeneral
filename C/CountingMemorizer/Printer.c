#include <stdio.h>
#include <stdlib.h>

const char *baseNames[] = {
        "Binary",       // Base-2
        "Ternary",      // Base-3
        "Quaternary",   // Base-4
        "Quinary",      // Base-5
        "Senary",       // Base-6
        "Septenary",    // Base-7
        "Octal",        // Base-8
        "Nonary",       // Base-9
        "Decimal",      // Base-10
        "Undecimal",    // Base-11
        "Duodecimal",   // Base-12
        "Tridecimal",   // Base-13
        "Tetradecimal", // Base-14
        "Pentadecimal", // Base-15
        "Hexadecimal"   // Base-16
    };

void printPrompt(char* num){
    int base = sizeof(num)/sizeof(char);
    printf("What is the decimal value of %s which is a %s number.\n", num, baseNames[base]);

    
}