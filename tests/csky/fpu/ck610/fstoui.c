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

struct unary_calculation samples_fstoui[] = {
    {.op1.a.f = 2.2, .result.a.ui = 2.0},
    {.op1.a.f = 1.2, .result.a.ui = 1.0}
};

/* fstoui */
void test_fstoui()
{
    unsigned int fstoui_res = 0;
    for (int i = 0;
        i < sizeof(samples_fstoui) / sizeof(samples_fstoui[0]);
        i++){
        float a = samples_fstoui[i].op1.a.f;
        asm ("fmts %1, fr0;\
            fstoui fr1, fr0, RM_NEAREST, r2;\
            fmfs %0, fr1;"
            : "=r"(fstoui_res)
            : "r"(a)
            : "r2"
        );
        TEST(fstoui_res == samples_fstoui[i].result.a.ui);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstoui instructions.\n");
    test_fstoui();

    return done_testing();
}
