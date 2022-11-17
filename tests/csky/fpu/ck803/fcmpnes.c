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

struct binary_calculation samples_fcmpnes_32[] = {
    {0xbfc00000, 0x3fc00000, 0x1}, /* -1.5, 1.5 */
    {0x3fc00000, 0x3fc00000, 0x0}, /* 1.5, 1.5 */
};

/* fmtvrl, mfcr32, fcmpnes */
void test_fcmpnes()
{
    unsigned int fcmpnes_psr;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fcmpnes_32) / sizeof(struct binary_calculation);
        i++)
    {
        asm ("fmtvrl vr0, %1;\
            fmtvrl vr1, %2;\
            fcmpnes vr0, vr1;\
            mfcr32 %0, cr<0, 0>"
            : "=r"(fcmpnes_psr)
            : "r"(samples_fcmpnes_32[i].op1), "r"(samples_fcmpnes_32[i].op2)
            : "vr0", "vr1"
        );
        TEST((fcmpnes_psr & 0x1) == samples_fcmpnes_32[i].result);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fcmpnes instructions.\n");
    test_fcmpnes();

    return done_testing();
}
