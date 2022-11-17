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

/* fabsd */
void test_fabsd()
{
    union {
        double d;
        unsigned int i[2];
    } a, fabsd_res;
    a.d = 1.5;
    asm ("fmtvr.64 vr0, %2, %3;\
        fabsd vr1, vr0;\
        fmfvr.64 %0, %1, vr1;"
        : "=r"(fabsd_res.i[0]), "=r"(fabsd_res.i[1])
        : "r"(a.i[0]), "r"(a.i[1])
        : "vr0", "vr1"
    );
    TEST(fabsd_res.d == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fabsd instructions.\n");
    test_fabsd();

    return done_testing();
}
