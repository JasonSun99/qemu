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
 * Lesser General Public License  *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "testsuite.h"
#include "rvv_insn.h"

struct rvv_reg src0[] =
{
    {
        .fixu8 =
        {
            {
                0x01, 0x01, 0x01, 0x01,
                0x02, 0x02, 0x02, 0x02,
                0x03, 0x03, 0x03, 0x03,
                0x04, 0x04, 0x04, 0x04,
            },
        },
    },
};

int64_t src1 = -1;

struct rvv_reg dst_vl[] = {
    {
        .fixs32 = {
            {0x1111110d, 0x11111109, 0x11111105, 0x11111105, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs32 = {
            {0x1111110f, 0x1111110d, 0x1111110b, 0x11111109, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs32 = {
            {0x1111110f, 0x1111110d, 0x1111110b, 0x11111109, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    init_testsuite("Testing insn vmaqasu.vx\n");

    /* vmaqasu.vx */
    test_vmaqasu_vx(src0[0].fixu8[0], src1, res.fixs32[0], &vma8, pad.fixs32[0]);
    result_compare_s32(res.fixs32[0], dst_vl[0].fixs32[0]);

    test_vmaqasu_vx(src0[0].fixu8[0], src1, res.fixs32[0], &vme8, pad.fixs32[0]);
    result_compare_s32(res.fixs32[0], dst_even[0].fixs32[0]);

    test_vmaqasu_vx(src0[0].fixu8[0], src1, res.fixs32[0], &vmo8, pad.fixs32[0]);
    result_compare_s32(res.fixs32[0], dst_odd[0].fixs32[0]);

    return done_testing();
}