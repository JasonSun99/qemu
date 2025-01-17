/*
 * Copyright (c) 2021 C-SKY Microsystems Co., Ltd. All rights reserved.
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
#include "rvp_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn sclip32\n");

    for (i = 0;
         i < sizeof(samples_sclip32)/sizeof(struct binary_calculation);
         i++) {
        if (samples_sclip32[i].op2 == 0) {
            TEST(test_sclip32_0(samples_sclip32[i].op1)
                 == samples_sclip32[i].result);
        } else if (samples_sclip32[i].op2 == 1) {
            TEST(test_sclip32_1(samples_sclip32[i].op1)
                 == samples_sclip32[i].result);
        } else if (samples_sclip32[i].op2 == 5) {
            TEST(test_sclip32_5(samples_sclip32[i].op1)
                 == samples_sclip32[i].result);
        } else if (samples_sclip32[i].op2 == 30) {
            TEST(test_sclip32_30(samples_sclip32[i].op1)
                 == samples_sclip32[i].result);
        } else if (samples_sclip32[i].op2 == 31) {
            TEST(test_sclip32_31(samples_sclip32[i].op1)
                 == samples_sclip32[i].result);
        }
    }
    return done_testing();
}
