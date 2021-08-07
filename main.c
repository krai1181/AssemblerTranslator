#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

#include "functions.h"

int main() {
    FILE *psMainFile, *psExternalsFile, *psEntitiesFile;
    psEntitiesFile = fopen("ps.ent", "a");
    psExternalsFile = fopen("ps.ext", "a");
    char *original = "K: la      val1";

/*   char *original = "MAIN:       add   $3,$5,$9";
     char *original = "Next: move $3,$5";
    char *original = "la      val1";
    char *original = "sw   $0,4,$10";
    char *original = "LOOP: ori   $9,-5,$2";
    char *original = "bne  %5 %24 loop";
    char *original = "call val1";*/

    printf("%s\n", original);

    char sentence[10][SENTENCE_LENGTH];
    int i, j = 0, counter = 0, spaceCounter = 0;

    for (i = 0; i <= (strlen(original)); i++) {
        if (original[i] == ' ')
            spaceCounter++;
        if ((spaceCounter == 1 && original[i] == ' ') || original[i] == '\0' || original[i] == ',') {
            sentence[counter][j] = '\0';
            counter++;  /*for next word*/
            j = 0;/*for next word, init index to 0*/
        } else if (original[i] != ' ' && original[i] != '$') {
            sentence[counter][j] = original[i];
            j++;
            spaceCounter = 0;
        }
    }


    /*debug*/
    for (i = 0; i < counter; i++)
        printf("%s\n", sentence[i]);


    char *functionName;
    R typeR;
    I typeI;
    J typeJ;

    char actionType;
    int currentIndex = 0;
    int wordsIndex = 0;

    if (isLowerCase(sentence[0][0]) != 0 || sentence[0][0] == '.') {
        currentIndex = 1;
        if (isLowerCase(sentence[0][1]) == 0 || sentence[0][1] == ':'){
            while (sentence[0][wordsIndex] != ':') {
                fprintf(psEntitiesFile, "%c", sentence[0][wordsIndex]);
                wordsIndex++;
            }
            fputs("\n", psEntitiesFile);
        }
    } else {
        currentIndex = 0;
    }


    functionName = sentence[currentIndex];
    actionType = getActionType(instructionsTable, functionName);
    if (actionType == 'R') {
        typeR.notInUse = "000000";
        typeR.opcode = getOpCode(functionName, instructionsTable);
        char *rs = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 1], (char **) NULL, 10), 4);
        typeR.rs = rs;
        char *rt = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 2], (char **) NULL, 10), 4);
        typeR.rt = rt;
        char *rd = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 3], (char **) NULL, 10), 4);
        typeR.rd = rd;
        typeR.funct = getFuncCode(functionName, instructionsTable);
        /* debug */
        printf("action type is %c\n", actionType);
        printf("typeR.opcode %s\n", typeR.opcode);
        printf("typeR.rs  %s\n", typeR.rs);
        printf("typeR.rt  %s\n", typeR.rt);
        printf("typeR.rd  %s\n", typeR.rd);
        printf("typeR.funct  %s\n", typeR.funct);
        printf("typeR.notInUse %s\n", typeR.notInUse);
    } else if (actionType == 'I') {
        typeI.opcode = getOpCode(functionName, instructionsTable);
        char *rs = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 1], (char **) NULL, 10), 4);
        typeI.rs = rs;
        if (strcmp(functionName, "beq") == 0 || strcmp(functionName, "bne") == 0 || strcmp(functionName, "blt") == 0 ||
            strcmp(functionName, "bgt") == 0) {
            char *rt = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 2], (char **) NULL, 10), 4);
            typeI.rt = rt;
        } else {
            char *rt = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 3], (char **) NULL, 10), 4);
            typeI.rt = rt;
            char *immed = convertFromDecimalToBinary((int) strtol(sentence[currentIndex + 2], (char **) NULL, 10), 15);
            typeI.immed = immed;
        }

        /* debug */
        printf("action type is %c\n", actionType);
        printf("typeI.opcode %s\n", typeI.opcode);
        printf("typeI.rs  %s\n", typeI.rs);
        printf("typeI.rt  %s\n", typeI.rt);
        printf("typeI.immed  %s\n", typeI.immed);
    } else{
        typeJ.opcode = getOpCode(functionName, instructionsTable);
        if (isLowerCase(sentence[currentIndex + 1][0]))
            typeJ.reg = '0';
        else
            typeJ.reg = '1';





        /* debug */
        printf("action type is %c\n", actionType);
        printf("typeJ.opcode %s\n", typeJ.opcode);
        printf("typeJ.reg  %c\n", typeJ.reg);
    }


    char translateLine[34];
    memset(translateLine, 0, 34);


    if (actionType == 'R') {
        strcat(translateLine, typeR.opcode);
        strcat(translateLine, typeR.rs);
        strcat(translateLine, typeR.rt);
        strcat(translateLine, typeR.rd);
        strcat(translateLine, typeR.funct);
        strcat(translateLine, typeR.notInUse);
        strcat(translateLine, "\n");
    } else if (actionType == 'I') {
        strcat(translateLine, typeI.opcode);
        strcat(translateLine, typeI.rs);
        strcat(translateLine, typeI.rt);
        strcat(translateLine, typeI.immed);
        strcat(translateLine, "\n");
    }

    printf("translateLine %s", translateLine);


    FinalTable table[100];
    int k = 100, l, tableIndex = 0;
    for (l = 0; l < 10; l++) {
        table[l].address = k;
        table[l].machineCode = translateLine;
        table[l].sourceCode = original;

    }

    printf("%d %s %s", table[tableIndex].address, table[tableIndex].sourceCode, table[tableIndex].machineCode);

    psMainFile = fopen("ps.ob", "w");
    char c_num[9];
    int m = (int) strlen(table[tableIndex].machineCode) - 1;

    fprintf(psMainFile, "00%d ", table[tableIndex].address);

    /* copy eight characters, starting at the end */
    while (m >= 0) {
        strncpy(c_num, &table[tableIndex].machineCode[m], 8);
        int hex = convertFromBinaryToHex(c_num);
        fprintf(psMainFile, "%x ", hex);
        m -= 8;
        memset(c_num, 0, 9);
        /*tableIndex++;*/
    }

    fprintf(psMainFile, "\n");



    /*  int x;
      x = remove("ps.ob");
      printf("%d",x);*/


    /* FREE MEMORY*/
    free(typeR.rs);
    free(typeR.rt);
    free(typeR.rd);
    free(typeI.immed);
    free(typeI.rs);
    free(typeI.rt);
    fclose(psMainFile);
    fclose(psExternalsFile);
    fclose(psEntitiesFile);


    return 0;
}
