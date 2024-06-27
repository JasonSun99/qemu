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
        .fixs64 = {
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        },
        .fixs32 = {
            {0xcfe06686, 0x80000001, 0x15fc5221, 0x7fff745a, },
            {0xcfe06686, 0x80000001, 0x15fc5221, 0x7fff745a, },
        },
        .fixs16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
        .fixu64 = {
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        },
        .fixu32 = {
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        },
        .fixu16 = {
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        },
        .fixu8 = {
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
        },
    },
};

int8_t   src1_s8[2] = {0x7d, 0x3f,};
int16_t src1_s16[2] = {0xaf83, 0x5f3f,};
int32_t src1_s32[2] = {0x80000083, 0x7fff3278,};
int64_t src1_s64[2] = {0x8000011d617caf83, 0x7ffff11d617caf3f,};

uint8_t   src1_u8 = 0x5f;
uint16_t src1_u16 = 0x5fff;
uint32_t src1_u32 = 0x3fffffff;
uint64_t src1_u64 = 0x9234567887654321;

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0xb970b6b69c2ea195, 0x8000000000000000},
            {0xb970b6b69c2ea195, 0x0000000000000000},
        },
        .fixs32 = {
            {0x80000000, 0x80000000, 0x95fc52a4, 0xffff74dd,},
            {0x80000000, 0x80000000, 0x95fc52a4, 0x00000000,},
        },
        .fixs16 = {
            {0x8659, 0x0175, 0xc072, 0xbe24, 0x8000, 0xfcc2, 0xf6e0, 0x8000,},
            {0x8659, 0x0175, 0xc072, 0xbe24, 0x8000, 0xfcc2, 0xf6e0, 0x0000,},
        },
        .fixs8 = {
            {0x22, 0x7f, 0x09, 0x7f, 0x4a, 0x7f, 0x0f, 0x7f, 0x7f, 0x7f, 0x7f, 0x0e, 0x7a, 0x28, 0x7f, 0x7f,},
            {0x22, 0x7f, 0x09, 0x7f, 0x4a, 0x7f, 0x0f, 0x7f, 0x7f, 0x7f, 0x7f, 0x0e, 0x7a, 0x28, 0x7f, 0x00,},
        },
        .fixu64 = {
            {0xffffffffffffffff, 0xae96c245ae7ae352,},
            {0xffffffffffffffff, 0x0000000000000000,},
        },
        .fixu32 = {
            {0xffffffff, 0xb5bc7c2f, 0xffffffff, 0xa83e0474,},
            {0xffffffff, 0xb5bc7c2f, 0xffffffff, 0x00000000,},
        },
        .fixu16 = {
            {0xffff, 0xab62, 0xffff, 0x68bb, 0xcf15, 0x6dda, 0xffff, 0xffff,},
            {0xffff, 0xab62, 0xffff, 0x68bb, 0xcf15, 0x6dda, 0xffff, 0x0000,},
        },
        .fixu8 = {
            {0xff, 0x88, 0xf8, 0x9d, 0xff, 0xe1, 0xa6, 0xe8, 0xff, 0xff, 0xff, 0xfd, 0xff, 0x86, 0x73, 0xff,},
            {0xff, 0x88, 0xf8, 0x9d, 0xff, 0xe1, 0xa6, 0xe8, 0xff, 0xff, 0xff, 0xfd, 0xff, 0x86, 0x73, 0x00,},
        },
    },

    {
        .fixs64 = {
            {0x7fffffffffffffff, 0x46a621d0a963e6ba},
            {0x7fffffffffffffff, 0x0000000000000000},
        },
        .fixs32 = {
            {0x4fdf98fe, 0xffff3279, 0x7fffffff, 0x7fffffff,},
            {0x4fdf98fe, 0xffff3279, 0x7fffffff, 0x00000000,},
        },
        .fixs16 = {
            {0x3615, 0x7fff, 0x702e, 0x6de0, 0x0288, 0x7fff, 0x7fff, 0x00a3,},
            {0x3615, 0x7fff, 0x702e, 0x6de0, 0x0288, 0x7fff, 0x7fff, 0x0000,},
        },
        .fixs8 = {
            {0xe4, 0x73, 0xcb, 0x7f, 0x0c, 0x7f, 0xd1, 0x7f, 0x7f, 0x58, 0x7b, 0xd0, 0x3c, 0xea, 0x62, 0x60,},
            {0xe4, 0x73, 0xcb, 0x7f, 0x0c, 0x7f, 0xd1, 0x7f, 0x7f, 0x58, 0x7b, 0xd0, 0x3c, 0xea, 0x62, 0x00,},
        },
    },

};

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0x8000000000000000},
            {0x1111111111111111, 0x8000000000000000},
        },
        .fixs32 = {
            {0x11111111, 0x80000000, 0x11111111, 0xffff74dd,},
            {0x11111111, 0x80000000, 0x11111111, 0xffff74dd,},
        },
        .fixs16 = {
            {0x1111, 0x0175, 0x1111, 0xbe24, 0x1111, 0xfcc2, 0x1111, 0x8000,},
            {0x1111, 0x0175, 0x1111, 0xbe24, 0x1111, 0xfcc2, 0x1111, 0x8000,},
        },
        .fixs8 = {
            {0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x0e, 0x11, 0x28, 0x11, 0x7f,},
            {0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x0e, 0x11, 0x28, 0x11, 0x7f,},
        },
        .fixu64 = {
            {0x1111111111111111, 0xae96c245ae7ae352,},
            {0x1111111111111111, 0xae96c245ae7ae352,},
        },
        .fixu32 = {
            {0x11111111, 0xb5bc7c2f, 0x11111111, 0xa83e0474,},
            {0x11111111, 0xb5bc7c2f, 0x11111111, 0xa83e0474,},
        },
        .fixu16 = {
            {0x1111, 0xab62, 0x1111, 0x68bb, 0x1111, 0x6dda, 0x1111, 0xffff,},
            {0x1111, 0xab62, 0x1111, 0x68bb, 0x1111, 0x6dda, 0x1111, 0xffff,},
        },
        .fixu8 = {
            {0x11, 0x88, 0x11, 0x9d, 0x11, 0xe1, 0x11, 0xe8, 0x11, 0xff, 0x11, 0xfd, 0x11, 0x86, 0x11, 0xff,},
            {0x11, 0x88, 0x11, 0x9d, 0x11, 0xe1, 0x11, 0xe8, 0x11, 0xff, 0x11, 0xfd, 0x11, 0x86, 0x11, 0xff,},
        },
    },

    {
        .fixs64 = {
            {0x1111111111111111, 0x46a621d0a963e6ba},
            {0x1111111111111111, 0x46a621d0a963e6ba},
        },
        .fixs32 = {
            {0x11111111, 0xffff3279, 0x11111111, 0x7fffffff,},
            {0x11111111, 0xffff3279, 0x11111111, 0x7fffffff,},
        },
        .fixs16 = {
            {0x1111, 0x7fff, 0x1111, 0x6de0, 0x1111, 0x7fff, 0x1111, 0x00a3,},
            {0x1111, 0x7fff, 0x1111, 0x6de0, 0x1111, 0x7fff, 0x1111, 0x00a3,},
        },
        .fixs8 = {
            {0x11, 0x73, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x58, 0x11, 0xd0, 0x11, 0xea, 0x11, 0x60,},
            {0x11, 0x73, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x58, 0x11, 0xd0, 0x11, 0xea, 0x11, 0x60,},
        },
    },

};

