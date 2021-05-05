#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_king, correct_horiz_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][3] = 'K';
    exp[3][3] = 'K';
    res_ret = move_king('K', "d4-d5", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[3][3] = 'K';
    exp[3][3] = ' ';
    exp[4][3] = 'K';
    res_ret = move_king('K', "d5-d4", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, correct_vert_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][3] = 'K';
    exp[4][4] = 'K';
    res_ret = move_king('K', "d4-e4", res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[4][4] = 'K';
    exp[4][4] = ' ';
    exp[4][3] = 'K';
    res_ret = move_king('K', "e4-d4", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, incorrect_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][3] = 'K';
    exp[4][3] = 'K';
    res_ret = move_king('K', "d4-d6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, correct_hit)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][3] = 'K';
    exp[1][3] = 'K';
    res_ret = move_king('K', "d6xd7", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, incorrect_hit)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[3][3] = 'K';
    exp[3][3] = 'K';
    res_ret = move_king('K', "d5xd7", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, incorrect_act_move_hit)
{
    int i, exp_ret = 2, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][3] = 'K';

    exp[4][3] = 'K';
    res_ret = move_king('K', "d4xd5", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, incorrect_act_hit_move)
{
    int i, exp_ret = 2, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][3] = 'K';
    exp[2][3] = 'K';
    res_ret = move_king('K', "d6-d7", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
