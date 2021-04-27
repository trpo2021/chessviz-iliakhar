#include <stdio.h>
#include <string.h>
#include <ctest.h>

void Output_Log(char table[8][9])
{
    int i;
    for (i = 0; i < 8; i++) {
        CTEST_LOG("%d %s ", 8 - i, table[i]);
    }
    CTEST_LOG("  abcdefgh\n");
}

void board(char table[8][9])
{
    int i;
    strcpy(table[0], "rnbqkbnr");
    strcpy(table[1], "pppppppp");
    for (i = 2; i < 6; i++)
        strcpy(table[i], "        ");
    strcpy(table[6], "PPPPPPPP");
    strcpy(table[7], "RNBQKBNR");
}