struct rvv_reg dst_even[] = {
    {
        .fixs64 = {
            {0xb970b6b69c2ea195, 0x1111111111111111},
            {0xb970b6b69c2ea195, 0x1111111111111111},
        },
        .fixs32 = {
            {0x80000000, 0x11111111, 0x95fc52a4, 0x11111111,},
            {0x80000000, 0x11111111, 0x95fc52a4, 0x11111111,},
        },
        .fixs16 = {
            {0x8659, 0x1111, 0xc072, 0x1111, 0x8000, 0x1111, 0xf6e0, 0x1111,},
            {0x8659, 0x1111, 0xc072, 0x1111, 0x8000, 0x1111, 0xf6e0, 0x1111,},
        },
        .fixs8 = {
            {0x22, 0x11, 0x09, 0x11, 0x4a, 0x11, 0x0f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7a, 0x11, 0x7f, 0x11,},
            {0x22, 0x11, 0x09, 0x11, 0x4a, 0x11, 0x0f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7a, 0x11, 0x7f, 0x11,},
        },
        .fixu64 = {
            {0xffffffffffffffff, 0x1111111111111111,},
            {0xffffffffffffffff, 0x1111111111111111,},
        },
        .fixu32 = {
            {0xffffffff, 0x11111111, 0xffffffff, 0x11111111,},
            {0xffffffff, 0x11111111, 0xffffffff, 0x11111111,},
        },
        .fixu16 = {
            {0xffff, 0x1111, 0xffff, 0x1111, 0xcf15, 0x1111, 0xffff, 0x1111,},
            {0xffff, 0x1111, 0xffff, 0x1111, 0xcf15, 0x1111, 0xffff, 0x1111,},
        },
        .fixu8 = {
            {0xff, 0x11, 0xf8, 0x11, 0xff, 0x11, 0xa6, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0x73, 0x11,},
            {0xff, 0x11, 0xf8, 0x11, 0xff, 0x11, 0xa6, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0x73, 0x11,},
        },
    },

