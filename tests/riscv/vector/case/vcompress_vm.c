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
        .fixs64 = {
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        },
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixs16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .fixs8 = {
            {0x01, 0x10, 0x11, 0x10, 0x10, 0x01, 0x10, 0x10, 0x01, 0x11, 0x00, 0x11, 0x00, 0x11, 0x01, 0x01, },
        },
        .fixs16 = {
            {0x0001, 0x0100, 0x0101, 0x0100, 0x0001, 0x0101, 0x0100, 0x0001, },
        },
        .fixs32 = {
            {0x00010000, 0x00010001, 0x00010001, 0x00000001, },
        },
        .fixs64 = {
            {0x0000000100000000, 0x0000000000000001, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0xa5, 0x74, 0xcd, 0x75, 0x7a, 0x19, 0x3c, 0xab, 0x21, 0xa5, 0x8c, 0x74, 0x92, 0x7a, 0x3c, 0x91,},
            {0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
        },
        .fixs16 = {
            {0xd6d6, 0x0ea1, 0xa349, 0x4d3f, 0xa164, 0xd6d6, 0x10ef, 0x0ea1,},
            {0x4d3f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,},
        },
        .fixs32 = {
            {0x8262f661, 0x15fc5221, 0xd6b9745a, 0xcfe06686,},
            {0x8262f661, 0x00000000, 0x00000000, 0x00000000,},
        },
        .fixs64 = {
            {0xc6a630b347e7377b, 0x0000000000000000,},
            {0x0000000000000000, 0x0000000000000000,},
        },
    },

    {
        .fixs8 = {
            {0xa5, 0x74, 0xcd, 0x75, 0x7a, 0x19, 0x3c, 0xab, 0x21, 0xa5, 0x8c, 0x74, 0x92, 0x7a, 0x3c, 0x91,},
            {0xfd, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
        },
        .fixs16 = {
            {0xd6d6, 0x0ea1, 0xa349, 0x4d3f, 0xa164, 0xd6d6, 0x10ef, 0x0ea1,},
            {0x4d3f, 0x475d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,},
        },
        .fixs32 = {
            {0x8262f661, 0x15fc5221, 0xd6b9745a, 0xcfe06686,},
            {0x8262f661, 0x15fc5221, 0x00000000, 0x00000000,},
        },
        .fixs64 = {
            {0xc6a630b347e7377b, 0x3970b5993ab1f212,},
            {0x0000000000000000, 0x0000000000000000,},
        },
    },

};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vcompress.vm\n");

    /* int8_t adc */
    test_vcompress_vm_8(vlmax_8 - 2, src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[0].fixs8[0]);

    test_vcompress_vm_8(vlmax_8, src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[1].fixs8[0]);

    /* int16_t adc */
    test_vcompress_vm_16(vlmax_16 - 2, src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[0].fixs16[0]);

    test_vcompress_vm_16(vlmax_16, src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[1].fixs16[0]);

    /* int32_t adc */
    test_vcompress_vm_32(vlmax_32 - 2, src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[0].fixs32[0]);

    test_vcompress_vm_32(vlmax_32, src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[1].fixs32[0]);

    /* int64_t adc */
    test_vcompress_vm_64(vlmax_64 - 2, src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[0].fixs64[0]);

    test_vcompress_vm_64(vlmax_64, src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[1].fixs64[0]);

    return done_testing();
}
