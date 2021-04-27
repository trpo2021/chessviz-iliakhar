#include <libchessviz/FigMove.h>
#include <libchessviz/Move.h>
#include <libchessviz/Output.h>
#include <stdio.h>
#include <string.h>

int first_pos(char s1[], char table[8][9])
{
    int x, y;
    x = s1[1] - 'a';
    y = 7 - (s1[2] - '1');
    if (table[y][x] == s1[0])
        return 1;
    return 0;
}

int Move(char s[], char table[8][9], int k)
{
    // printf("%s\n",s);
    char s1[10] = "\0", s2[10] = "\0", fig;
    int i, beg = 0;
    for (i = 0; i < 2; i++, beg += 7) {
        printf("\n%c.%s\n", k + '0', strncpy(s1, s + beg, 6));
        s1[6] = '\0';
        strcpy(s2, s1);
        fig = s2[0];
        if (first_pos(strncpy(s1, s + beg, 3), table) == 0) {
            printf("\nНеверное исходное положение фигуры\n");
            return 0;
        }
        s1[3] = '\0';

        switch (fig) {
        case 'k':
        case 'K':
            if (move_king(fig, strcpy(s2, s2 + 1), table) == 0)
                return 0;

            break;
        default:
            break;
        }
        // mv(strncpy(s1, s + beg, 6), table);
        Output(table);
    }

    return 1;
}
