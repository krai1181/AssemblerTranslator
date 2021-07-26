#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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


char getActionType(Instruction *instructions, char *str) {
    int i;
    for (i = 0; i < INSTRUCTIONS_SIZE; i++) {
        if (strcmp(str, instructions[i].actionName) == 0)
            return instructions[i].actionType;
    }

    return '0';
}

int convertFromBinaryToHex(char* binaryNumber) {
    char *tempNum = binaryNumber;
    int hexNumber = 0;
    do {
        int b = *tempNum == '1' ? 1 : 0;
        hexNumber = (hexNumber<<1)|b;
        tempNum++;
    } while (*tempNum);
    return hexNumber;
}


int isLowerCase(char character) {
    if (character >= 'a' && character <= 'z')
        return 1;
    return 0;
}



