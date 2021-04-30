#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_pawn, correct_move1)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[6][1] = 'P';
    exp[6][1] = ' ';
    exp[5][1] = 'P';
    res_ret = move_pawn('P', "b2-b3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_pawn, correct_move2)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[6][1] = 'P';
    exp[6][1] = ' ';
    exp[4][1] = 'P';
    res_ret = move_pawn('P', "b2-b4", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_pawn, incorrect_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][1] = 'P';
    exp[4][1] = 'P';
    res_ret = move_pawn('P', "b4-b3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[4][1] = 'P';
    exp[4][1] = 'P';
    res_ret = move_pawn('P', "b4-c5", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_pawn, incorrect_move2)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][1] = 'P';
    exp[5][1] = 'P';
    res_ret = move_pawn('P', "b3-b5", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_pawn, correct_hit)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[6][1] = 'P';
    res[5][2] = 'b';
    exp[6][1] = ' ';
    exp[5][2] = 'P';
    res_ret = move_pawn('P', "b2xc3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_pawn, incorrect_hit)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][1] = 'P';
    res[3][1] = 'b';
    res[5][2] = 'b';
    exp[4][1] = 'P';
    exp[3][1] = 'b';
    exp[5][2] = 'b';
    res_ret = move_pawn('P', "b2xb5", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res_ret = move_pawn('P', "b2xc1", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
