#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_queen, correct_horiz_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'Q';
    exp[5][6] = 'Q';

    res_ret = move_queen('Q', "a3-g3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[5][6] = 'Q';
    exp[5][0] = 'Q';
    exp[5][6] = ' ';

    res_ret = move_queen('Q', "g3-a3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_queen, correct_vert_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'Q';
    exp[2][0] = 'Q';
    res_ret = move_queen('Q', "a3-a6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[2][0] = 'Q';
    exp[5][0] = 'Q';
    exp[2][0] = ' ';
    res_ret = move_queen('Q', "a6-a3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_bishop, correct_diag1_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'Q';
    exp[2][3] = 'Q';
    res_ret = move_queen('Q', "a3-d6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[2][3] = 'Q';
    exp[5][0] = 'Q';
    exp[2][3] = ' ';
    res_ret = move_queen('Q', "d6-a3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_queen, correct_diag2_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][0] = 'Q';
    exp[5][3] = 'Q';
    res_ret = move_queen('Q', "a6-d3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[5][3] = 'Q';
    exp[2][0] = 'Q';
    exp[5][3] = ' ';
    res_ret = move_bishop('Q', "d3-a6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_queen, incorrect_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'Q';
    exp[5][0] = 'Q';
    res_ret = move_rook('Q', "a3-g4", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_queen, figure_on_the_way)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[3][2] = 'p';
    exp[3][2] = 'p';
    res[5][0] = 'Q';
    exp[5][0] = 'Q';
    res_ret = move_queen('Q', "a3-d6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_queen, correct_hit)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][3] = 'p';
    res[5][0] = 'Q';
    exp[2][3] = 'Q';
    res_ret = move_queen('Q', "a3xd6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
