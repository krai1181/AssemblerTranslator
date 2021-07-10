#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

char *convertFromDecimalToBinary(int decimalNumber) {
    char *binaryNumber = (char *) calloc(8, sizeof(char));

    if (!binaryNumber)
        return NULL;
    int cursor, tempNumber;

    for (cursor = 7; cursor >=0; cursor--) {
        tempNumber = decimalNumber >> cursor;
        if (tempNumber & 1) {
             binaryNumber[cursor] = '1';
             printf("1");
         } else {
             binaryNumber[cursor] = '0';
             printf("0");
         }

    }
    printf("\n");
    return binaryNumber;

}

char *convertFromBinaryToHex(int binaryNumber) {
    char *hexNumber = (char *) calloc(8, sizeof(char));

    return hexNumber;

}
