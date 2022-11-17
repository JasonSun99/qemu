/*
 * Copyright (C) 2017 C-SKY Microsystems Co., Ltd. All rights reserved.
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

/**************************************************************************//**
 * @file     soc.h
 * @brief    CSI Core Peripheral Access Layer Header File for
 *           CSKYSOC Device Series
 * @version  V1.0
 * @date     06. Mar 2019
 ******************************************************************************/
#ifndef _SOC_H_
#define _SOC_H_

#include <sys_freq.h>

#define reg_wr(addr) *((volatile unsigned int *)addr)
#define I2S0_BUFF_SIZE  24

#ifdef __CK804__

#ifndef SYSTEM_CLOCK
#define SYSTEM_CLOCK        (30000000) // 30Mhz fpga
#define  IHS_VALUE          (30000000)
#endif

#ifndef LSP_DEFAULT_FREQ
#define LSP_DEFAULT_FREQ    (30000000) // 30Mhz fpga
#define EHS_VALUE          (30000000)
#endif

#ifndef DSP_CLOCK
#define DSP_CLOCK           (250000000) // 220Mhz
#endif

#ifndef APB_CLOCK
#define APB_CLOCK           (30000000)  // 30Mhz
#endif

#ifndef CODEC_CLOCK
#define CODEC_CLOCK         (12000000)  // 12Mhz
#endif

#ifndef RTC_CLOCK
#define RTC_CLOCK           (32768)  // 32.768Khz
#endif

#ifndef LSP_DEFAULT_TIMER
#define LSP_DEFAULT_TIMER   (32768)  // 32.768Khz
#endif
/* ----------------------  YunVoice_V2 804ef Specific Interrupt Numbers  --------------------- */
typedef enum IRQn {
    ERROR_INTC_IRQn                 =   0,      /* error Interrupt */
    WDT_IRQn                        =   1,      /* wdt Interrupt */
    PLL_IRQn                        =   2,      /* pll lose lock Interrupt */
    PLL_FRAC_IRQn                   =   3,      /* pll lose lock Interrupt */
    WCOM_IRQn                       =   4,      /* cpu0 wcom Interrupt */
    RCOM_IRQn                       =   5,      /* cpu0 rcom Interrupt */
    PMU_IRQn                        =   6,      /* PMU Interrupt */
    MCA_IRQn                        =   7,      /* MCA Interrupt */
    DMAC0_IRQn                      =   8,      /* DMA0 Interrupt */
    DMAC1_IRQn                      =   9,      /* DMA1 Interrupt */
    CORET_IRQn                      =   10,     /* CTIM0 Interrupt */
    RTC_IRQn                        =   11,     /* RTC Interrupt */
    SDIO1_IRQn                      =   12,     /* SDMMC Interrupt */
    USB_IRQn                        =   13,     /* USB Interrupt */
    QSPI_IRQn                       =   14,     /* QSPI Interrupt */
    SDIO0_IRQn                      =   15,     /* SDIO Interrupt */
    CODEC_WHISPER_IRQn              =   16,     /* codec whisper Interrupt */
    CODEC_INTC_IRQn                 =   17,     /* code Interrupt */
    GSK_INTC_IRQn                   =   18,     /* gsk Interrupt */
    TIMER0_INT0_IRQn                =   19,     /* timer0 Interrupt */
    TIMER0_INT1_IRQn                =   20,     /* timer0  Interrupt */
    TIMER1_INT0_IRQn                =   21,     /* timer1 Interrupt */
    TIMER1_INT1_IRQn                =   22,     /* timer1 Interrupt */
    TIMER2_INT0_IRQn                =   23,     /* timer2 Interrupt */
    TIMER2_INT1_IRQn                =   24,     /* timer2  Interrupt */
    TIMER3_INT0_IRQn                =   25,     /* timer3 Interrupt */
    TIMER3_INT1_IRQn                =   26,     /* timer3  Interrupt */
    USI0_IRQn                       =   27,     /* USI0 Interrupt */
    USI1_IRQn                       =   28,     /* USI1 Interrupt */
    USI2_IRQn                       =   29,     /* USI2 Interrupt */
    USI3_IRQn                       =   30,     /* USI3 Interrupt */
    I2S0_IRQn                       =   31,     /* I2S0 Interrupt */
    I2S1_IRQn                       =   32,     /* I2S1 Interrupt */
    I2S2_IRQn                       =   33,     /* I2S2 Interrupt */
    I2S3_IRQn                       =   34,     /* I2S3 Interrupt */
    SPDIF0_IRQn                     =   35,     /* spdif0 Interrupt */
    UART0_HS_IRQn                   =   36,     /* I2S0 Interrupt */
    UART1_HS_IRQn                   =   37,     /* I2S1 Interrupt */
    UART2_IRQn                      =   38,     /* I2S2 Interrupt */
    UART3_IRQn                      =   39,     /* I2S3 Interrupt */
    TDM_IRQn                        =   40,     /* tdm Interrupt */
    PDM_IRQn                        =   41,     /* pdm Interrupt */
    GPIO0_IRQn                      =   42,     /* gpio0 Interrupt */
    PLL_LL_IRQn                     =   43,     /* pll lose lock Interrupt */
    PLL_LL_FRAC_IRQn                =   44,     /* pll lose lock FRAC Interrupt */
    PWM0_IRQn                       =   45,     /* pwm0 Interrupt */
    RSA_IRQn                        =   46,     /* rsa Interrupt */
    SHA_IRQn                        =   47,     /* sha Interrupt */
    AES_IRQn                        =   48,     /* aes Interrupt */
    TRNG_IRQn                       =   49,     /* trng Interrupt */
    GPIO1_IRQn                      =   50,     /* gpio1 Interrupt */
    PWM1_IRQn                       =   51,     /* pwm1 Interrupt */
} IRQn_Type;

