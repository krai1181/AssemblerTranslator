#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

    /*instructions table*/
    Instruction instructions[] = {
            {0,1,'R', "add"},
            {0,2,'R', "sub"},
            {0,3,'R', "and"},
            {0,4,'R', "or"},
            {0,5,'R', "nor"},
            {1,1,'R', "move"},
            {1,2,'R', "mvhi"},
            {1,3,'R', "mvlo"},
            {10,0,'I', "addi"},
            {11,0,'I', "subi"},
            {12,0,'I', "andi"},
            {13,0,'I', "ori"},
            {14,0,'I', "nori"},
            {15,0,'I', "bne"},
            {16,0,'I', "beq"},
            {17,0,'I', "blt"},
            {18,0,'I', "bgt"},
            {19,0,'I', "lb"},
            {20,0,'I', "sb"},
            {21,0,'I', "lw"},
            {22,0,'I', "sw"},
            {23,0,'I', "lh"},
            {24,0,'I', "sh"},
            {30,0,'J', "jmp"},
            {31,0,'J', "la"},
            {32,0,'J', "call"},
            {63,0,'J', "stop"}
    };

  /*  FILE *output;
    output = fopen("output","w");*/

    char *original = "jmp";

    char c = getInstructionType(instructions, original);
    printf("size is %lu\n", sizeof(instructions[0]));
    printf("type is %c",c);




/*
    fclose(output);
*/


    return 0;
}
