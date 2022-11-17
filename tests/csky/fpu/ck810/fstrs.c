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

/* fstrs */
void test_fstrs()
{
    volatile float a[2];
    a[0] = 0;
    a[1] = 1.5;
    asm volatile ("fldrs vr0, (%0, %1 << 0);\
        fstrs vr0, (%0, %2 << 0);"
        :
        : "r"(&a[0]), "r"(4), "r"(0)
        : "vr0", "vr1"
    );
    TEST(a[0] == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstrs instructions.\n");
    test_fstrs();

    return done_testing();
}