#define CONFIG_DMAC_NUM         1
#define CONFIG_DMA_CHANNEL_NUM  2
#define CONFIG_I2S_NUM          2
#define CONFIG_TIMER_NUM        4
#define CONFIG_USI_NUM          2
#define CONFIG_PWM_NUM          1
#define CONFIG_AES_NUM          1
#define CONFIG_RSA_NUM          1
#define CONFIG_SHA_NUM          1
#define CONFIG_TRNG_NUM         1
#define CONFIG_RTC_NUM          1
#define CONFIG_WDT_NUM          1
#define CONFIG_QSPI_NUM         1
#define CONFIG_SPIFLASH_NUM     1
#define CONFIG_MAILBOX_NUM      3
#define CONFIG_MAILBOX_CHANNEL_NUM      2
#define CONFIG_EFUSEC_NUM       1
#define CONFIG_SDIO_NUM         2
#define CONFIG_GPIO_PIN_NUM     32
#define CONFIG_GPIO_NUM         1
#define CONFIG_USART_NUM        2


#else           /* ck805 */

#define CONFIG_QSPI_NUM         1
#define CONFIG_SPIFLASH_NUM     1
#ifndef SYSTEM_CLOCK
#define SYSTEM_CLOCK        (30000000) // 30Mhz fpga
#define  IHS_VALUE          (30000000)
#endif

#ifndef LSP_DEFAULT_FREQ
#define LSP_DEFAULT_FREQ    (30000000) // 30Mhz fpga
#define EHS_VALUE          (30000000)
#endif

#ifndef DSP_CLOCK
#define DSP_CLOCK           (250000000) // 220Mhz
#endif

#ifndef APB_CLOCK
#define APB_CLOCK           (30000000)  // 30Mhz
#endif

#ifndef CODEC_CLOCK
#define CODEC_CLOCK         (12000000)  // 12Mhz
#endif

#ifndef RTC_CLOCK
#define RTC_CLOCK           (32768)  // 32.768Khz
#endif

