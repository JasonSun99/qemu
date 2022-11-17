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
#define TEST_TIMES      8
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MULLL.S16_F \n");

    /*
     * MULLL.S16.F
     * rz = rx[15:0] * ry[15:0] << 1, signed
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x00000001, 0x00000001, 0x00000002},
        {0x00000001, 0x7FFF7FFF, 0x0000FFFE},
        {0x00000001, 0xFFFFFFFF, 0xFFFFFFFE},
        {0xFFFFFFFF, 0xFFFFFFFF, 0x00000002},
        {0x00008000, 0x80008000, 0x80000000},
        {0x00000000, 0x00000000, 0x00000000},
        {0x00000000, 0x7FFFFFFF, 0x00000000},
        {0x80000000, 0x00008000, 0x00000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mulll_s16_f(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

