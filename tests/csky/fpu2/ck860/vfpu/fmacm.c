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
#include "fpu_structs.h"

/* -1.0 + -1.5 * 1.5 = -3.25 */
struct ternary_calculation_64 samples_fmacm_64[] = {
    {.op1.a.ull = 0xbf800000bf800000,
        .op2.a.ull = 0xbfc000003fc00000,
        .op3.a.ull = 0x3fc00000bfc00000,
        .result.a.ull = 0xc0500000c0500000},
};

void test_fmacm()
{
    operand_64_t fmacm_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fmacm_64) / sizeof(struct ternary_calculation_64);
        i++) {
        asm ("fmtvrl vr0, %4;\
            fmtvrh vr0, %5;\
            fmtvrl vr1, %6;\
            fmtvrh vr1, %7;\
            fmtvrl vr2, %2;\
            fmtvrh vr2, %3;\
            fmacm vr2, vr0, vr1;\
            fmfvrl %0, vr2;\
            fmfvrh %1, vr2;"
            : "=r"(fmacm_res.a.i[0]), "=r"(fmacm_res.a.i[1])
            : "r"(samples_fmacm_64[i].op1.a.i[0]),
            "r"(samples_fmacm_64[i].op1.a.i[1]),
            "r"(samples_fmacm_64[i].op2.a.i[0]),
            "r"(samples_fmacm_64[i].op2.a.i[1]),
            "r"(samples_fmacm_64[i].op3.a.i[0]),
            "r"(samples_fmacm_64[i].op3.a.i[1])
            : "vr0", "vr1", "vr2"
        );
        TEST(fmacm_res.a.ull == samples_fmacm_64[i].result.a.ull);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmacm instructions.\n");
    test_fmacm();

    return done_testing();
}
