#include <libchessviz/FigMove.h>
#include <stdio.h>

void mv(char fig, int x1, int y1, int x2, int y2, char table[8][9])
{
    table[y1][x1] = ' ';
    table[y2][x2] = fig;
}

int check_act(char fig, int x, int y, char s[], char table[8][9])
{
    if (s[2] == '-' && table[y][x] == ' ')
        return 1;
    if (fig <= 'Z')
        if (s[2] == 'x' && table[y][x] != ' ' && table[y][x] > 'Z')
            return 1;
    if (fig > 'Z')
        if (s[2] == 'x' && table[y][x] != ' ' && table[y][x] <= 'Z')
            return 1;
    return 0;
}

int move_king(char fig, char s[], char table[8][9])
{
    int x1, x2, y1, y2;
    int bl = 1;

    x1 = s[0] - 'a';
    y1 = 7 - (s[1] - '1');
    x2 = s[3] - 'a';
    y2 = 7 - (s[4] - '1');

    if (check_act(fig, x2, y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (!(x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1))
        bl = 0;
    if (!(y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1))
        bl = 0;
    if (x2 == x1 && y2 == y1)
        bl = 0;

    if (bl == 1)
        mv(fig, x1, y1, x2, y2, table);
    else{
    	printf("Ход невозможен\n");
    	return 0;
    }
        
    return 1;
}