#ifndef LSP_DEFAULT_TIMER
#define LSP_DEFAULT_TIMER   (32768)  // 32.768Khz
#endif
#if 0
#ifndef SYSTEM_CLOCK
#define SYSTEM_CLOCK        (25000000) // 25Mhz fpga
#define  IHS_VALUE          (25000000)
#endif

#ifndef LSP_DEFAULT_FREQ
#define LSP_DEFAULT_FREQ    (25000000) // 25Mhz fpga
#define EHS_VALUE          (25000000)
#endif

#ifndef DSP_CLOCK
#define DSP_CLOCK           (250000000) // 220Mhz
#endif

#ifndef APB_CLOCK
#define APB_CLOCK           (25000000)  // 30Mhz
#endif

#ifndef CODEC_CLOCK
#define CODEC_CLOCK         (12000000)  // 12Mhz
#endif

#ifndef RTC_CLOCK
#define RTC_CLOCK           (32768)  // 32.768Khz
#endif
#endif

/* ----------------------  YunVoice_V2 805 Specific Interrupt Numbers  --------------------- */
typedef enum IRQn {
    ERROR_INTC_IRQn                 =   0,      /* error Interrupt */
    WDT_IRQn                        =   1,      /* wdt Interrupt */
    PLL_IRQn                        =   2,      /* pll lose lock Interrupt */
    PLL_FRAC_IRQn                   =   3,      /* pll lose lock Interrupt */
    WCOM_IRQn                       =   4,      /* cpu0 wcom Interrupt */
    RCOM_IRQn                       =   5,      /* cpu0 rcom Interrupt */
    PMU_IRQn                        =   6,      /* PMU Interrupt */
    MCA_IRQn                        =   7,      /* MCA Interrupt */
    DMAC0_IRQn                      =   8,      /* DMA0 Interrupt */
    DMAC1_IRQn                      =   9,      /* DMA1 Interrupt */
    CORET_IRQn                      =   10,     /* CTIM0 Interrupt */
    RTC_IRQn                        =   11,     /* RTC Interrupt */
    SDIO1_IRQn                      =   12,     /* SDMMC Interrupt */
    USB_IRQn                        =   13,     /* USB Interrupt */
    QSPI_IRQn                       =   14,     /* QSPI Interrupt */
    SDIO0_IRQn                      =   15,     /* SDIO Interrupt */
    CODEC_WHISPER_IRQn              =   16,     /* codec whisper Interrupt */
    CODEC_INTC_IRQn                 =   17,     /* code Interrupt */
    GSK_INTC_IRQn                   =   18,     /* gsk Interrupt */
    TIMER0_INT0_IRQn                =   19,     /* timer0 Interrupt */
    TIMER0_INT1_IRQn                =   20,     /* timer0  Interrupt */
    TIMER1_INT0_IRQn                =   21,     /* timer1 Interrupt */
    TIMER1_INT1_IRQn                =   22,     /* timer1 Interrupt */
    TIMER2_INT0_IRQn                =   23,     /* timer2 Interrupt */
    TIMER2_INT1_IRQn                =   24,     /* timer2  Interrupt */
    TIMER3_INT0_IRQn                =   25,     /* timer3 Interrupt */
    TIMER3_INT1_IRQn                =   26,     /* timer3  Interrupt */
    USI0_IRQn                       =   27,     /* USI0 Interrupt */
    USI1_IRQn                       =   28,     /* USI1 Interrupt */
    USI2_IRQn                       =   29,     /* USI2 Interrupt */
    USI3_IRQn                       =   30,     /* USI3 Interrupt */
    I2S0_IRQn                       =   31,     /* I2S0 Interrupt */
    I2S1_IRQn                       =   32,     /* I2S1 Interrupt */
    I2S2_IRQn                       =   33,     /* I2S2 Interrupt */
    I2S3_IRQn                       =   34,     /* I2S3 Interrupt */
    SPDIF0_IRQn                     =   35,     /* spdif0 Interrupt */
    UART0_HS_IRQn                   =   36,     /* uart0 Interrupt */
    UART1_HS_IRQn                   =   37,     /* uart1 Interrupt */
    UART2_IRQn                      =   38,     /* uart2 Interrupt */
    UART3_IRQn                      =   39,     /* uart3 Interrupt */
    TDM_IRQn                        =   40,     /* tdm Interrupt */
    PDM_IRQn                        =   41,     /* pdm Interrupt */
    GPIO0_IRQn                      =   42,     /* gpio0 Interrupt */
    PLL_LL_IRQn                     =   43,     /* pll lose lock Interrupt */
    PLL_LL_FRAC_IRQn                =   44,     /* pll lose lock FRAC Interrupt */
    PWM0_IRQn                       =   45,     /* pwm0 Interrupt */
    RSA_IRQn                        =   46,     /* rsa Interrupt */
    SHA_IRQn                        =   47,     /* sha Interrupt */
    AES_IRQn                        =   48,     /* aes Interrupt */
    TRNG_IRQn                       =   49,     /* trng Interrupt */
    GPIO1_IRQn                      =   50,     /* gpio1 Interrupt */
    PWM1_IRQn                       =   51,     /* pwm1 Interrupt */
} IRQn_Type;

