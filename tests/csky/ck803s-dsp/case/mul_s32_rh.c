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
#include "test_device.h"
#include "dsp_insn.h"
#define TEST_TIMES      16
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MUL.S32.RH \n");

    /*
     * MUL.S32.RH
     * rz = (rx * ry + 0x80000000)[63:32] , signed
     */
    struct binary_calculation sample[TEST_TIMES] = {
        {0x7fffffff, 0x7fffffff, 0x3fffffff},
        {0x80000000, 0x80000000, 0x40000000},
        {0xffffffff, 0xffffffff, 0x00000000},
        {0x00000000, 0x00000000, 0x00000000},
        {0x7fffffff, 0x80000000, 0xc0000001},
        {0x80000000, 0x7fffffff, 0xc0000001},
        {0x7fffffff, 0xffffffff, 0x00000000},
        {0xffffffff, 0x7fffffff, 0x00000000},
        {0x7fffffff, 0x00000000, 0x00000000},
        {0x00000000, 0x7fffffff, 0x00000000},
        {0x80000000, 0xffffffff, 0x00000001},
        {0xffffffff, 0x80000000, 0x00000001},
        {0x00000000, 0x80000000, 0x00000000},
        {0x80000000, 0x00000000, 0x00000000},
        {0xffffffff, 0x00000000, 0x00000000},
        {0x00000000, 0xffffffff, 0x00000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mul_s32_rh(sample[i].op1, sample[i].op2)
                     == sample[i].result);
    }

    return done_testing();
}

