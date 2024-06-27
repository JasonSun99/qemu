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
        .float64 = {
            {0x7fefffffffffffff, 0xffefffffffffffff,},
            {0x40154afd6a012e31, 0xc0417456836cfe7b,},
        },
        .float32 = {
            {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
            {0x483471f7, 0x46f2e02b, 0xff7fffff, 0x47ad69d9, },
        },
        .float16 = {
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .float64 = {
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
        },
        .float32 = {
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x7f7fffff, },
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        },
        .float16 = {
            {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
            {0x7bff, 0x4b3d, 0xfbff, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
        },
    },
};

struct rvv_reg dst[] = {
    {
        .float64 = {
            {0x7fb28def9bdf57c0, 0x7fa62445141b1068,},
            {0x3fd8b140d0108eb6, 0xc0371fb2129cb102,},
        },
        .float32 = {
            {0xbf6befd1, 0x3e24f025, 0x3fb6de33, 0x07ad69da,},
            {0xbf6befd1, 0x3e24f025, 0x77aedcbf, 0x483c7bbf,},
        },
        .float16 = {
            {0xbb5f, 0x3128, 0x3db7, 0x385e, 0xbb5f, 0x3128, 0x3db8, 0x385e,},
            {0x0aef, 0x3128, 0x0525, 0x385e, 0xbb5f, 0x3128, 0x3db8, 0x49a2,},
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .float64 = {
            {0x7c93111855607f00, 0x7ff0000000000000,},
            {0xbcaf2f553d859050, 0x0000000000000000,},
        },
        .float32 = {
            {0xbb70f0f8, 0xc777953d, 0xc854c92e, 0xc7ad69d9,},
            {0xbb70f0f8, 0xc777953d, 0xff800000, 0x00000000,},
        },
        .float16 = {
            {0x994a, 0xc4c1, 0xcc16, 0xcb6f, 0x3c45, 0xc493, 0xcc30, 0xcb2e,},
            {0xcaee, 0xc4c1, 0x4524, 0xcb6f, 0x3c45, 0xc493, 0xcc30, 0x000,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .float64 = {
            {0x7c93111855607f00, 0x7fa62445141b1068,},
            {0xbcaf2f553d859050, 0xc0371fb2129cb102,},
        },
        .float32 = {
            {0xbb70f0f8, 0x3e24f025, 0xc854c92e, 0x07ad69da,},
            {0xbb70f0f8, 0x3e24f025, 0xff800000, 0x483c7bbf,},
        },
        .float16 = {
            {0x994a, 0x3128, 0xcc16, 0x385e, 0x3c45, 0x3128, 0xcc30, 0x385e,},
            {0xcaee, 0x3128, 0x4524, 0x385e, 0x3c45, 0x3128, 0xcc30, 0x49a2,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .float64 = {
            {0x7fb28def9bdf57c0, 0x7ff0000000000000,},
            {0x3fd8b140d0108eb6, 0xc071c22c6da61600,},
        },
        .float32 = {
            {0xbf6befd1, 0xc777953d, 0x3fb6de33, 0xc7ad69d9,},
            {0xbf6befd1, 0xc777953d, 0x77aedcbf, 0xd110272b,},
        },
        .float16 = {
            {0xbb5f, 0xc4c1, 0x3db7, 0xcb6f, 0xbb5f, 0xc493, 0x3db8, 0xcb2e,},
            {0x0aef, 0xc4c1, 0x0525, 0xcb6f, 0xbb5f, 0xc493, 0x3db8, 0xd97d,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfmsub.vf\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_16(vlmax_16 - 1, src0[i].float16[0],
                src1[i].float16[0][0], res.float16[0], dst[i].float16[0]);
        result_compare_s16_lmul(res.float16[0], dst_vl[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_16_vm(src0[i].float16[0], src1[i].float16[0][0],
                res.float16[0], vmo.fixu16, dst[i].float16[0]);
        result_compare_s16_lmul(res.float16[0], dst_odd[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_16_vm(src0[i].float16[0], src1[i].float16[0][0],
                res.float16[0], vme.fixu16, dst[i].float16[0]);
        result_compare_s16_lmul(res.float16[0], dst_even[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_32(vlmax_32 - 1, src0[i].float32[0],
                src1[i].float32[0][0], res.float32[0], dst[i].float32[0]);
        result_compare_s32_lmul(res.float32[0], dst_vl[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_32_vm(src0[i].float32[0], src1[i].float32[0][0],
                res.float32[0], vme.fixu32, dst[i].float32[0]);
        result_compare_s32_lmul(res.float32[0], dst_even[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_32_vm(src0[i].float32[0], src1[i].float32[0][0],
                res.float32[0], vmo.fixu32, dst[i].float32[0]);
        result_compare_s32_lmul(res.float32[0], dst_odd[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_64(vlmax_64 - 1, src0[i].float64[0],
                src1[i].float64[0][0], res.float64[0], dst[i].float64[0]);
        result_compare_s64_lmul(res.float64[0], dst_vl[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_64_vm(src0[i].float64[0], src1[i].float64[0][0],
                res.float64[0], vmo.fixu64, dst[i].float64[0]);
        result_compare_s64_lmul(res.float64[0], dst_odd[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfmsub_vf_64_vm(src0[i].float64[0], src1[i].float64[0][0],
                res.float64[0], vme.fixu64, dst[i].float64[0]);
        result_compare_s64_lmul(res.float64[0], dst_even[i].float64[0]);
    }

    return done_testing();
}
