#include <libchessviz/ProverkaFormata.h>
#include <stdio.h>
#include <string.h>

int proverka_formata_figura(
        int n, char mv[3], char m1[8], int player, int phase)
{
    //функция проверяет формат положения фигуры, phase=1 - начальное, phase=2-
    //конечное

    char fig[7];
    int i, bl = 0;
    if (player == 1)
        strcpy(fig, "PRNBQK");
    else
        strcpy(fig, "prnbqk");
    if (n == 2) {
        //если phase=1 и длина строки положения равна 2, то
        //на первое место в m1 ставится p/P и проверяется формат
        //положения, если ,то просто проверяется формат
        if (phase == 1)
            m1[strlen(m1)] = fig[0];
        if (mv[0] < 'a' || mv[0] > 'h')
            return 0;
        if (mv[1] < '1' || mv[1] > '8')
            return 0;
        strcat(m1, mv);

    }

    else if (n == 3 && phase == 1) {
        //проверка формата исходного положения всех фигур кроме пешек
        for (i = 1; i < strlen(fig); i++)
            if (mv[0] == fig[i])
                bl = 1;
        if (!bl)
            return 0;
        if (mv[1] < 'a' || mv[1] > 'h')
            return 0;
        if (mv[2] < '1' || mv[2] > '8')
            return 0;
        strcat(m1, mv);

    }

    else
        return 0;
    return 1;
}

int prov_act(char m[])
{
    if (strchr(m, '-'))
        return (strchr(m, '-') - m);
    else if (strchr(m, 'x'))
        return (strchr(m, 'x') - m);
    else
        return (-1);
}

int proverka_formata_hod(char m[8], int player)
{
    //функция проверяет есть ли в m '-' или 'x', и если есть делит строку на
    //начальное и конечное
    // положение фигуры и вызывает proverka_formata_figura для обеих, иначе
    // возвращает 0

    int act, i;
    char mv[3], m1[8] = "\0";
    act = prov_act(m);
    if (act == -1)
        return 0;

    for (i = 0; i < act; i++)
        mv[i] = m[i];
    mv[i] = '\0';

    if (proverka_formata_figura(act, mv, m1, player, 1) == 0)
        return 0;
    m1[strlen(m1)] = m[act];

    for (i = act + 1; i < strlen(m); i++)
        mv[i - act - 1] = m[i];
    mv[i - act - 1] = '\0';

    if (proverka_formata_figura(strlen(m) - act - 1, mv, m1, player, 2) == 0)
        return 0;

    strcpy(m, m1);
    return 1;
}

int proverka_formata(char table[8][8], char s[20])
{
    //функция проверяет есть ли в s ' ', и если он есть делит строку на две
    //части:
    // ход игрока 1 и ход игрока 2 и вызывает proverka_formata_hod для
    // обеих,иначе возвращает 0

    char m[8], s1[20] = "\0";
    int i, spr = 0;

    if (strchr(s, '\n'))
        s[strchr(s, '\n') - s] = '\0';

    if (strchr(s, ' '))
        spr = strchr(s, ' ') - s;
    else
        return 0;

    for (i = 0; i < spr; i++)
        m[i] = s[i];
    m[i] = '\0';

    if (proverka_formata_hod(m, 1) == 0)
        return 0;
    strcpy(s1, m);
    s1[strlen(s1)] = s[spr];

    for (i = spr + 1; i < strlen(s); i++)
        m[i - spr - 1] = s[i];
    m[i - spr - 1] = '\0';

    if (proverka_formata_hod(m, 2) == 0)
        return 0;
    strcat(s1, m);
    // printf("\n@%s@\n",s1);
    strcpy(s, s1);
    return 1;
}
