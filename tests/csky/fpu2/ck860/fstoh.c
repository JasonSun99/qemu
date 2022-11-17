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

struct op1_res1_f32_f16 data[] = {
    {.op1.f = -1.0,     .res.f = -1.0},
    {.op1.f = 0.5,      .res.f = 0.5},
    {.op1.d = SpZero,   .res.d = HpZero},
    {.op1.d = SpInf,    .res.d = HpInf},
    {.op1.d = SpsNaN,   .res.d = 0x7e00},

};

void test_fstoh(float32 a, float16 expt)
{
    float16 res;
    asm ("fstoh %0, %1"
         : "=&v"(res.f)
         : "v"(a.f)
    );
    TEST(res.d == expt.d);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstoh instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op1_res1_f32_f16); i++) {
        test_fstoh(data[i].op1, data[i].res);
    }

    return done_testing();
}
