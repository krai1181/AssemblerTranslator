#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"


char *convertFromDecimalToBinary(int decimalNumber, int cursorSize) {
    char *binaryNumber = (char *) calloc(8, sizeof(char));

    if (!binaryNumber)
        return NULL;
    int cursor, tempNumber;

    for (cursor = cursorSize; cursor >= 0; cursor--) {
        tempNumber = decimalNumber >> cursor;

        if (tempNumber & 1) {
            binaryNumber[cursor] = '1';
        } else {
            binaryNumber[cursor] = '0';
        }
    }
    printf("\n");
    reverseString(binaryNumber);
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


char getActionType(Instruction *instruction, char *str) {
    int i;
    for (i = 0; i < INSTRUCTIONS_SIZE; i++) {
        if (strcmp(str, instruction[i].actionName) == 0)
            return instruction[i].actionType;
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
        return 0;
    return 1;
}

char *getFuncCode(char *functionName, Instruction *instruction){
    char *result;
    int i;
    for (i = 0; i < INSTRUCTIONS_SIZE; i++) {
        if (strcmp(functionName, instruction[i].actionName) == 0){
            result = convertFromDecimalToBinary(instruction[i].funct, 4);
            break;
        } else {
            result = "-1";
        }
    }
    return result;
}

char *getOpCode(char *functionName, Instruction *instruction){
    char *result;
    int i;
    for (i = 0; i < INSTRUCTIONS_SIZE; i++) {
        if (strcmp(functionName, instruction[i].actionName) == 0){
            result = convertFromDecimalToBinary(instruction[i].opcode, 5);
            break;
        } else {
            result = "-1";
        }
    }
    return result;
}


