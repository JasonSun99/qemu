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
        .wfloat64 = {
            {0x7fb28def9bdf57c0, 0x7fa62445141b1068, 0x7fb28def9bdf57c0, 0x7fa62445141b1068,},
            {0x3fd8b140d0108eb6, 0xc0371fb2129cb102, 0x3fd8b140d0108eb6, 0xc0371fb2129cb102,},
        },
        .wfloat32 = {
            {0xbf6befd1, 0x3e24f025, 0x3fb6de33, 0x07ad69da, 0xbf6befd1, 0x3e24f025, 0x3fb6de33, 0x07ad69da,},
            {0xbf6befd1, 0x3e24f025, 0x77aedcbf, 0x483c7bbf, 0xbf6befd1, 0x3e24f025, 0x77aedcbf, 0x483c7bbf,},
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .wfloat64 = {
            {0xffb28def9bdf57c0, 0xffa62445141b1068, 0xffb28def9bdf57c0, 0xffa62445141b1068,},
            {0x4221402921205436, 0x41f73810be0871e1, 0xc90879442786bbc0, 0x0000000000000000,},
        },
        .wfloat32 = {
            {0x43515a88, 0x420ba458, 0xc29d7a49, 0x42c85334, 0x434141d4, 0x4200d528, 0xc2919c65, 0x42b8eef8,},
            {0x43515a88, 0x420ba458, 0xf7aedcbf, 0xc83c62b5, 0x434141d4, 0x4200d528, 0xf7aedcbf, 0x00000000,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .wfloat64 = {
            {0xffb28def9bdf57c0, 0x7fa62445141b1068, 0xffb28def9bdf57c0, 0x7fa62445141b1068,},
            {0x4221402921205436, 0xc0371fb2129cb102, 0xc90879442786bbc0, 0xc0371fb2129cb102,},
        },
        .wfloat32 = {
            {0x43515a88, 0x3e24f025, 0xc29d7a49, 0x07ad69da, 0x434141d4, 0x3e24f025, 0xc2919c65, 0x07ad69da,},
            {0x43515a88, 0x3e24f025, 0xf7aedcbf, 0x483c7bbf, 0x434141d4, 0x3e24f025, 0xf7aedcbf, 0x483c7bbf,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .wfloat64 = {
            {0x7fb28def9bdf57c0, 0xffa62445141b1068, 0x7fb28def9bdf57c0, 0xffa62445141b1068,},
            {0x3fd8b140d0108eb6, 0x41f73810be0871e1, 0x3fd8b140d0108eb6, 0x421094119b659908,},
        },
        .wfloat32 = {
            {0xbf6befd1, 0x420ba458, 0x3fb6de33, 0x42c85334, 0xbf6befd1, 0x4200d528, 0x3fb6de33, 0x42b8eef8,},
            {0xbf6befd1, 0x420ba458, 0x77aedcbf, 0xc83c62b5, 0xbf6befd1, 0x4200d528, 0x77aedcbf, 0xc83c64a1,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfwnmacc.vf\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwnmacc_vf_16(vlmax_16 - 1, src0[i].float16[0],
                src1[i].float16[0][0], res.wfloat32[0], dst[i].wfloat32[0]);
        result_compare_s32_lmulw(res.wfloat32[0], dst_vl[i].wfloat32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwnmacc_vf_16_vm(src0[i].float16[0], src1[i].float16[0][0],
                res.wfloat32[0], vmo.fixu16, dst[i].wfloat32[0]);
        result_compare_s32_lmulw(res.wfloat32[0], dst_odd[i].wfloat32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwnmacc_vf_16_vm(src0[i].float16[0], src1[i].float16[0][0],
                res.wfloat32[0], vme.fixu16, dst[i].wfloat32[0]);
        result_compare_s32_lmulw(res.wfloat32[0], dst_even[i].wfloat32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwnmacc_vf_32(vlmax_32 - 1, src0[i].float32[0],
                src1[i].float32[0][0], res.wfloat64[0], dst[i].wfloat64[0]);
        result_compare_s64_lmulw(res.wfloat64[0], dst_vl[i].wfloat64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwnmacc_vf_32_vm(src0[i].float32[0], src1[i].float32[0][0],
                res.wfloat64[0], vme.fixu32, dst[i].wfloat64[0]);
        result_compare_s64_lmulw(res.wfloat64[0], dst_even[i].wfloat64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwnmacc_vf_32_vm(src0[i].float32[0], src1[i].float32[0][0],
                res.wfloat64[0], vmo.fixu32, dst[i].wfloat64[0]);
        result_compare_s64_lmulw(res.wfloat64[0], dst_odd[i].wfloat64[0]);
    }

    return done_testing();
}