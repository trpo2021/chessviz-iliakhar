#include "Output.h"
#include <stdio.h>

void Output(char table[8][9])
{
    int i, j;
    for (i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (j = 0; j < 8; j++)
            printf("%c ", table[i][j]);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}
