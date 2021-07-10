#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    char *number = convertFromDecimalToBinary(3);
    int i;
    for(i = 0;i<8;i++)
    {
        printf("%c",number[i] );
    }
    printf("\n");

    free(number);
    return 0;
}