    {
        .fixs64 = {
            {0x7fffffffffffffff, 0x1111111111111111},
            {0x7fffffffffffffff, 0x1111111111111111},
        },
        .fixs32 = {
            {0x4fdf98fe, 0x11111111, 0x7fffffff, 0x11111111,},
            {0x4fdf98fe, 0x11111111, 0x7fffffff, 0x11111111,},
        },
        .fixs16 = {
            {0x3615, 0x1111, 0x702e, 0x1111, 0x0288, 0x1111, 0x7fff, 0x1111,},
            {0x3615, 0x1111, 0x702e, 0x1111, 0x0288, 0x1111, 0x7fff, 0x1111,},
        },
        .fixs8 = {
            {0xe4, 0x11, 0xcb, 0x11, 0x0c, 0x11, 0xd1, 0x11, 0x7f, 0x11, 0x7b, 0x11, 0x3c, 0x11, 0x62, 0x11,},
            {0xe4, 0x11, 0xcb, 0x11, 0x0c, 0x11, 0xd1, 0x11, 0x7f, 0x11, 0x7b, 0x11, 0x3c, 0x11, 0x62, 0x11,},
        },
    },

};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsadd.vx\n");

   for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_8(vlmax_8 - 1, src0[0].fixs8[0], src1_s8[i],
                res.fixs8[0], pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_8_vm(src0[0].fixs8[0], src1_s8[i], res.fixs8[0],
                vmo.fixs8, pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_8_vm(src0[0].fixs8[0], src1_s8[i], res.fixs8[0],
                vme.fixs8, pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_16(vlmax_16 - 1, src0[0].fixs16[0], src1_s16[i],
                res.fixs16[0], pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_16_vm(src0[0].fixs16[0], src1_s16[i], res.fixs16[0],
                vmo.fixs16, pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_16_vm(src0[0].fixs16[0], src1_s16[i], res.fixs16[0],
                vme.fixs16, pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_32(vlmax_32 - 1, src0[0].fixs32[0], src1_s32[i],
                res.fixs32[0], pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_32_vm(src0[0].fixs32[0], src1_s32[i], res.fixs32[0],
                vme.fixs32, pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_32_vm(src0[0].fixs32[0], src1_s32[i], res.fixs32[0],
                vmo.fixs32, pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_64(vlmax_64 - 1, src0[0].fixs64[0], src1_s64[i],
                res.fixs64[0], pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_64_vm(src0[0].fixs64[0], src1_s64[i], res.fixs64[0],
                vmo.fixs64, pad.fixs64[0]);
        result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vsadd_vx_64_vm(src0[0].fixs64[0], src1_s64[i], res.fixs64[0],
                vme.fixs64, pad.fixs64[0]);
        result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);
    }

    return done_testing();
}
