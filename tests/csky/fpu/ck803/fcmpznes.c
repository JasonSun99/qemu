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

/* fmtvrl, mfcr32, fcmpznes */
void test_fcmpznes()
{
    unsigned int fcmpznes_res;
    float a = 0;
    asm("fmtvrl vr0, %1;\
        fcmpznes vr0;\
        mfcr32 %0, cr<0, 0>;"
        : "=r"(fcmpznes_res)
        : "r"(a)
        : "vr0"
    );
    TEST((fcmpznes_res & 0x1) == 0);

    a = 1.0;
    asm("fmtvrl vr0, %1;\
        fcmpznes vr0;\
        mfcr32 %0, cr<0, 0>;"
        : "=r"(fcmpznes_res)
        : "r"(a)
        : "vr0"
    );
    TEST((fcmpznes_res & 0x1) == 1);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fcmpznes instructions.\n");
    test_fcmpznes();

    return done_testing();
}
