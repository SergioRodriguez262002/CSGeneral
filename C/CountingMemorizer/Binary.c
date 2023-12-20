#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned char randomByte;
void getPrompt(){
    srand(time(NULL));
    // Generate a random byte
    randomByte = rand() % 256;

    char binaryRep[9];
    binaryRep[8] = '\0';
    int remainder = (int) randomByte;
    for(int i = 7; i >= 0; i--){
        binaryRep[i] = (char)(remainder % 2 + '0');
        remainder /= 2;
    }
    // Prompting user
    printf("What is the value of %s\n", binaryRep);
}
int promptResponse(int dec){
    return dec == (int)randomByte;
}
