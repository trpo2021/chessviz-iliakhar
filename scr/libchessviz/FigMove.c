#include <libchessviz/FigMove.h>
#include <libchessviz/figmove_func.h>
#include <stdio.h>
#include <stdlib.h>

struct coordinates get_cord(char s[])
{
    struct coordinates cord;
    cord.x1 = s[0] - 'a';
    cord.y1 = 7 - (s[1] - '1');
    cord.x2 = s[3] - 'a';
    cord.y2 = 7 - (s[4] - '1');
    return cord;
}

int move_king(char fig, char s[], char table[8][9])
{
    struct coordinates cord;
    int bl = 1, dx, dy;
    cord = get_cord(s);
    dx = cord.x2 - cord.x1;
    dy = cord.y2 - cord.y1;

    if (check_act(fig, cord.x2, cord.y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (!(dx == 1 || dx == -1 || dx == 0))
        bl = 0;
    if (!(dy == 1 || dy == -1 || dy == 0))
        bl = 0;
    if (cord.x2 == cord.x1 && cord.y2 == cord.y1)
        bl = 0;

    if (bl == 1)
        mv(fig, cord, table);
    else {
        printf("Ход невозможен\n");
        return 0;
    }

    return 1;
}

int move_pawn(char fig, char s[], char table[8][9])
{
    struct coordinates cord;
    int bl = 1, forward, dx, dy;
    cord = get_cord(s);
    dx = cord.x2 - cord.x1;
    dy = cord.y2 - cord.y1;

    if (fig == 'p')
        forward = 1;
    else
        forward = -1;

    if (check_act(fig, cord.x2, cord.y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (s[2] == '-') {
        if (!((dy == forward
               || ((cord.y1 == 1 || cord.y1 == 6) && dy == 2 * forward))
              && dx == 0))
            bl = 0;
    }
    if (s[2] == 'x') {
        if (!(dy == forward && (dx == 1 || dx == -1)))
            bl = 0;
    }

    if (bl == 1)
        mv(fig, cord, table);
    else {
        printf("Ход невозможен\n");
        return 0;
    }

    return 1;
}

int move_rook(char fig, char s[], char table[8][9])
{
    struct coordinates cord;
    int bl = 1, dx, dy;
    int i, xmove = 0, ymove = 0, sig = 1;
    cord = get_cord(s);
    dx = cord.x2 - cord.x1;
    dy = cord.y2 - cord.y1;
    if (dx != 0)
        xmove = 1;
    else
        ymove = 1;
    if (dx < 0 || dy < 0)
        sig = -1;
    if (check_act(fig, cord.x2, cord.y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (!((dx == 0 || dy == 0) && dx != dy))
        bl = 0;
    for (i = 1; i < abs(dx - dy); i++) {
        if (xmove != 0)
            xmove = i * sig;
        else
            ymove = i * sig;
        if (table[cord.y1 + ymove][cord.x1 + xmove] != ' ') {
            bl = 0;
            break;
        }
    }
    if (bl == 1)
        mv(fig, cord, table);
    else {
        printf("Ход невозможен\n");
        return 0;
    }
    return 1;
}

int move_bishop(char fig, char s[], char table[8][9])
{
    struct coordinates cord;
    int bl = 1, dx, dy;
    int i, ysig = 1, xsig = 1;
    cord = get_cord(s);
    dx = cord.x2 - cord.x1;
    dy = cord.y2 - cord.y1;

    if (dx < 0)
        xsig = -1;
    if (dy < 0)
        ysig = -1;
    if (check_act(fig, cord.x2, cord.y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (!(abs(dx) == abs(dy) && dx != 0)) {
        bl = 0;
    }
    for (i = 1; i < abs(dx); i++) {
        if (table[cord.y1 + i * ysig][cord.x1 + i * xsig] != ' ') {
            bl = 0;
            break;
        }
    }
    if (bl == 1)
        mv(fig, cord, table);
    else {
        printf("Ход невозможен\n");
        return 0;
    }
    return 1;
}

int move_queen(char fig, char s[], char table[8][9])
{
    struct coordinates cord;
    int bl = 1, dx, dy, max_d;
    int i, xmove = 0, ymove = 0, xsig = 1, ysig = 1;
    cord = get_cord(s);
    dx = cord.x2 - cord.x1;
    dy = cord.y2 - cord.y1;
    if (dx > dy)
        max_d = dx;
    else
        max_d = dy;
    if (dx != 0)
        xmove = 1;
    if (dy != 0)
        ymove = 1;
    if (dx < 0)
        xsig = -1;
    if (dy < 0)
        ysig = -1;
    if (check_act(fig, cord.x2, cord.y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (!((dx == 0 || dy == 0 || abs(dx) == abs(dy)) && (dx != 0 || dy != 0)))
        bl = 0;
    for (i = 1; i < abs(max_d); i++) {
        if (xmove != 0)
            xmove = i * xsig;
        if (ymove != 0)
            ymove = i * ysig;
        // printf("# %d %d %c
        // #\n",xmove,ymove,table[cord.y1+ymove][cord.x1+xmove]!=' ');
        if (table[cord.y1 + ymove][cord.x1 + xmove] != ' ') {
            bl = 0;
            break;
        }
    }
    if (bl == 1)
        mv(fig, cord, table);
    else {
        printf("Ход невозможен\n");
        return 0;
    }
    return 1;
}

int move_knight(char fig, char s[], char table[8][9])
{
    struct coordinates cord;
    int bl = 1, dx, dy;
    cord = get_cord(s);
    dx = cord.x2 - cord.x1;
    dy = cord.y2 - cord.y1;

    if (check_act(fig, cord.x2, cord.y2, s, table) == 0) {
        printf("\nНеверное действие\n");
        return 0;
    }

    if (!((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)))
        bl = 0;
    if (bl == 1)
        mv(fig, cord, table);
    else {
        printf("Ход невозможен\n");
        return 0;
    }

    return 1;
}
