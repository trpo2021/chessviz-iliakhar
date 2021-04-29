#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_king, correct_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][3] = 'K';
    res[7][4] = ' ';

    exp[3][3] = 'K';
    exp[7][4] = ' ';
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_king('K', "d4-d5", res);
    // Output_Log(res);
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
    res[7][4] = ' ';

    exp[4][3] = 'K';
    exp[7][4] = ' ';

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
    res[7][4] = ' ';
    // Output_Log(res);
    // CTEST_LOG(" ");

    exp[1][3] = 'K';
    exp[7][4] = ' ';
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_king('K', "d6xd7", res);
    // Output_Log(res);
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
    res[7][4] = ' ';
    // Output_Log(res);
    // CTEST_LOG(" ");
    exp[3][3] = 'K';
    exp[7][4] = ' ';
    // Output_Log(exp);
    // CTEST_LOG(" ");

    res_ret = move_king('K', "d5xd7", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, incorrect_act_move_hit)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[4][3] = 'K';
    res[7][4] = ' ';
    // Output_Log(res);
    // CTEST_LOG(" ");

    exp[4][3] = 'K';
    exp[7][4] = ' ';
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_king('K', "d4xd5", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_king, incorrect_act_hit_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][3] = 'K';
    res[7][4] = ' ';
    // Output_Log(res);
    // CTEST_LOG(" ");

    exp[2][3] = 'K';
    exp[7][4] = ' ';
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_king('K', "d6-d7", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
