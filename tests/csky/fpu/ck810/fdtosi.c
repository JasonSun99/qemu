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

void show_bit(void *bit)
{
    unsigned long long int num = *((unsigned long long *)bit);
    /*printf("num = %lld\n", num);*/
    int i;
    unsigned long long tmp = 0x8000000000000000;
    for (i = 63; i >= 0; i--) {
        if (num & (tmp)) {
            printf("1");
        } else {
            printf("0");
        }
        tmp >>= 1;
    }
    printf("\n");
}

/* fmtvrl, fmfvrl, fmfvrh, fmtvrh, fdtosi */
void test_fdtosi()
{
    union {
        double d;
        unsigned int i[2];
    } a;
    a.d = -1.5;
    int res;
    asm ("fmtvrl vr0, %1;\
        fmtvrh vr0, %2;\
        fdtosi.rn vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a.i[0]), "r"(a.i[1])
        : "vr0", "vr1"
        );
    /*printf("a = %lf, res = %d\n", a.d, res);*/
    TEST(res == -2);

    asm ("fmtvrl vr0, %1;\
        fmtvrh vr0, %2;\
        fdtosi.rz vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a.i[0]), "r"(a.i[1])
        : "vr0", "vr1"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -1);

    asm ("fmtvrl vr0, %1;\
        fmtvrh vr0, %2;\
        fdtosi.rpi vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a.i[0]), "r"(a.i[1])
        : "vr0", "vr1"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -1);

    asm ("fmtvrl vr0, %1;\
        fmtvrh vr0, %2;\
        fdtosi.rni vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a.i[0]), "r"(a.i[1])
        : "vr0", "vr1"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -2);
}

/* fmtvrl, fmfvrl, fstoui */
int main()
{
    int i = 0;
    init_testsuite("Testing fpu fdtosi instructions.\n");
    test_fdtosi();

    return done_testing();
}
