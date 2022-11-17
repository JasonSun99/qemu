/*
 * Copyright (C) 2017-2019 C-SKY Microsystems Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************************
 * @file     reboot.c
 * @brief    source file for the reboot
 * @version  V1.0
 * @date     04. April 2019
 ******************************************************************************/

#include <soc.h>
#include <drv_wdt.h>

void drv_reboot(void)
{
    wdt_handle_t wdt_handle;
    uint32_t irq_flag = 0;

    irq_flag = csi_irq_save();

    wdt_handle = csi_wdt_initialize(0, NULL);
    csi_wdt_start(wdt_handle);
    csi_wdt_set_timeout(wdt_handle, 0);

    /* waiting for reboot */
    while(1);

    csi_irq_restore(irq_flag);
}