#define CONFIG_DMAC_NUM         1
#define CONFIG_DMA_CHANNEL_NUM  2
#define CONFIG_I2S_NUM          2
#define CONFIG_TIMER_NUM        4
#define CONFIG_USI_NUM          2
#define CONFIG_PWM_NUM          1
#define CONFIG_MAILBOX_NUM      3
#define CONFIG_MAILBOX_CHANNEL_NUM      2
#define CONFIG_GPIO_PIN_NUM     32
#define CONFIG_GPIO_NUM         1
#define CONFIG_USART_NUM        2

#endif

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of the CK805 Processor and Core Peripherals  ------- */
#define __CK805_REV               0x0000U   /* Core revision r0p0 */
#define __MGU_PRESENT             0         /* MGU present or not */
#define __NVIC_PRIO_BITS          2         /* Number of Bits used for Priority Levels */

#include "csi_core.h"                     /* Processor and core peripherals */
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CKENUM_DMA_UART0_RX,
    CKENUM_DMA_UART0_TX,
    CKENUM_DMA_UART1_RX,
    CKENUM_DMA_UART1_TX,
    CKENUM_DMA_IIS_TX,
    CKENUM_DMA_IIS_RX,
    CKENUM_DMA_ADC_RX,
    CKENUM_DMA_ADC_TX,
    CKENUM_DMA_SPI1_RX,
    CKENUM_DMA_SPI1_TX,
    CKENUM_DMA_SPI0_RX,
    CKENUM_DMA_SPI0_TX,
    CKENUM_DMA_IIC_RX,
    CKENUM_DMA_IIC_TX,
    CKENUM_DMA_IIC1_RX,
    CKENUM_DMA_IIC1_TX,
    CKENUM_DMA_MEMORY
} ckenum_dma_device_e;

typedef enum {
    ADDR_SPACE_ERROR      = -1,
    ADDR_SPACE_EFLASH     =  0,
    ADDR_SPACE_SRAM       =  1,
    ADDR_SPACE_PERIPHERAL =  2,
    ADDR_SPACE_TCIP       =  3
} addr_space_e;

//#define CONFIG_DW_DMAC

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#define CSKY_QSPIMEM_BASE               (0x08000000UL)
#define CSKY_CK804_TCM0_BASE            (0xFFE0000UL)
#define CSKY_CK804_TCM1_BASE            (0xFFE8000UL)
#define CSKY_CK804_TCM2_BASE            (0xFFF0000UL)
#define CSKY_CK804_TCM3_BASE            (0xFFF8000UL)
#define CSKY_CK804_TCM4_BASE            (0x10000000UL)
#define CSKY_CK804_TCM5_BASE            (0x10008000UL)
#define CSKY_CK804_TCM6_BASE            (0x10010000UL)
#define CSKY_CK804_TCM7_BASE            (0x10018000UL)
#define CSKY_CK804_TCM_SIZE             (0x8000UL)

