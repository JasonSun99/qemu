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
#include "nvic_insn.h"
#define TEST_TIMES      1
int main(void)
{
    init_testsuite("Testing insn ipush \n");

    /*
     * ipush
     * MEM[sp-4]~MEM[sp - 24] = {r13, r12, r3~r0}, sp=sp - 24
     * if test_ipush return 0, succeed, otherwise, fail.
     */
    TEST(test_ipush() == 0);
    return done_testing();
}

