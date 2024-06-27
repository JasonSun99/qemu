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
#include "rvv_insn.h"

struct rvv_reg src0[] = {
    {
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
        .fixs16 = {
            {0xffa5, 0x0034, 0xff8c, 0x0074, 0xffcd, 0x0075, 0xff92, 0x007a, },
            {0x0060, 0x0019, 0x003c, 0xff91, 0xfffd, 0xffab, 0x0023, 0x0021, },
        },
        .fixs32 = {
            {0xffffffa5, 0x00000034, 0xffffff8c, 0x00000074, },
            {0xffffffcd, 0x00000075, 0xffffff92, 0x0000007a, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0x0000000000000034, },
            {0xffffffffffffff8c, 0x0000000000000074, },
        }
    },
};

struct rvv_reg dst0[] = {
    {
        .fixs8 = {
            {0xa5, 0x8c, 0xcd, 0x92, 0x60, 0x3c, 0xfd, 0x23, 0xa5, 0x8c, 0xcd, 0x92, 0x60, 0x3c, 0xfd, 0x23, },
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        },
        .fixs16 = {
            {0xffa5, 0xff8c, 0xffcd, 0xff92, 0x0060, 0x003c, 0xfffd, 0x0023, },
            {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        },
        .fixs32 = {
            {0xffffffa5, 0xffffff8c, 0xffffffcd, 0xffffff92, },
            {0x00000000, 0x00000000, 0x00000000, 0x00000000, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0xffffffffffffff8c, },
            {0x0000000000000000, 0x0000000000000000, },
        },
    },
    {
        .fixs8 = {
            {0xa5, 0x11, 0xcd, 0x11, 0x60, 0x11, 0xfd, 0x11, 0xa5, 0x11, 0xcd, 0x11, 0x60, 0x11, 0xfd, 0x11, },
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        },
        .fixs16 = {
            {0xffa5, 0x1111, 0xffcd, 0x1111, 0x0060, 0x1111, 0xfffd, 0x1111, },
            {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        },
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0xffffffcd, 0x11111111, },
            {0x00000000, 0x00000000, 0x00000000, 0x00000000, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0x1111111111111111, },
            {0x0000000000000000, 0x0000000000000000, },
        },
    },
    {
        .fixs8 = {
            {0x11, 0x8c, 0x11, 0x92, 0x11, 0x3c, 0x11, 0x23, 0x11, 0x8c, 0x11, 0x92, 0x11, 0x3c, 0x11, 0x23, },
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        },
        .fixs16 = {
            {0x1111, 0xff8c, 0x1111, 0xff92, 0x1111, 0x003c, 0x1111, 0x0023, },
            {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        },
        .fixs32 = {
            {0x11111111, 0xffffff8c, 0x11111111, 0xffffff92, },
            {0x00000000, 0x00000000, 0x00000000, 0x00000000, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xffffffffffffff8c, },
            {0x0000000000000000, 0x0000000000000000, },
        },
    },

};

struct rvv_reg res0;

int main(void)
{
    init_testsuite("Testing insn vlse\n");

    /* sew 8 */
    test_vlse_8(vlmax_8 / 2, &pad.fixs8[0], src0[0].fixs8[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[0].fixs8[0]);

    test_vlse_8_vm(vlmax_8 / 2, &vme.fixs8, &pad.fixs8[0], src0[0].fixs8[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[1].fixs8[0]);

    test_vlse_8_vm(vlmax_8 / 2, &vmo.fixs8, &pad.fixs8[0], src0[0].fixs8[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[2].fixs8[0]);

    /* sew 16 */
    test_vlse_16(vlmax_16 / 2, &pad.fixs16[0], src0[0].fixs16[0], res0.fixs16[0]);
    result_compare_s16_lmul(res0.fixs16[0], dst0[0].fixs16[0]);

    test_vlse_16_vm(vlmax_16 / 2, &vme.fixs16, &pad.fixs16[0], src0[0].fixs16[0], res0.fixs16[0]);
    result_compare_s16_lmul(res0.fixs16[0], dst0[1].fixs16[0]);

    test_vlse_16_vm(vlmax_16 / 2, &vmo.fixs16, &pad.fixs16[0], src0[0].fixs16[0], res0.fixs16[0]);
    result_compare_s16_lmul(res0.fixs16[0], dst0[2].fixs16[0]);

    /* sew 32 */
    test_vlse_32(vlmax_32 / 2, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[0].fixs32[0]);

    test_vlse_32_vm(vlmax_32 / 2, &vme.fixs32, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[1].fixs32[0]);

    test_vlse_32_vm(vlmax_32 / 2, &vmo.fixs32, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[2].fixs32[0]);

    /* sew 64 */
    test_vlse_64(vlmax_64 / 2, &pad.fixs64[0], src0[0].fixs64[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[0].fixs64[0]);

    test_vlse_64_vm(vlmax_64 / 2, &vme.fixs64, &pad.fixs64[0], src0[0].fixs64[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[1].fixs64[0]);

    test_vlse_64_vm(vlmax_64 / 2, &vmo.fixs64, &pad.fixs64[0], src0[0].fixs64[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[2].fixs64[0]);

    return done_testing();
}
