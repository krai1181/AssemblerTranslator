#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

char *convertFromDecimalToBinary(int decimalNumber) {
    char *binaryNumber = (char *) calloc(8, sizeof(char));

    if (!binaryNumber)
        return NULL;
    int cursor, tempNumber;

    for (cursor = 7; cursor >= 0; cursor--) {
        tempNumber = decimalNumber >> cursor;

        if (tempNumber & 1) {
            binaryNumber[cursor] = '1';
        } else {
            binaryNumber[cursor] = '0';
        }
    }
    printf("\n");
    return binaryNumber;
}

void reverseString(char *str) {
    if (*str == 0)
        return;

    char *start = str;
    char *end = start + strlen(str) - 1;
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }
}

char *convertFromBinaryToHex(int binaryNumber) {
    char *hexNumber = (char *) calloc(8, sizeof(char));

    return hexNumber;

}
