#include <libchessviz/FigMove.h>
#include <libchessviz/figmove_func.h>

void mv(char fig, struct coordinates cord, char table[8][9])
{
    table[cord.y1][cord.x1] = ' ';
    table[cord.y2][cord.x2] = fig;
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
