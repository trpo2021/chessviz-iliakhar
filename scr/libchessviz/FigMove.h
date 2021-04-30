#pragma once

struct coordinates{
int x1,x2,y1,y2;
};
int move_king(char fig, char s[], char table[8][9]);
void mv(char fig,struct coordinates cord, char table[8][9]);
int check_act(char fig,int x,int y, char s[], char table[8][9]);
int move_pawn(char fig, char s[], char table[8][9]);
int move_rook(char fig, char s[], char table[8][9]);
int move_bishop(char fig, char s[], char table[8][9]);
int move_queen(char fig, char s[], char table[8][9]);
int move_knight(char fig, char s[], char table[8][9]);
struct coordinates get_cord( char s[]);
