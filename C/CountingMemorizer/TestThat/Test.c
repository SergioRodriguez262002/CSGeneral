#include <stdio.h>
#include <stdlib.h>

int totalTests = 0;
int passedTests = 0;
int failedTests = 0;

void testIntger(int a, int b){
    if(a == b){
        printf("Test passed\n");
        return;
    }
    printf("Test failed should've been %i \n",b);
}
