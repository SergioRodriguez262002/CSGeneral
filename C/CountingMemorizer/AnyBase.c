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

    /*Base 2 (Binary): 11111111 (length: 8)
Base 3: 100000 (length: 6)
Base 4: 3333 (length: 4)
Base 5: 1020 (length: 4)
Base 6: 1103 (length: 4)
Base 7: 513 (length: 3)
Base 8 (Octal): 377 (length: 3)
Base 9: 340 (length: 3)
Base 10 (Decimal): 255 (length: 3)
Base 11: 210 (length: 3)
Base 12: 187 (length: 3)
Base 13: 159 (length: 3)
Base 14: 129 (length: 3)
Base 15: FF (length: 2)
Base 16 (Hexadecimal): FF (length: 2)*/
    int strlen = 9;
    if(base < 5) strlen = 5;

    randomByte = rand() % 256;
    stringRep = (char*)malloc(sizeof(char)*strlen);
    stringRep[strlen - 1] = '\0';
    int remainder = (int) randomByte;
    // 'A' is ascci 65 '0' is 48
    for(int i = strlen -1; i >= 0; i--){
        int modu = (remainder %  base);
        stringRep[i] = modu + (modu > 9) ? 55 : 48;
        remainder /= base;
    }
    return stringRep;

}
int promptResponse(int dec){
    free(stringRep);
    return dec == randomByte;   
}