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

struct binary_calculation samples_fcmpznes_32[] = {
    {0x3fc00000, 0, 0x1}, /* 1.5, -1.5 */
    {0xbfc00000, 0, 0x1}, /* -1.5, 1.5 */
    {0x3fc00000, 0, 0x1}, /* 1.5, 1.5 */
};

/* fmtvrl, mfcr32, fcmpznes */
void test_fcmpznes()
{
    unsigned int fcmpznes_psr;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fcmpznes_32) / sizeof(struct binary_calculation);
        i++)
    {
        asm volatile ("fmtvrl vr0, %1;\
            fmtvrl vr1, %2;\
            fcmpznes vr0;\
            bt32 .L1;\
            movi32 r0, 0;\
            st32.w r0, (%0, 0);\
            br32 .L2;\
            .L1:\
            movi r0, 1;\
            st32.w r0, (%0, 0);\
            .L2:"
            :
            : "r"(&fcmpznes_psr), "r"(samples_fcmpznes_32[i].op1),
            "r"(samples_fcmpznes_32[i].op2)
            : "vr0", "vr1", "r0"
        );
        TEST((fcmpznes_psr & 0x1) == samples_fcmpznes_32[i].result);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fcmpznes instructions.\n");
    test_fcmpznes();

    return done_testing();
}
