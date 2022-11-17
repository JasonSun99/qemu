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

/* fsqrt_16 */
void test_fsqrt_16()
{
    __fp16 a = 0.25, fsqrt_16_res = 0;
    asm ("fmtvrl vr0, %1;\
        fsqrt.16 vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(fsqrt_16_res)
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(fsqrt_16_res == 0.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsqrt.16 instructions.\n");
    test_fsqrt_16();

    return done_testing();
}
