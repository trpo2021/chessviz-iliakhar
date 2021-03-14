#include "../libchessviz/Output.h"
#include "../libchessviz/ProverkaFormata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Неверное колличество аргументов командной строки\n");
        return 1;
    }
    FILE* fmove;
    char table[8][8]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char s[20];
    if ((fmove = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    while (fgets(s, 20, fmove)) {
        printf("\n%s\n", s);
        //вывод доски
        Output(table);
        //проверка входных данных + добавление
        //в сторку s p/P если ходит пешка
        if (proverka_formata(table, s) == 0) {
            printf("Неверный формат входных данных\n");
            return 0;
        }
        printf("\nПроверка входных данных прошла успешно\n");
        // TO_DO: реализовать движение фигур
    }

    fclose(fmove);
    return 0;
}
