#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(test_bishop, correct_diag1_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'B';
    exp[2][3] = 'B';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "a3-d6", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[2][3] = 'B';
    exp[5][0] = 'B';
    exp[2][3] = ' ';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "d6-a3", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_bishop, correct_diag2_move)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][0] = 'B';
    exp[5][3] = 'B';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "a6-d3", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);

    res[5][3] = 'B';
    exp[2][0] = 'B';
    exp[5][3] = ' ';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "d3-a6", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_bishop, incorrect_move)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'B';
    exp[5][0] = 'B';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "a3-g3", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_bishop, figure_on_the_way)
{
    int i, exp_ret = 0, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[3][2] = 'p';
    exp[3][2] = 'p';
    res[5][0] = 'B';
    exp[5][0] = 'B';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "a3-d6", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}

CTEST(test_bishop, correct_hit)
{
    int i, exp_ret = 1, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[2][3] = 'p';
    res[5][0] = 'B';
    exp[2][3] = 'B';
    // Output_Log(res);
    // CTEST_LOG(" ");
    // Output_Log(exp);
    // CTEST_LOG(" ");
    res_ret = move_bishop('B', "a3xd6", res);
    // Output_Log(res);
    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
