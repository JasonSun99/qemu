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

struct binary_calculation samples_fadds[] = {
    {.op1.a.f = -1.5, .op2.a.f = 1.0, .result.a.f = -0.5},
    {.op1.a.f = 1.5, .op2.a.f = 1.0, .result.a.f = 2.5}
};

/* fadds */
void test_fadds()
{
    float a = -1.5, b, fadds_res = 0;
    for (int i = 0;
        i < sizeof(samples_fadds) / sizeof(samples_fadds[0]);
        i++){
        a = samples_fadds[i].op1.a.f;
        b = samples_fadds[i].op2.a.f;
        asm ("fmts %1, fr0;\
            fmts %2, fr1;\
            fadds fr2, fr1, fr0, r2;\
            fmfs %0, fr2;"
            : "=r"(fadds_res)
            : "r"(a), "r"(b)
            : "r2"
        );
        TEST(fadds_res == samples_fadds[i].result.a.f);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fadds instructions.\n");
    test_fadds();

    return done_testing();
}
