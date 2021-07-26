
#include "structures.h"

#define INSTRUCTIONS_SIZE  36
#define SENTENCE_LENGTH  80


char *convertFromDecimalToBinary(int);
int convertFromBinaryToHex(char* binaryNumber);
void reverseString(char*);
char getActionType(Instruction *instructions, char* str);
int isLowerCase(char character);