#define CSKY_FMC_BASE                   (0x18000000UL)
#define CSKY_FMC_SIZE                   (0x800000UL)

/* AHB SUB0 */
#define CSKY_SDIO0_BASE                 (0x21000000UL)
#define CSKY_SDIO1_BASE                 (0x22000000UL)
#define CSKY_DMAC0_BASE                 (0x23000000UL)
/* AHB SUB1 */
#define CSKY_AES_BASE                   (0x28000000UL)
#define CSKY_SHA_BASE                   (0x29000000UL)
#define CSKY_FFT_BASE                   (0x2A000000UL)
/* AHB SUB2 */
#define CSKY_AONCPR_BASE                (0x30000000UL)
#define CSKY_CPR0_BASE                  (0x31000000UL)
#define CSKY_MCC0_BASE                  (0x32000000UL)
#define CSKY_RSA_BASE                   (0x33000000UL)
#define CSKY_TRNG_BASE                  (0x34000000UL)

/* CPU0 CK804 APB0 */
#define CSKY_WDT_BASE                   (0x38000000UL)
#define CSKY_RTC_BASE                   (0x38800000UL)
#define CSKY_TIM0_BASE                  (0x39000000UL)
#define CSKY_TIM1_BASE                  (0x39800000UL)
#define CSKY_EFUSE_BASE                 (0x3A000000UL)
#define CSKY_QSPIC0_BASE                (0x3A800000UL)
#define CSKY_PADREG_BASE                (0x3B000000UL)
#define CSKY_TIPC_BASE                  (0x3B800000UL)
#define CSKY_GPIO0_BASE                 (0x3C000000UL)
#define CSKY_PWM0_BASE                  (0x3C800000UL)
#define CSKY_I2S0_BASE                  (0x3D000000UL)
#define CSKY_I2S1_BASE                  (0x3D800000UL)
#define CSKY_USI0_BASE                  (0x3E000000UL)
#define CSKY_USI1_BASE                  (0x3E800000UL)
#define CSKY_UART0_BASE                 (0x3F000000UL)
#define CSKY_UART1_BASE                 (0x3F800000UL)

#define CSKY_CK805_TCM0_BASE            (0x80000000UL)
#define CSKY_CK805_TCM1_BASE            (0x80020000UL)
#define CSKY_CK805_TCM0_SIZE            (0x20000UL)
#define CSKY_CK805_TCM1_SIZE            (0x10000UL)
/* CK805 SUB0 */
#define CSKY_DMAC1_BASE                 (0x88000000UL)
#define CSKY_MCA_BASE                   (0x89000000UL)
#define CSKY_MCC1_BASE                  (0x8A000000UL)
#define CSKY_CPR1_BASE                  (0x8B000000UL)

/* CK805 APB1 */
#define CSKY_CODEC_BASE                 (0x90000000UL)
#define CSKY_TIM2_BASE                  (0x90800000UL)
#define CSKY_TIM3_BASE                  (0x91000000UL)
#define CSKY_SPDIF_BASE                 (0x91800000UL)
#define CSKY_PDM_BASE                   (0x92000000UL)
#define CSKY_TDM_BASE                   (0x92800000UL)
#define CSKY_GPIO1_BASE                 (0x93000000UL)
#define CSKY_PWM1_BASE                  (0x93800000UL)
#define CSKY_I2S2_BASE                  (0x94000000UL)
#define CSKY_I2S3_BASE                  (0x94800000UL)
#define CSKY_USI2_BASE                  (0x95000000UL)
#define CSKY_USI3_BASE                  (0x95800000UL)
#define CSKY_UART2_BASE                 (0x96000000UL)
#define CSKY_UART3_BASE                 (0x96800000UL)

#define SDMMC_BASE_ADDR                 CSKY_SDIO0_BASE
#define SHA_CONTEXT_SIZE                (224)
#define CONFIG_USI_V25
#define USI_USART_FUN_DIS               1
/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#ifdef __cplusplus
}
#endif

#endif  /* SOC_H_ */
