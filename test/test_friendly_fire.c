#include <ctest.h>
#include <func_for_test.h>
#include <libchessviz/FigMove.h>
#include <stdio.h>
#include <string.h>

CTEST(friendly_fire, knig)
{
    int i, exp_ret = 2, res_ret;
    char exp[8][9], res[8][9];
    board(res);
    board(exp);

    res[5][0] = 'K';
    exp[5][0] = 'K';
    res_ret = move_bishop('K', "a3xa2", res);

    for (i = 0; i < 8; i++)
        ASSERT_STR(exp[i], res[i]);
    ASSERT_EQUAL(exp_ret, res_ret);
}
