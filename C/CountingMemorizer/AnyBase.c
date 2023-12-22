#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char randomByte;
char* stringRep;
char* getPrompt(int base){
    if(base < 2 || base > 16){
        printf("Invalid base, valid bases withing 2 to 16\n");
        return 0;
    }
    srand(time(NULL));

    int strlen = 9;
    if(base > 5) strlen = 5;

    randomByte = rand() % 256;
    stringRep = (char*)malloc(sizeof(char)*strlen);
    stringRep[strlen - 1] = '\0';
    int remainder = (int) randomByte;
    // 'A' is ascci 65 '0' is 48
    for(int i = strlen -1; i >= 0; i--){
        int modu = (remainder %  base);
        int asciiOffset = (modu > 9) ? 55 : 48;
        stringRep[i] = modu + asciiOffset;
        remainder /= base;
    }
    return stringRep;

}
int promptResponse(int dec){
    free(stringRep);
    return dec == randomByte;   
}