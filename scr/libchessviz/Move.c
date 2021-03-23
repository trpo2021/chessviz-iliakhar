#include <libchessviz/Move.h>
#include <libchessviz/Output.h>
#include <stdio.h>
#include <string.h>

int first_pos(char s1[], char table[8][8])
{
    int x, y;
    x = s1[1] - 'a';
    y = 7 - (s1[2] - '1');
    if (table[y][x] == s1[0])
        return 1;
    return 0;
}

int second_pos(char s1[], char table[8][8])
{
    //Проверка на выход за границы доски проверяется в ProverkaFormata.c
    //тк нельзя ввести число вне a-h и цифру вне 1-8
    int x, y;
    x = s1[1] - 'a';
    y = 7 - (s1[2] - '1');
    if (s1[0] == '-' && table[y][x] == ' ')
        return 1;
    if (s1[0] == 'x' && table[y][x] != ' ')
        return 1;
    return 0;
}

void mv(char s1[], char table[8][8])
{
    int x, y;
    x = s1[1] - 'a';
    y = 7 - (s1[2] - '1');
    table[y][x] = ' ';

    x = s1[4] - 'a';
    y = 7 - (s1[5] - '1');
    table[y][x] = s1[0];
}

int Move(char s[], char table[8][8], int k)
{
    // printf("%s\n",s);
    char s1[10] = "\0", choice = '\0';
    int i;
    for (i = 0; i < 2; i++) {
        switch (i) {
        case 0:
            choice = s[0];
            printf("\n%c.%s\n", k + '0', strncpy(s1, s, 6));
            break;
        case 1:
            choice = s[7];
            printf("\n%c.%s\n", k + '0', strncpy(s1, s + 7, 6));
            break;
        }
        switch (choice) {
        case 'P':
            if (first_pos(strncpy(s1, s, 3), table) == 0) {
                printf("\nНеверное исходное положение фигуры\n");
                return 0;
            }
            if (second_pos(strncpy(s1, s + 3, 3), table) == 0) {
                printf("\nНеверное действие\n");
                return 0;
            }
            printf("\n");
            mv(strncpy(s1, s, 6), table);
            Output(table);
            break;
        case 'p':
            if (first_pos(strncpy(s1, s + 7, 3), table) == 0) {
                printf("\nНеверное исходное положение фигуры\n");
                return 0;
            }
            if (second_pos(strncpy(s1, s + 10, 3), table) == 0) {
                printf("\nНеверное действие\n");
                return 0;
            }
            printf("\n");
            mv(strncpy(s1, s + 7, 6), table);
            Output(table);
            break;
        default:
            printf("\nДля данной фигуры не реализовано перемещение\n");
        }
    }

    return 1;
}
