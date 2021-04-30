#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_rook, correct_horiz_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'R';
    exp[5][6] = 'R';

    res_ret = move_rook('R', "a3-g3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[5][6] = 'R';
    exp[5][0] = 'R';
    exp[5][6] = ' ';

    res_ret = move_rook('R', "g3-a3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_rook, correct_vert_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'R';
    exp[2][0] = 'R';

    res_ret = move_rook('R', "a3-a6", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[2][0] = 'R';
    exp[5][0] = 'R';
    exp[2][0] = ' ';

    res_ret = move_rook('R', "a6-a3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_rook, incorrect_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'R';
    exp[5][0] = 'R';
    res_ret = move_rook('R', "a3-b4", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_rook, figure_on_the_way)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][3] = 'p';
    exp[5][3] = 'p';
    res[5][0] = 'R';
    exp[5][0] = 'R';

    res_ret = move_rook('R', "a3-g3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_rook, correct_hit)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][6] = 'p';
    res[5][0] = 'R';
    exp[5][6] = 'R';

    res_ret = move_rook('R', "a3xg3", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
