#include <libchessviz/Move.h>
#include <libchessviz/Output.h>
#include <libchessviz/ProverkaFormata.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i = 1;
    if (argc != 2) {
        printf("Неверное колличество аргументов командной строки\n");
        return 1;
    }
    FILE* fmove;
    char table[8][9]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char s[20];
    // printf("%s",table[0]);
    if ((fmove = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    //вывод доски
    printf("\n");
    Output(table);

    while (fgets(s, 20, fmove)) {
        //проверка входных данных + добавление
        //в сторку s p/P если ходит пешка
        if (proverka_formata(table, s) == 0) {
            printf("\nНеверный формат входных данных ( %s )\n", s);
            return 0;
        }
        // printf("\nПроверка входных данных прошла успешно\n");
        if (Move(s, table, i) == 0)
            return 0;
        i++;
    }

    fclose(fmove);
    return 0;
}
