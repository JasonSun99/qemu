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
#include "dspv3_insn.h"

struct vdsp_reg src[] = {
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
    {
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
    {
        .fixs32 = {0x2ef3c1ca, 0xd167753f, 0xd345a93c, 0xcb8a4543, },
        .fixs16 = {0xf0f6, 0x8940, 0xf0cf, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0x86d3, },
        .fixs8 = {0x5a, 0xeb, 0x19, 0x10, 0x5b, 0xcd, 0xa0, 0xda, 0x8f, 0x29, 0xb3, 0x35, 0x3d, 0xda, 0x0d, 0x99, },
    },
    {
        .fixs32 = {0xb62db774, 0x0709f7b4, 0x6c9c7bcc, 0xa8c6d274, },
        .fixs16 = {0xbb9b, 0xb82a, 0x94a5, 0x70b4, 0x29b7, 0x8c06, 0x7c45, 0xaca1, },
        .fixs8 = {0xb5, 0x33, 0x70, 0x25, 0xd1, 0xaf, 0x8c, 0x2b, 0x97, 0xcd, 0x2d, 0x8a, 0xf5, 0x3a, 0x83, 0x10, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0x2ef3c1ca, 0xd167753f, 0xd345a93c, 0xcfe06686, },
        .fixs16 = {0xf0f6, 0x8940, 0xf0cf, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0xd6d6,  },
        .fixs8 = {0x5a, 0xeb, 0x19, 0x10, 0x5b, 0xcd, 0xa0, 0xda, 0x8f, 0x29, 0xb3, 0x35, 0x3d, 0xda, 0x0d, 0xa5, },
    },
};

struct vdsp_reg dst1[] = {
    {
        .fixs32 = {0x7794d541, 0x0709f7b4, 0x6c9c7bcc, 0xa8c6d274, },
        .fixs16 = {0x4fb8, 0xb82a, 0x94a5, 0x70b4, 0x29b7, 0x8c06, 0x7c45, 0xaca1, },
        .fixs8 = {0x21, 0x33, 0x70, 0x25, 0xd1, 0xaf, 0x8c, 0x2b, 0x97, 0xcd, 0x2d, 0x8a, 0xf5, 0x3a, 0x83, 0x10, },
    },
};

struct vdsp_reg res[2];

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vpkg.t.2\n");

    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vpkg_8_2(src[4 * i].fixs8, res[0].fixs8);
        result_compare_s8(res[0].fixs8, dst0[i].fixs8);
        result_compare_s8(res[1].fixs8, dst1[i].fixs8);
    }

    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vpkg_16_2(src[4 * i].fixs16, res[0].fixs16);
        result_compare_s16(res[0].fixs16, dst0[i].fixs16);
        result_compare_s16(res[1].fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vpkg_32_2(src[4 * i].fixs32, res[0].fixs32);
        result_compare_s32(res[0].fixs32, dst0[i].fixs32);
        result_compare_s32(res[1].fixs32, dst1[i].fixs32);
    }

    return done_testing();
}
