#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_knight, correct_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'N';
    exp[4][2] = 'N';
    res_ret = move_knight('N', "a3-c4", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[4][2] = 'N';
    exp[5][0] = 'N';
    exp[4][2] = ' ';
    res_ret = move_knight('N', "c4-a3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_knight, incorrect_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'N';
    exp[5][0] = 'N';
    res_ret = move_knight('N', "a3-g3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_knight, figure_on_the_way)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[7][0] = 'N';
    exp[5][1] = 'N';
    exp[7][0] = ' ';
    res_ret = move_knight('N', "a1-b3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_knight, correct_hit)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'N';
    res[4][2] = 'p';
    exp[4][2] = 'N';
    res_ret = move_knight('N', "a3xc4", res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
