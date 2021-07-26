#include <stdio.h>
#include <string.h>

#include "functions.h"

int main() {
    /*instructions table*/
    Instruction instructionsTable[] = {
            {0,  1, 'R', "add"},
            {0,  2, 'R', "sub"},
            {0,  3, 'R', "and"},
            {0,  4, 'R', "or"},
            {0,  5, 'R', "nor"},
            {1,  1, 'R', "move"},
            {1,  2, 'R', "mvhi"},
            {1,  3, 'R', "mvlo"},
            {10, 0, 'I', "addi"},
            {11, 0, 'I', "subi"},
            {12, 0, 'I', "andi"},
            {13, 0, 'I', "ori"},
            {14, 0, 'I', "nori"},
            {15, 0, 'I', "bne"},
            {16, 0, 'I', "beq"},
            {17, 0, 'I', "blt"},
            {18, 0, 'I', "bgt"},
            {19, 0, 'I', "lb"},
            {20, 0, 'I', "sb"},
            {21, 0, 'I', "lw"},
            {22, 0, 'I', "sw"},
            {23, 0, 'I', "lh"},
            {24, 0, 'I', "sh"},
            {30, 0, 'J', "jmp"},
            {31, 0, 'J', "la"},
            {32, 0, 'J', "call"},
            {63, 0, 'J', "stop"}
    };

    /*  FILE *output;
      output = fopen("output","w");*/

    //char *original = "MAIN:       add   $3,$5,$9";
    //char *original = "Next: move $3,$5";
    char *original = "la      val1";
    //char *original = "call val1";
    printf("%s\n", original);

    char sentence[10][SENTENCE_LENGTH];
    int i, j = 0, counter = 0, spaceCounter = 0;

    for (i = 0; i <= (strlen(original)); i++) {
        if (original[i] == ' ')
            spaceCounter++;
        if ((spaceCounter==1 && original[i] == ' ') || original[i] == '\0' || original[i] == ',') {
            sentence[counter][j] = '\0';
            counter++;  /*for next word*/
            j = 0;/*for next word, init index to 0*/
        } else if (original[i] != ' ' && original[i] != '$'){
            sentence[counter][j] = original[i];
            j++;
            spaceCounter = 0;
        }
    }


    //debug
    for (i = 0; i < counter; i++)
        printf("%s\n", sentence[i]);


    char  *functionName;

    if(isLowerCase(sentence[0][0]) == 0 || sentence[0][0] == '.')
        functionName = sentence[1];
    else
        functionName = sentence[0];

       char actionType = getActionType(instructionsTable, functionName);
    printf("action type is %c", actionType);


    //check numbers
    char *number = convertFromDecimalToBinary(16);
    reverseString(number);
    printf("binary number %s\n", number);
    printf("hex number %X\n", convertFromBinaryToHex("01000000"));

    Row* rows[10];
    if(actionType == 'R'){
        if(strcmp(functionName,"move")==1 || strcmp(functionName,"mvhi")==1 || strcmp(functionName,"mvlo") == 1){
            
        }

    }






/*
    fclose(output);
*/


    return 0;
}
