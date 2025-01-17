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

struct rvv_reg src0[] = {
    {
        .fixu64 = {
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        },
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixu16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};


uint64_t src1 = 0x1122334455667788;

struct rvv_reg dst_vl[] = {
    {
        .fixu16 = {
            {0xd64e, 0x516a, 0x1067, 0x0e19, 0xa2c1, 0x4cb7, 0x46d5, 0xa0dc, },
            {0xd64e, 0x516a, 0x1067, 0x0e19, 0xa2c1, 0x4cb7, 0x46d5, 0xa0dc, },
            {0xd64e, 0x516a, 0x1067, 0x0e19, 0xa2c1, 0x4cb7, 0x46d5, 0xa0dc, },
            {0xd64e, 0x516a, 0x1067, 0x0e19, 0xa2c1, 0x4cb7, 0x46d5, 0x0000, },
        },
        .fixu32 = {
            {0xcfdfeefe, 0x82627ed9, 0x15fbda99, 0xd6b8fcd2, },
            {0xcfdfeefe, 0x82627ed9, 0x15fbda99, 0xd6b8fcd2, },
            {0xcfdfeefe, 0x82627ed9, 0x15fbda99, 0xd6b8fcd2, },
            {0xcfdfeefe, 0x82627ed9, 0x15fbda99, 0x00000000, },
        },
        .fixu64 = {
            {0x3970b598e54b7a8a, 0xc6a630b2f280bff3, },
            {0x3970b598e54b7a8a, 0xc6a630b2f280bff3, },
            {0x3970b598e54b7a8a, 0xc6a630b2f280bff3, },
            {0x3970b598e54b7a8a, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu16 = {
            {0xd64e, 0x1111, 0x1067, 0x1111, 0xa2c1, 0x1111, 0x46d5, 0x1111, },
            {0xd64e, 0x1111, 0x1067, 0x1111, 0xa2c1, 0x1111, 0x46d5, 0x1111, },
            {0xd64e, 0x1111, 0x1067, 0x1111, 0xa2c1, 0x1111, 0x46d5, 0x1111, },
            {0xd64e, 0x1111, 0x1067, 0x1111, 0xa2c1, 0x1111, 0x46d5, 0x1111, },
        },
        .fixu32 = {
            {0xcfdfeefe, 0x11111111, 0x15fbda99, 0x11111111, },
            {0xcfdfeefe, 0x11111111, 0x15fbda99, 0x11111111, },
            {0xcfdfeefe, 0x11111111, 0x15fbda99, 0x11111111, },
            {0xcfdfeefe, 0x11111111, 0x15fbda99, 0x11111111, },
        },
        .fixu64 = {
            {0x3970b598e54b7a8a, 0x1111111111111111, },
            {0x3970b598e54b7a8a, 0x1111111111111111, },
            {0x3970b598e54b7a8a, 0x1111111111111111, },
            {0x3970b598e54b7a8a, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu16 = {
            {0x1111, 0x516a, 0x1111, 0x0e19, 0x1111, 0x4cb7, 0x1111, 0xa0dc, },
            {0x1111, 0x516a, 0x1111, 0x0e19, 0x1111, 0x4cb7, 0x1111, 0xa0dc, },
            {0x1111, 0x516a, 0x1111, 0x0e19, 0x1111, 0x4cb7, 0x1111, 0xa0dc, },
            {0x1111, 0x516a, 0x1111, 0x0e19, 0x1111, 0x4cb7, 0x1111, 0xa0dc, },
        },
        .fixu32 = {
            {0x11111111, 0x82627ed9, 0x11111111, 0xd6b8fcd2, },
            {0x11111111, 0x82627ed9, 0x11111111, 0xd6b8fcd2, },
            {0x11111111, 0x82627ed9, 0x11111111, 0xd6b8fcd2, },
            {0x11111111, 0x82627ed9, 0x11111111, 0xd6b8fcd2, },
        },
        .fixu64 = {
            {0x1111111111111111, 0xc6a630b2f280bff3, },
            {0x1111111111111111, 0xc6a630b2f280bff3, },
            {0x1111111111111111, 0xc6a630b2f280bff3, },
            {0x1111111111111111, 0xc6a630b2f280bff3, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsubu.wx\n");

    /* uint8_t add */
    test_vwsubu_wx_8(vlmax_8 - 1, src0[i].fixu16[0], src1, res.fixu16[0], pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_vl[i].fixu16[0]);

    test_vwsubu_wx_8_vm(src0[i].fixu16[0], src1, res.fixu16[0], vme.fixu8, pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_even[i].fixu16[0]);

    test_vwsubu_wx_8_vm(src0[i].fixu16[0], src1, res.fixu16[0], vmo.fixu8, pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_odd[i].fixu16[0]);

    /* uint16_t add */
    test_vwsubu_wx_16(vlmax_16 - 1, src0[i].fixu32[0], src1, res.fixu32[0], pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_vl[i].fixu32[0]);

    test_vwsubu_wx_16_vm(src0[i].fixu32[0], src1, res.fixu32[0], vme.fixu16, pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_even[i].fixu32[0]);

    test_vwsubu_wx_16_vm(src0[i].fixu32[0], src1, res.fixu32[0], vmo.fixu16, pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_odd[i].fixu32[0]);

    /* uint32_t add */
    test_vwsubu_wx_32(vlmax_32 - 1, src0[i].fixu64[0], src1, res.fixu64[0], pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_vl[i].fixu64[0]);

    test_vwsubu_wx_32_vm(src0[i].fixu64[0], src1, res.fixu64[0], vme.fixu32, pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_even[i].fixu64[0]);

    test_vwsubu_wx_32_vm(src0[i].fixu64[0], src1, res.fixu64[0], vmo.fixu32, pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_odd[i].fixu64[0]);

    return done_testing();
}
