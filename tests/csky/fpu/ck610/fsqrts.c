/*
 * Copyright (c) 2021 T-Head Semiconductor Co., Ltd. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "testsuite.h"
#include "fpu_structs.h"

struct unary_calculation samples_fsqrts[] = {
    {.op1.a.f = 4.0, .result.a.f = 2.0},
    {.op1.a.f = 9.0, .result.a.f = 3.0}
};

/* fsqrts */
void test_fsqrts()
{
    float a = -1.5, fsqrts_res = 0;
    for (int i = 0;
        i < sizeof(samples_fsqrts) / sizeof(samples_fsqrts[0]);
        i++){
        a = samples_fsqrts[i].op1.a.f;
        asm ("fmts %1, fr0;\
            fsqrts fr1, fr0, r2;\
            fmfs %0, fr1;"
            : "=r"(fsqrts_res)
            : "r"(a)
            : "r2"
        );
        TEST(fsqrts_res == samples_fsqrts[i].result.a.f);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsqrts instructions.\n");
    test_fsqrts();

    return done_testing();
}
