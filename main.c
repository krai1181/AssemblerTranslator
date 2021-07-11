#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    char *number = convertFromDecimalToBinary(3);

    reverseString(number);
    printf("%s",number);

    printf("\n");

    free(number);
    return 0;
}
