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

#ifndef __CSI_GCC_H
#define __CSI_GCC_H

/* ###########################  Core Function Access  ########################### */
/** \ingroup  CSI_Core_FunctionInterface
    \defgroup CSI_Core_RegAccFunctions CSI Core Register Access Functions
  @{
 */

/**
  \brief   Enable IRQ Interrupts
  \details Enables IRQ interrupts by setting the IE-bit in the PSR.
           Can only be executed in Privileged modes.
 */
__ALWAYS_INLINE void __enable_irq(void)
{
  __ASM volatile ("psrset ie");
}



/**
  \brief   Disable IRQ Interrupts
  \details Disables IRQ interrupts by clearing the IE-bit in the PSR.
  Can only be executed in Privileged modes.
 */
__ALWAYS_INLINE void __disable_irq(void)
{
  __ASM volatile ("psrclr ie");
}

/**
  \brief   Get PSR
  \details Returns the content of the PSR Register.
  \return               PSR Register value
 */
__ALWAYS_INLINE uint32_t __get_PSR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, psr" : "=r" (result) );
  return(result);
}

/**
  \brief   Set PSR
  \details Writes the given value to the PSR Register.
  \param [in]    psr  PSR Register value to set
 */
__ALWAYS_INLINE void __set_PSR(uint32_t psr)
{
  __ASM volatile ("mtcr %0, psr" : : "r" (psr) );
}

/**
  \brief   Get SP
  \details Returns the content of the SP Register.
  \return               SP Register value
 */
__ALWAYS_INLINE uint32_t __get_SP(void)
{
  uint32_t result;

  __ASM volatile ("mov %0, sp" : "=r" (result) );
  return(result);
}

/**
  \brief   Set SP
  \details Writes the given value to the SP Register.
  \param [in]    sp  SP Register value to set
 */
__ALWAYS_INLINE void __set_SP(uint32_t sp)
{
  __ASM volatile ("mov sp, %0" : : "r" (sp):"sp");
}


/**
  \brief   Get VBR Register
  \details Returns the content of the VBR Register.
  \return               VBR Register value
 */
__ALWAYS_INLINE uint32_t __get_VBR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, vbr" : "=r" (result) );
  return(result);
}

/**
  \brief   Set VBR
  \details Writes the given value to the VBR Register.
  \param [in]    vbr  VBR Register value to set
 */
__ALWAYS_INLINE void __set_VBR(uint32_t vbr)
{
  __ASM volatile ("mtcr %0, vbr" : : "r" (vbr) );
}

/**
  \brief   Get EPC Register
  \details Returns the content of the EPC Register.
  \return               EPC Register value
 */
__ALWAYS_INLINE uint32_t __get_EPC(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, epc" : "=r" (result) );
  return(result);
}

/**
  \brief   Set EPC
  \details Writes the given value to the EPC Register.
  \param [in]    epc  EPC Register value to set
 */
__ALWAYS_INLINE void __set_EPC(uint32_t epc)
{
  __ASM volatile ("mtcr %0, epc" : : "r" (epc) );
}

/**
  \brief   Get EPSR
  \details Returns the content of the EPSR Register.
  \return               EPSR Register value
 */
__ALWAYS_INLINE uint32_t __get_EPSR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, epsr" : "=r" (result) );
  return(result);
}

/**
  \brief   Set EPSR
  \details Writes the given value to the EPSR Register.
  \param [in]    epsr  EPSR Register value to set
 */
__ALWAYS_INLINE void __set_EPSR(uint32_t epsr)
{
  __ASM volatile ("mtcr %0, epsr" : : "r" (epsr) );
}

/**
  \brief   Get CPUID Register
  \details Returns the content of the CPUID Register.
  \return               CPUID Register value
 */
__ALWAYS_INLINE uint32_t __get_CPUID(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<13, 0>" : "=r" (result) );
  return(result);
}

#if       (__SOFTRESET_PRESENT == 1U)
/**
  \brief   Set SRCR
  \details Assigns the given value to the SRCR.
  \param [in]    srcr  SRCR value to set
 */
__ALWAYS_INLINE void __set_SRCR(uint32_t srcr)
{
  __ASM volatile ("mtcr %0, cr<31, 0>\n" : : "r" (srcr) );
}
#endif /* __SOFTRESET_PRESENT == 1U */

#if       (__MGU_PRESENT == 1U)
/**
  \brief   Get CCR
  \details Returns the current value of the CCR.
  \return               CCR Register value
 */
__ALWAYS_INLINE uint32_t __get_CCR(void)
{
  register uint32_t result;

  __ASM volatile ("mfcr %0, cr<18, 0>\n"  : "=r" (result) );
  return(result);
}


/**
  \brief   Set CCR
  \details Assigns the given value to the CCR.
  \param [in]    ccr  CCR value to set
 */
__ALWAYS_INLINE void __set_CCR(uint32_t ccr)
{
  __ASM volatile ("mtcr %0, cr<18, 0>\n" : : "r" (ccr) );
}


/**
  \brief   Get CAPR
  \details Returns the current value of the CAPR.
  \return               CAPR Register value
 */
__ALWAYS_INLINE uint32_t __get_CAPR(void)
{
  register uint32_t result;

  __ASM volatile ("mfcr %0, cr<19, 0>\n" : "=r" (result) );
  return(result);
}

/**
  \brief   Set CAPR
  \details Assigns the given value to the CAPR.
  \param [in]    capr  CAPR value to set
 */
__ALWAYS_INLINE void __set_CAPR(uint32_t capr)
{
  __ASM volatile ("mtcr %0, cr<19, 0>\n" : : "r" (capr) );
}


/**
  \brief   Set PACR
  \details Assigns the given value to the PACR.

    \param [in]    pacr  PACR value to set
 */
__ALWAYS_INLINE void __set_PACR(uint32_t pacr)
{
  __ASM volatile ("mtcr %0, cr<20, 0>\n" : : "r" (pacr) );
}


/**
  \brief   Get PACR
  \details Returns the current value of PACR.
  \return               PACR value
 */
__ALWAYS_INLINE uint32_t __get_PACR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<20, 0>" : "=r" (result) );
  return(result);
}

/**
  \brief   Set PRSR
  \details Assigns the given value to the PRSR.

    \param [in]    prsr  PRSR value to set
 */
__ALWAYS_INLINE void __set_PRSR(uint32_t prsr)
{
  __ASM volatile ("mtcr %0, cr<21, 0>\n" : : "r" (prsr) );
}

/**
  \brief   Get PRSR
  \details Returns the current value of PRSR.
  \return               PRSR value
 */
__ALWAYS_INLINE uint32_t __get_PRSR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<21, 0>" : "=r" (result) );
  return(result);
}
#endif /* __MGU_PRESENT == 1U */

/**
  \brief   Get user sp
  \details Returns the current value of user r14.
  \return               UR14 value
 */
__ALWAYS_INLINE uint32_t __get_UR14(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<14, 1>" : "=r" (result) );
  return(result);
}

/**
  \brief   Enable interrupts and exceptions
  \details Enables interrupts and exceptions by setting the IE-bit and EE-bit in the PSR.
           Can only be executed in Privileged modes.
 */
__ALWAYS_INLINE void __enable_excp_irq(void)
{
  __ASM volatile ("psrset ee, ie");
}


/**
  \brief   Disable interrupts and exceptions
  \details Disables interrupts and exceptions by clearing the IE-bit and EE-bit in the PSR.
           Can only be executed in Privileged modes.
 */
__ALWAYS_INLINE void __disable_excp_irq(void)
{
  __ASM volatile ("psrclr ee, ie");
}

#if       (__GSR_GCR_PRESENT == 1U)
/**
  \brief   Get GSR
  \details Returns the content of the GSR Register.
  \return               GSR Register value
 */
__ALWAYS_INLINE uint32_t __get_GSR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<12, 0>" : "=r" (result) );
  return(result);
}

/**
  \brief   Get GCR
  \details Returns the content of the GCR Register.
  \return               GCR Register value
 */
__ALWAYS_INLINE uint32_t __get_GCR(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<11, 0>" : "=r" (result) );
  return(result);
}

/**
  \brief   Set GCR
  \details Writes the given value to the GCR Register.
  \param [in]    gcr  GCR Register value to set
 */
__ALWAYS_INLINE void __set_GCR(uint32_t gcr)
{
  __ASM volatile ("mtcr %0, cr<11, 0>" : : "r" (gcr) );
}

#endif /* (__GSR_GCR_PRESENT == 1U) */

/*@} end of CSI_Core_RegAccFunctions */


/* ##########################  Core Instruction Access  ######################### */
/** \defgroup CSI_Core_InstructionInterface CSI Core Instruction Interface
  Access to dedicated instructions
  @{
*/

#define __CSI_GCC_OUT_REG(r) "=r" (r)
#define __CSI_GCC_USE_REG(r) "r" (r)

/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
__ALWAYS_INLINE void __NOP(void)
{
  __ASM volatile ("nop");
}


/**
  \brief   Wait For Interrupt
  \details Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
 */
__ALWAYS_INLINE void __WFI(void)
{
  __ASM volatile ("wait");
}

/**
  \brief   Wait For Interrupt
  \details Wait For Interrupt is a hint instruction that suspends execution until one interrupt occurs.
 */
__ALWAYS_INLINE void __WAIT(void)
{
  __ASM volatile ("wait");
}

/**
  \brief   Doze For Interrupt
  \details Doze For Interrupt is a hint instruction that suspends execution until one interrupt occurs.
 */
__ALWAYS_INLINE void __DOZE(void)
{
  __ASM volatile ("doze");
}

/**
  \brief   Stop For Interrupt
  \details Stop For Interrupt is a hint instruction that suspends execution until one interrupt occurs.
 */
__ALWAYS_INLINE void __STOP(void)
{
  __ASM volatile ("stop");
}

/**
  \brief   Instruction Synchronization Barrier
  \details Instruction Synchronization Barrier flushes the pipeline in the processor,
           so that all instructions following the ISB are fetched from cache or memory,
           after the instruction has been completed.
 */
__ALWAYS_INLINE void __ISB(void)
{
  __ASM volatile ("sync":::"memory");
}


/**
  \brief   Data Synchronization Barrier
  \details Acts as a special kind of Data Memory Barrier.
           It completes when all explicit memory accesses before this instruction complete.
 */
__ALWAYS_INLINE void __DSB(void)
{
  __ASM volatile ("sync":::"memory");
}


/**
  \brief   Data Memory Barrier
  \details Ensures the apparent order of the explicit memory operations before
           and after the instruction, without ensuring their completion.
 */
__ALWAYS_INLINE void __DMB(void)
{
  __ASM volatile ("sync":::"memory");
}


/**
  \brief   Reverse byte order (32 bit)
  \details Reverses the byte order in integer value.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
__ALWAYS_INLINE uint32_t __REV(uint32_t value)
{
  return __builtin_bswap32(value);
}


/**
  \brief   Reverse byte order (16 bit)
  \details Reverses the byte order in two unsigned short values.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
__ALWAYS_INLINE uint32_t __REV16(uint32_t value)
{
  uint32_t result;
#if (__CK80X >= 2)
  __ASM volatile ("revh %0, %1" : __CSI_GCC_OUT_REG (result) : __CSI_GCC_USE_REG (value) );
#else
  result = ((value & 0xFF000000) >> 8) | ((value & 0x00FF0000) << 8) |
           ((value & 0x0000FF00) >> 8) | ((value & 0x000000FF) << 8);
#endif
  return(result);
}


/**
  \brief   Reverse byte order in signed short value
  \details Reverses the byte order in a signed short value with sign extension to integer.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
__ALWAYS_INLINE int32_t __REVSH(int32_t value)
{
  return (short)(((value & 0xFF00) >> 8) | ((value & 0x00FF) << 8));
}


/**
  \brief   Rotate Right in unsigned value (32 bit)
  \details Rotate Right (immediate) provides the value of the contents of a register rotated by a variable number of bits.
  \param [in]    value  Value to rotate
  \param [in]    value  Number of Bits to rotate
  \return               Rotated value
 */
__ALWAYS_INLINE uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  return (op1 >> op2) | (op1 << (32U - op2));
}


/**
  \brief   Breakpoint
  \details Causes the processor to enter Debug state.
           Debug tools can use this to investigate system state when the instruction at a particular address is reached.
  \param [in]    value  is ignored by the processor.
                 If required, a debugger can use it to store additional information about the breakpoint.
 */
__ALWAYS_INLINE void __BKPT()
{
  __ASM volatile ("bkpt");
}

/**
  \brief   Reverse bit order of value
  \details Reverses the bit order of the given value.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
__ALWAYS_INLINE uint32_t __RBIT(uint32_t value)
{
  uint32_t result;

#if       (__CK80X >= 0x03U)
   __ASM volatile ("brev %0, %1" : "=r" (result) : "r" (value) );
#else
  int32_t s = 4 /*sizeof(v)*/ * 8 - 1; /* extra shift needed at end */

  result = value;                      /* r will be reversed bits of v; first get LSB of v */
  for (value >>= 1U; value; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;                        /* shift when v's highest bits are zero */
#endif
  return(result);
}


/**
  \brief   Count leading zeros
  \details Counts the number of leading zeros of a data value.
  \param [in]  value  Value to count the leading zeros
  \return             number of leading zeros in value
 */
#define __CLZ             __builtin_clz
/**
  \details This function saturates a signed value.
  \param [in]    x   Value to be saturated
  \param [in]    y   Bit position to saturate to [1..32]
  \return            Saturated value.
 */
__ALWAYS_INLINE int32_t __SSAT(int32_t x, uint32_t y)
{
  int32_t posMax, negMin;
  uint32_t i;

//  posMax = 1;
//  for (i = 0; i < (y - 1); i++)
//  {
//    posMax = posMax * 2;
//  }

  posMax = 1 << (y - 1);

  if(x > 0)
  {
    posMax = (posMax - 1);

    if(x > posMax)
    {
      x = posMax;
    }
  }
  else
  {
    negMin = -posMax;

    if(x < negMin)
    {
      x = negMin;
    }
  }
  return (x);
}

__ALWAYS_INLINE int32_t __SSAT_31(int32_t x)
{
    int32_t res = x;
    if (x > 0x3fffffff) {
       res = 0x3fffffff;
    } else if (x < -1073741824) {
       res = -1073741824;
    }

    return res;
}

__ALWAYS_INLINE int32_t __SSAT_16(int32_t x)
{
#if 0
    int32_t res = 0x7fff;
    __ASM volatile ("cmplti   %1, 0x8000\n\t"
                    "bf       1f\n\t"
                    "nor      %0, %0\n\t"
                    "cmplt    %1, %0\n\t"
                    "movf     %0, %1\n\t"
                    "1:\n\t"
                    : "=r" (res), "=r" (x): "0" (res), "1" (x));
#else
    int32_t res = x;
    if (x > 0x7fff) {
       res = 0x7fff;
    } else if (x < -32768) {
       res = -32768;
    }
#endif
    return res;
}

__ALWAYS_INLINE int32_t __SSAT_8(int32_t x)
{
    int32_t res = x;
    if (x > 0x7f) {
       res = 0x7f;
    } else if (x < -128) {
       res = -128;
    }

    return res;
}

/**
  \brief   Unsigned Saturate
  \details Saturates an unsigned value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (0..31)
  \return             Saturated value
 */
__ALWAYS_INLINE uint32_t __USAT(uint32_t value, uint32_t sat)
{
  uint32_t result;

  if ((((0xFFFFFFFF >> sat) << sat) & value) != 0) {
    result = 0xFFFFFFFF >> (32 - sat);
  } else {
    result = value;
  }

  return (result);
}

/**
  \brief   Unsigned Saturate for internal use
  \details Saturates an unsigned value, should not call directly.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (0..31)
  \return             Saturated value
 */
__ALWAYS_INLINE uint32_t __IUSAT(uint32_t value, uint32_t sat)
{
  uint32_t result;

  if (value & 0x80000000) { /* only overflow set bit-31 */
    result = 0;
  } else if ((((0xFFFFFFFF >> sat) << sat) & value) != 0) {
    result = 0xFFFFFFFF >> (32 - sat);
  } else {
    result = value;
  }

  return (result);
}

#if (__CMSIS_COMPATIBLE == 1)
/**
  \brief   Rotate Right with Extend
  \details This function moves each bit of a bitstring right by one bit.
           The carry input is shifted in at the left end of the bitstring.
  \note    carry input will always 0.
  \param [in]    value  Value to rotate
  \return               Rotated value
 */
__ALWAYS_INLINE uint32_t __RRX(uint32_t op1)
{
  return (op1 >> 1);
}

/**
  \brief   LDRT Unprivileged (8 bit)
  \details Executes a Unprivileged LDRT instruction for 8 bit value.
  \param [in]    ptr  Pointer to data
  \return             value of type uint8_t at (*ptr)
 */
__ALWAYS_INLINE uint8_t __LDRBT(volatile uint8_t *addr)
{
    uint32_t result;
//#warning "__LDRBT"
   __ASM volatile ("ldb %0, (%1, 0)" : "=r" (result) : "r" (addr));
   return ((uint8_t) result);    /* Add explicit type cast here */
}


/**
  \brief   LDRT Unprivileged (16 bit)
  \details Executes a Unprivileged LDRT instruction for 16 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint16_t at (*ptr)
 */
__ALWAYS_INLINE uint16_t __LDRHT(volatile uint16_t *addr)
{
    uint32_t result;

//#warning "__LDRHT"
   __ASM volatile ("ldh %0, (%1, 0)" : "=r" (result) : "r" (addr) );
   return ((uint16_t) result);    /* Add explicit type cast here */
}


/**
  \brief   LDRT Unprivileged (32 bit)
  \details Executes a Unprivileged LDRT instruction for 32 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint32_t at (*ptr)
 */
__ALWAYS_INLINE uint32_t __LDRT(volatile uint32_t *addr)
{
    uint32_t result;

//#warning "__LDRT"
   __ASM volatile ("ldw %0, (%1, 0)" : "=r" (result) : "r" (addr) );
   return(result);
}


/**
  \brief   STRT Unprivileged (8 bit)
  \details Executes a Unprivileged STRT instruction for 8 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
__ALWAYS_INLINE void __STRBT(uint8_t value, volatile uint8_t *addr)
{
//#warning "__STRBT"
   __ASM volatile ("stb %1, (%0, 0)" :: "r" (addr), "r" ((uint32_t)value) : "memory");
}


/**
  \brief   STRT Unprivileged (16 bit)
  \details Executes a Unprivileged STRT instruction for 16 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
__ALWAYS_INLINE void __STRHT(uint16_t value, volatile uint16_t *addr)
{
//#warning "__STRHT"
   __ASM volatile ("sth %1, (%0, 0)" :: "r" (addr), "r" ((uint32_t)value) : "memory");
}


/**
  \brief   STRT Unprivileged (32 bit)
  \details Executes a Unprivileged STRT instruction for 32 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
__ALWAYS_INLINE void __STRT(uint32_t value, volatile uint32_t *addr)
{
//#warning "__STRT"
   __ASM volatile ("stw %1, (%0, 0)" :: "r" (addr), "r" (value) : "memory");
}
#endif /* __CMSIS_COMPATIBLE == 1 */

/*@}*/ /* end of group CSI_Core_InstructionInterface */

/* ##########################  FPU functions  #################################### */
/**
  \ingroup  CSI_Core_FunctionInterface
  \defgroup CSI_Core_FpuFunctions FPU Functions
  \brief    Function that provides FPU type.
  @{
 */

/**
  \brief   get FPU type
  \details returns the FPU type, always 0.
  \returns
   - \b  0: No FPU
   - \b  1: Single precision FPU
   - \b  2: Double + Single precision FPU
 */
__STATIC_INLINE uint32_t SCB_GetFPUType(void)
{
  uint32_t result;

  __ASM volatile ("mfcr %0, cr<13, 0>" : "=r" (result) );
  return 0;
}


/*@} end of CSI_Core_FpuFunctions */


/* ###################  Compiler specific Intrinsics  ########################### */
/** \defgroup CSI_SIMD_intrinsics CSI SIMD Intrinsics
  Access to dedicated SIMD instructions \n
  Single Instruction Multiple Data (SIMD) extensions are provided to simplify development of application software. SIMD extensions increase the processing capability without materially increasing the power consumption. The SIMD extensions are completely transparent to the operating system (OS), allowing existing OS ports to be used.

  @{
*/

/**
  \brief   Halfword packing instruction. Combines bits[15:0] of val1 with bits[31:16]
           of val2 levitated with the val3.
  \details Combine a halfword from one register with a halfword from another register.
           The second argument can be left-shifted before extraction of the halfword.
  \param [in]    val1   first 16-bit operands
  \param [in]    val2   second 16-bit operands
  \param [in]    val3   value for left-shifting val2. Value range [0..31].
  \return               the combination of halfwords.
  \remark
                 res[15:0]  = val1[15:0]              \n
                 res[31:16] = val2[31:16] << val3
 */
__ALWAYS_INLINE uint32_t __PKHBT(uint32_t val1, uint32_t val2, uint32_t val3)
{
#ifdef CSKY_SIMD
  uint32_t res;
  if (val3 == 16) {
    __ASM volatile ("pkgll %0, %1, %2" :"=r" (res), "=r" (val1), "=r" (val2): "0" (res), "1" (val1), "2" (val2));
  } else if (val3 == 0){
    __ASM volatile ("pkg %0, %1, 0, %2, 16" :"=r" (res), "=r" (val1), "=r" (val2): "0" (res), "1" (val1), "2" (val2));
  } else {
    return ((((int32_t)(val1) << 0) & (int32_t)0x0000FFFF) | (((int32_t)(val2) << val3) & (int32_t)0xFFFF0000));
  }
  return res;
#else
  return ((((int32_t)(val1) << 0) & (int32_t)0x0000FFFF) | (((int32_t)(val2) << val3) & (int32_t)0xFFFF0000));
#endif
}

/**
  \brief   Halfword packing instruction. Combines bits[31:16] of val1 with bits[15:0]
           of val2 right-shifted with the val3.
  \details Combine a halfword from one register with a halfword from another register.
           The second argument can be right-shifted before extraction of the halfword.
  \param [in]    val1   first 16-bit operands
  \param [in]    val2   second 16-bit operands
  \param [in]    val3   value for right-shifting val2. Value range [1..32].
  \return               the combination of halfwords.
  \remark
                 res[15:0]  = val2[15:0] >> val3        \n
                 res[31:16] = val1[31:16]
 */
__ALWAYS_INLINE uint32_t __PKHTB(uint32_t val1, uint32_t val2, uint32_t val3)
{
  return ((((int32_t)(val1) << 0) & (int32_t)0xFFFF0000) | (((int32_t)(val2) >> val3) & (int32_t)0x0000FFFF));
}

/**
  \brief   Dual 16-bit signed saturate.
  \details This function saturates a signed value.
  \param [in]    x   two signed 16-bit values to be saturated.
  \param [in]    y   bit position for saturation, an integral constant expression in the range 1 to 16.
  \return        the sum of the absolute differences of the following bytes, added to the accumulation value:\n
                 the signed saturation of the low halfword in val1, saturated to the bit position specified in
                 val2 and returned in the low halfword of the return value.\n
                 the signed saturation of the high halfword in val1, saturated to the bit position specified in
                 val2 and returned in the high halfword of the return value.
 */
__ALWAYS_INLINE uint32_t __SSAT16(int32_t x, const uint32_t y)
{
  int32_t r = 0, s = 0;

  r = __SSAT((((int32_t)x << 16) >> 16), y) & (int32_t)0x0000FFFF;
  s = __SSAT((((int32_t)x      ) >> 16), y) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
}

/**
  \brief   Dual 16-bit unsigned saturate.
  \details This function enables you to saturate two signed 16-bit values to a selected unsigned range.
  \param [in]    x   two signed 16-bit values to be saturated.
  \param [in]    y   bit position for saturation, an integral constant expression in the range 1 to 16.
  \return        the saturation of the two signed 16-bit values, as non-negative values:
                 the saturation of the low halfword in val1, saturated to the bit position specified in
                 val2 and returned in the low halfword of the return value.\n
                 the saturation of the high halfword in val1, saturated to the bit position specified in
                 val2 and returned in the high halfword of the return value.
 */
__ALWAYS_INLINE uint32_t __USAT16(int32_t x, const uint32_t y)
{
  int32_t r = 0, s = 0;

  r = __IUSAT(((x << 16) >> 16), y) & 0x0000FFFF;
  s = __IUSAT(((x      ) >> 16), y) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Quad 8-bit saturating addition.
  \details This function enables you to perform four 8-bit integer additions,
           saturating the results to the 8-bit signed integer range -2^7 <= x <= 2^7 - 1.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the saturated addition of the first byte of each operand in the first byte of the return value.\n
                 the saturated addition of the second byte of each operand in the second byte of the return value.\n
                 the saturated addition of the third byte of each operand in the third byte of the return value.\n
                 the saturated addition of the fourth byte of each operand in the fourth byte of the return value.\n
                 The returned results are saturated to the 8-bit signed integer range -2^7 <= x <= 2^7 - 1.
  \remark
                 res[7:0]   = val1[7:0]   + val2[7:0]        \n
                 res[15:8]  = val1[15:8]  + val2[15:8]       \n
                 res[23:16] = val1[23:16] + val2[23:16]      \n
                 res[31:24] = val1[31:24] + val2[31:24]
 */
__ALWAYS_INLINE uint32_t __QADD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = __SSAT_8(((((int32_t)x << 24) >> 24) + (((int32_t)y << 24) >> 24))) & (int32_t)0x000000FF;
  s = __SSAT_8(((((int32_t)x << 16) >> 24) + (((int32_t)y << 16) >> 24))) & (int32_t)0x000000FF;
  t = __SSAT_8(((((int32_t)x <<  8) >> 24) + (((int32_t)y <<  8) >> 24))) & (int32_t)0x000000FF;
  u = __SSAT_8(((((int32_t)x      ) >> 24) + (((int32_t)y      ) >> 24))) & (int32_t)0x000000FF;

  return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
}

/**
  \brief   Quad 8-bit unsigned saturating addition.
  \details This function enables you to perform four unsigned 8-bit integer additions,
           saturating the results to the 8-bit unsigned integer range 0 < x < 2^8 - 1.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the saturated addition of the first byte of each operand in the first byte of the return value.\n
                 the saturated addition of the second byte of each operand in the second byte of the return value.\n
                 the saturated addition of the third byte of each operand in the third byte of the return value.\n
                 the saturated addition of the fourth byte of each operand in the fourth byte of the return value.\n
                 The returned results are saturated to the 8-bit signed integer range 0 <= x <= 2^8 - 1.
  \remark
                 res[7:0]   = val1[7:0]   + val2[7:0]        \n
                 res[15:8]  = val1[15:8]  + val2[15:8]       \n
                 res[23:16] = val1[23:16] + val2[23:16]      \n
                 res[31:24] = val1[31:24] + val2[31:24]
 */
__ALWAYS_INLINE uint32_t __UQADD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = __IUSAT((((x << 24) >> 24) + ((y << 24) >> 24)), 8) & 0x000000FF;
  s = __IUSAT((((x << 16) >> 24) + ((y << 16) >> 24)), 8) & 0x000000FF;
  t = __IUSAT((((x <<  8) >> 24) + ((y <<  8) >> 24)), 8) & 0x000000FF;
  u = __IUSAT((((x      ) >> 24) + ((y      ) >> 24)), 8) & 0x000000FF;

  return ((u << 24) | (t << 16) | (s <<  8) | (r      ));
}

/**
  \brief   Quad 8-bit signed addition.
  \details This function performs four 8-bit signed integer additions.
  \param [in]    x  first four 8-bit summands.
  \param [in]    y  second four 8-bit summands.
  \return        the addition of the first bytes from each operand, in the first byte of the return value.\n
                 the addition of the second bytes of each operand, in the second byte of the return value.\n
                 the addition of the third bytes of each operand, in the third byte of the return value.\n
                 the addition of the fourth bytes of each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = val1[7:0]   + val2[7:0]        \n
                 res[15:8]  = val1[15:8]  + val2[15:8]       \n
                 res[23:16] = val1[23:16] + val2[23:16]      \n
                 res[31:24] = val1[31:24] + val2[31:24]
 */
__ALWAYS_INLINE uint32_t __SADD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = ((((int32_t)x << 24) >> 24) + (((int32_t)y << 24) >> 24)) & (int32_t)0x000000FF;
  s = ((((int32_t)x << 16) >> 24) + (((int32_t)y << 16) >> 24)) & (int32_t)0x000000FF;
  t = ((((int32_t)x <<  8) >> 24) + (((int32_t)y <<  8) >> 24)) & (int32_t)0x000000FF;
  u = ((((int32_t)x      ) >> 24) + (((int32_t)y      ) >> 24)) & (int32_t)0x000000FF;

  return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
}

/**
  \brief   Quad 8-bit unsigned addition.
  \details This function performs four unsigned 8-bit integer additions.
  \param [in]    x  first four 8-bit summands.
  \param [in]    y  second four 8-bit summands.
  \return        the addition of the first bytes from each operand, in the first byte of the return value.\n
                 the addition of the second bytes of each operand, in the second byte of the return value.\n
                 the addition of the third bytes of each operand, in the third byte of the return value.\n
                 the addition of the fourth bytes of each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = val1[7:0]   + val2[7:0]        \n
                 res[15:8]  = val1[15:8]  + val2[15:8]       \n
                 res[23:16] = val1[23:16] + val2[23:16]      \n
                 res[31:24] = val1[31:24] + val2[31:24]
 */
__ALWAYS_INLINE uint32_t __UADD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = (((x << 24) >> 24) + ((y << 24) >> 24)) & 0x000000FF;
  s = (((x << 16) >> 24) + ((y << 16) >> 24)) & 0x000000FF;
  t = (((x <<  8) >> 24) + ((y <<  8) >> 24)) & 0x000000FF;
  u = (((x      ) >> 24) + ((y      ) >> 24)) & 0x000000FF;

  return ((u << 24) | (t << 16) | (s <<  8) | (r      ));
}

/**
  \brief   Quad 8-bit saturating subtract.
  \details This function enables you to perform four 8-bit integer subtractions,
           saturating the results to the 8-bit signed integer range -2^7 <= x <= 2^7 - 1.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the subtraction of the first byte of each operand in the first byte of the return value.\n
                 the subtraction of the second byte of each operand in the second byte of the return value.\n
                 the subtraction of the third byte of each operand in the third byte of the return value.\n
                 the subtraction of the fourth byte of each operand in the fourth byte of the return value.\n
                 The returned results are saturated to the 8-bit signed integer range -2^7 <= x <= 2^7 - 1.
  \remark
                 res[7:0]   = val1[7:0]   - val2[7:0]        \n
                 res[15:8]  = val1[15:8]  - val2[15:8]       \n
                 res[23:16] = val1[23:16] - val2[23:16]      \n
                 res[31:24] = val1[31:24] - val2[31:24]
 */
__ALWAYS_INLINE uint32_t __QSUB8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = __SSAT_8(((((int32_t)x << 24) >> 24) - (((int32_t)y << 24) >> 24))) & (int32_t)0x000000FF;
  s = __SSAT_8(((((int32_t)x << 16) >> 24) - (((int32_t)y << 16) >> 24))) & (int32_t)0x000000FF;
  t = __SSAT_8(((((int32_t)x <<  8) >> 24) - (((int32_t)y <<  8) >> 24))) & (int32_t)0x000000FF;
  u = __SSAT_8(((((int32_t)x      ) >> 24) - (((int32_t)y      ) >> 24))) & (int32_t)0x000000FF;

  return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
}

/**
  \brief   Quad 8-bit unsigned saturating subtraction.
  \details This function enables you to perform four unsigned 8-bit integer subtractions,
           saturating the results to the 8-bit unsigned integer range 0 < x < 2^8 - 1.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the subtraction of the first byte of each operand in the first byte of the return value.\n
                 the subtraction of the second byte of each operand in the second byte of the return value.\n
                 the subtraction of the third byte of each operand in the third byte of the return value.\n
                 the subtraction of the fourth byte of each operand in the fourth byte of the return value.\n
                 The returned results are saturated to the 8-bit unsigned integer range 0 <= x <= 2^8 - 1.
  \remark
                 res[7:0]   = val1[7:0]   - val2[7:0]        \n
                 res[15:8]  = val1[15:8]  - val2[15:8]       \n
                 res[23:16] = val1[23:16] - val2[23:16]      \n
                 res[31:24] = val1[31:24] - val2[31:24]
 */
__ALWAYS_INLINE uint32_t __UQSUB8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = __IUSAT((((x << 24) >> 24) - ((y << 24) >> 24)), 8) & 0x000000FF;
  s = __IUSAT((((x << 16) >> 24) - ((y << 16) >> 24)), 8) & 0x000000FF;
  t = __IUSAT((((x <<  8) >> 24) - ((y <<  8) >> 24)), 8) & 0x000000FF;
  u = __IUSAT((((x      ) >> 24) - ((y      ) >> 24)), 8) & 0x000000FF;

  return ((u << 24) | (t << 16) | (s <<  8) | (r      ));
}

/**
  \brief   Quad 8-bit signed subtraction.
  \details This function enables you to perform four 8-bit signed integer subtractions.
  \param [in]    x  first four 8-bit operands of each subtraction.
  \param [in]    y  second four 8-bit operands of each subtraction.
  \return        the subtraction of the first bytes from each operand, in the first byte of the return value.\n
                 the subtraction of the second bytes of each operand, in the second byte of the return value.\n
                 the subtraction of the third bytes of each operand, in the third byte of the return value.\n
                 the subtraction of the fourth bytes of each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = val1[7:0]   - val2[7:0]        \n
                 res[15:8]  = val1[15:8]  - val2[15:8]       \n
                 res[23:16] = val1[23:16] - val2[23:16]      \n
                 res[31:24] = val1[31:24] - val2[31:24]
 */
__ALWAYS_INLINE uint32_t __SSUB8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = ((((int32_t)x << 24) >> 24) - (((int32_t)y << 24) >> 24)) & (int32_t)0x000000FF;
  s = ((((int32_t)x << 16) >> 24) - (((int32_t)y << 16) >> 24)) & (int32_t)0x000000FF;
  t = ((((int32_t)x <<  8) >> 24) - (((int32_t)y <<  8) >> 24)) & (int32_t)0x000000FF;
  u = ((((int32_t)x      ) >> 24) - (((int32_t)y      ) >> 24)) & (int32_t)0x000000FF;

  return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
}

/**
  \brief   Quad 8-bit unsigned subtract.
  \details This function enables you to perform four 8-bit unsigned integer subtractions.
  \param [in]    x  first four 8-bit operands of each subtraction.
  \param [in]    y  second four 8-bit operands of each subtraction.
  \return        the subtraction of the first bytes from each operand, in the first byte of the return value.\n
                 the subtraction of the second bytes of each operand, in the second byte of the return value.\n
                 the subtraction of the third bytes of each operand, in the third byte of the return value.\n
                 the subtraction of the fourth bytes of each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = val1[7:0]   - val2[7:0]        \n
                 res[15:8]  = val1[15:8]  - val2[15:8]       \n
                 res[23:16] = val1[23:16] - val2[23:16]      \n
                 res[31:24] = val1[31:24] - val2[31:24]
 */
__ALWAYS_INLINE uint32_t __USUB8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = (((x << 24) >> 24) - ((y << 24) >> 24)) & 0x000000FF;
  s = (((x << 16) >> 24) - ((y << 16) >> 24)) & 0x000000FF;
  t = (((x <<  8) >> 24) - ((y <<  8) >> 24)) & 0x000000FF;
  u = (((x      ) >> 24) - ((y      ) >> 24)) & 0x000000FF;

  return ((u << 24) | (t << 16) | (s <<  8) | (r      ));
}

/**
  \brief   Unsigned sum of quad 8-bit unsigned absolute difference.
  \details This function enables you to perform four unsigned 8-bit subtractions, and add the absolute values
           of the differences together, returning the result as a single unsigned integer.
  \param [in]    x  first four 8-bit operands of each subtraction.
  \param [in]    y  second four 8-bit operands of each subtraction.
  \return        the subtraction of the first bytes from each operand, in the first byte of the return value.\n
                 the subtraction of the second bytes of each operand, in the second byte of the return value.\n
                 the subtraction of the third bytes of each operand, in the third byte of the return value.\n
                 the subtraction of the fourth bytes of each operand, in the fourth byte of the return value.\n
                 The sum is returned as a single unsigned integer.
  \remark
                 absdiff1   = val1[7:0]   - val2[7:0]        \n
                 absdiff2   = val1[15:8]  - val2[15:8]       \n
                 absdiff3   = val1[23:16] - val2[23:16]      \n
                 absdiff4   = val1[31:24] - val2[31:24]      \n
                 res[31:0]  = absdiff1 + absdiff2 + absdiff3 + absdiff4
 */
__ALWAYS_INLINE uint32_t __USAD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = (((x << 24) >> 24) - ((y << 24) >> 24)) & 0x000000FF;
  s = (((x << 16) >> 24) - ((y << 16) >> 24)) & 0x000000FF;
  t = (((x <<  8) >> 24) - ((y <<  8) >> 24)) & 0x000000FF;
  u = (((x      ) >> 24) - ((y      ) >> 24)) & 0x000000FF;

  return (u + t + s + r);
}

/**
  \brief   Unsigned sum of quad 8-bit unsigned absolute difference with 32-bit accumulate.
  \details This function enables you to perform four unsigned 8-bit subtractions, and add the absolute values
           of the differences to a 32-bit accumulate operand.
  \param [in]    x  first four 8-bit operands of each subtraction.
  \param [in]    y  second four 8-bit operands of each subtraction.
  \param [in]  sum  accumulation value.
  \return        the sum of the absolute differences of the following bytes, added to the accumulation value:
                 the subtraction of the first bytes from each operand, in the first byte of the return value.\n
                 the subtraction of the second bytes of each operand, in the second byte of the return value.\n
                 the subtraction of the third bytes of each operand, in the third byte of the return value.\n
                 the subtraction of the fourth bytes of each operand, in the fourth byte of the return value.
  \remark
                 absdiff1 = val1[7:0]   - val2[7:0]        \n
                 absdiff2 = val1[15:8]  - val2[15:8]       \n
                 absdiff3 = val1[23:16] - val2[23:16]      \n
                 absdiff4 = val1[31:24] - val2[31:24]      \n
                 sum = absdiff1 + absdiff2 + absdiff3 + absdiff4 \n
                 res[31:0] = sum[31:0] + val3[31:0]
 */
__ALWAYS_INLINE uint32_t __USADA8(uint32_t x, uint32_t y, uint32_t sum)
{
  int32_t r, s, t, u;

  r = (((x << 24) >> 24) - ((y << 24) >> 24)) & 0x000000FF;
  s = (((x << 16) >> 24) - ((y << 16) >> 24)) & 0x000000FF;
  t = (((x <<  8) >> 24) - ((y <<  8) >> 24)) & 0x000000FF;
  u = (((x      ) >> 24) - ((y      ) >> 24)) & 0x000000FF;

  return (u + t + s + r + sum);
}

/**
  \brief   Dual 16-bit saturating addition.
  \details This function enables you to perform two 16-bit integer arithmetic additions in parallel,
           saturating the results to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the saturated addition of the low halfwords, in the low halfword of the return value.\n
                 the saturated addition of the high halfwords, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \remark
                 res[15:0]  = val1[15:0]  + val2[15:0]        \n
                 res[31:16] = val1[31:16] + val2[31:16]
 */
__ALWAYS_INLINE uint32_t __QADD16(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("padd.s16.s %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  int32_t r = 0, s = 0;

  r = __SSAT_16(((((int32_t)x << 16) >> 16) + (((int32_t)y << 16) >> 16))) & (int32_t)0x0000FFFF;
  s = __SSAT_16(((((int32_t)x      ) >> 16) + (((int32_t)y      ) >> 16))) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned saturating addition.
  \details This function enables you to perform two unsigned 16-bit integer additions, saturating
           the results to the 16-bit unsigned integer range 0 < x < 2^16 - 1.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the saturated addition of the low halfwords, in the low halfword of the return value.\n
                 the saturated addition of the high halfwords, in the high halfword of the return value.\n
                 The results are saturated to the 16-bit unsigned integer range 0 < x < 2^16 - 1.
  \remark
                 res[15:0]  = val1[15:0]  + val2[15:0]        \n
                 res[31:16] = val1[31:16] + val2[31:16]
 */
__ALWAYS_INLINE uint32_t __UQADD16(uint32_t x, uint32_t y)
{
  int32_t r = 0, s = 0;

  r = __IUSAT((((x << 16) >> 16) + ((y << 16) >> 16)), 16) & 0x0000FFFF;
  s = __IUSAT((((x      ) >> 16) + ((y      ) >> 16)), 16) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit signed addition.
  \details This function enables you to perform two 16-bit signed integer additions.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the addition of the low halfwords in the low halfword of the return value.\n
                 the addition of the high halfwords in the high halfword of the return value.
  \remark
                 res[15:0]  = val1[15:0]  + val2[15:0]        \n
                 res[31:16] = val1[31:16] + val2[31:16]
 */
__ALWAYS_INLINE uint32_t __SADD16(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("padd.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  int32_t r = 0, s = 0;

  r = ((((int32_t)x << 16) >> 16) + (((int32_t)y << 16) >> 16)) & (int32_t)0x0000FFFF;
  s = ((((int32_t)x      ) >> 16) + (((int32_t)y      ) >> 16)) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned addition
  \details This function enables you to perform two 16-bit unsigned integer additions.
  \param [in]    x   first two 16-bit summands for each addition.
  \param [in]    y   second two 16-bit summands for each addition.
  \return        the addition of the low halfwords in the low halfword of the return value.\n
                 the addition of the high halfwords in the high halfword of the return value.
  \remark
                 res[15:0]  = val1[15:0]  + val2[15:0]        \n
                 res[31:16] = val1[31:16] + val2[31:16]
 */
__ALWAYS_INLINE uint32_t __UADD16(uint32_t x, uint32_t y)
{
  int32_t r = 0, s = 0;

  r = (((x << 16) >> 16) + ((y << 16) >> 16)) & 0x0000FFFF;
  s = (((x      ) >> 16) + ((y      ) >> 16)) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}


/**
  \brief   Dual 16-bit signed addition with halved results.
  \details This function enables you to perform two signed 16-bit integer additions, halving the results.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the halved addition of the low halfwords, in the low halfword of the return value.\n
                 the halved addition of the high halfwords, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  + val2[15:0]) >> 1        \n
                 res[31:16] = (val1[31:16] + val2[31:16]) >> 1
 */
__ALWAYS_INLINE uint32_t __SHADD16(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("paddh.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  int32_t r, s;

  r = (((((int32_t)x << 16) >> 16) + (((int32_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;
  s = (((((int32_t)x      ) >> 16) + (((int32_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned addition with halved results.
  \details This function enables you to perform two unsigned 16-bit integer additions, halving the results.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the halved addition of the low halfwords, in the low halfword of the return value.\n
                 the halved addition of the high halfwords, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  + val2[15:0]) >> 1        \n
                 res[31:16] = (val1[31:16] + val2[31:16]) >> 1
 */
__ALWAYS_INLINE uint32_t __UHADD16(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = ((((x << 16) >> 16) + ((y << 16) >> 16)) >> 1) & 0x0000FFFF;
  s = ((((x      ) >> 16) + ((y      ) >> 16)) >> 1) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Quad 8-bit signed addition with halved results.
  \details This function enables you to perform four signed 8-bit integer additions, halving the results.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the halved addition of the first bytes from each operand, in the first byte of the return value.\n
                 the halved addition of the second bytes from each operand, in the second byte of the return value.\n
                 the halved addition of the third bytes from each operand, in the third byte of the return value.\n
                 the halved addition of the fourth bytes from each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = (val1[7:0]   + val2[7:0]  ) >> 1    \n
                 res[15:8]  = (val1[15:8]  + val2[15:8] ) >> 1    \n
                 res[23:16] = (val1[23:16] + val2[23:16]) >> 1    \n
                 res[31:24] = (val1[31:24] + val2[31:24]) >> 1
 */
__ALWAYS_INLINE uint32_t __SHADD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = (((((int32_t)x << 24) >> 24) + (((int32_t)y << 24) >> 24)) >> 1) & (int32_t)0x000000FF;
  s = (((((int32_t)x << 16) >> 24) + (((int32_t)y << 16) >> 24)) >> 1) & (int32_t)0x000000FF;
  t = (((((int32_t)x <<  8) >> 24) + (((int32_t)y <<  8) >> 24)) >> 1) & (int32_t)0x000000FF;
  u = (((((int32_t)x      ) >> 24) + (((int32_t)y      ) >> 24)) >> 1) & (int32_t)0x000000FF;

  return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
}

/**
  \brief   Quad 8-bit unsigned addition with halved results.
  \details This function enables you to perform four unsigned 8-bit integer additions, halving the results.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the halved addition of the first bytes from each operand, in the first byte of the return value.\n
                 the halved addition of the second bytes from each operand, in the second byte of the return value.\n
                 the halved addition of the third bytes from each operand, in the third byte of the return value.\n
                 the halved addition of the fourth bytes from each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = (val1[7:0]   + val2[7:0]  ) >> 1    \n
                 res[15:8]  = (val1[15:8]  + val2[15:8] ) >> 1    \n
                 res[23:16] = (val1[23:16] + val2[23:16]) >> 1    \n
                 res[31:24] = (val1[31:24] + val2[31:24]) >> 1
 */
__ALWAYS_INLINE uint32_t __UHADD8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = ((((x << 24) >> 24) + ((y << 24) >> 24)) >> 1) & 0x000000FF;
  s = ((((x << 16) >> 24) + ((y << 16) >> 24)) >> 1) & 0x000000FF;
  t = ((((x <<  8) >> 24) + ((y <<  8) >> 24)) >> 1) & 0x000000FF;
  u = ((((x      ) >> 24) + ((y      ) >> 24)) >> 1) & 0x000000FF;

  return ((u << 24) | (t << 16) | (s <<  8) | (r      ));
}

/**
  \brief   Dual 16-bit saturating subtract.
  \details This function enables you to perform two 16-bit integer subtractions in parallel,
           saturating the results to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the saturated subtraction of the low halfwords, in the low halfword of the return value.\n
                 the saturated subtraction of the high halfwords, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \remark
                 res[15:0]  = val1[15:0]  - val2[15:0]        \n
                 res[31:16] = val1[31:16] - val2[31:16]
 */
__ALWAYS_INLINE uint32_t __QSUB16(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("psub.s16.s %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  int32_t r, s;

  r = __SSAT_16(((((int32_t)x << 16) >> 16) - (((int32_t)y << 16) >> 16))) & (int32_t)0x0000FFFF;
  s = __SSAT_16(((((int32_t)x      ) >> 16) - (((int32_t)y      ) >> 16))) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned saturating subtraction.
  \details This function enables you to perform two unsigned 16-bit integer subtractions,
           saturating the results to the 16-bit unsigned integer range 0 < x < 2^16 - 1.
  \param [in]    x   first two 16-bit operands for each subtraction.
  \param [in]    y   second two 16-bit operands for each subtraction.
  \return        the saturated subtraction of the low halfwords, in the low halfword of the return value.\n
                 the saturated subtraction of the high halfwords, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \remark
                 res[15:0]  = val1[15:0]  - val2[15:0]        \n
                 res[31:16] = val1[31:16] - val2[31:16]
 */
__ALWAYS_INLINE uint32_t __UQSUB16(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = __IUSAT((((x << 16) >> 16) - ((y << 16) >> 16)), 16) & 0x0000FFFF;
  s = __IUSAT((((x      ) >> 16) - ((y      ) >> 16)), 16) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit signed subtraction.
  \details This function enables you to perform two 16-bit signed integer subtractions.
  \param [in]    x   first two 16-bit operands of each subtraction.
  \param [in]    y   second two 16-bit operands of each subtraction.
  \return        the subtraction of the low halfword in the second operand from the low
                 halfword in the first operand, in the low halfword of the return value. \n
                 the subtraction of the high halfword in the second operand from the high
                 halfword in the first operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = val1[15:0]  - val2[15:0]        \n
                 res[31:16] = val1[31:16] - val2[31:16]
 */
__ALWAYS_INLINE uint32_t __SSUB16(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("psub.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  int32_t r, s;

  r = ((((int32_t)x << 16) >> 16) - (((int32_t)y << 16) >> 16)) & (int32_t)0x0000FFFF;
  s = ((((int32_t)x      ) >> 16) - (((int32_t)y      ) >> 16)) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned subtract.
  \details This function enables you to perform two 16-bit unsigned integer subtractions.
  \param [in]    x   first two 16-bit operands of each subtraction.
  \param [in]    y   second two 16-bit operands of each subtraction.
  \return        the subtraction of the low halfword in the second operand from the low
                 halfword in the first operand, in the low halfword of the return value. \n
                 the subtraction of the high halfword in the second operand from the high
                 halfword in the first operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = val1[15:0]  - val2[15:0]        \n
                 res[31:16] = val1[31:16] - val2[31:16]
 */
__ALWAYS_INLINE uint32_t __USUB16(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = (((x << 16) >> 16) - ((y << 16) >> 16)) & 0x0000FFFF;
  s = (((x      ) >> 16) - ((y      ) >> 16)) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit signed subtraction with halved results.
  \details This function enables you to perform two signed 16-bit integer subtractions, halving the results.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the halved subtraction of the low halfwords, in the low halfword of the return value.\n
                 the halved subtraction of the high halfwords, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  - val2[15:0]) >> 1        \n
                 res[31:16] = (val1[31:16] - val2[31:16]) >> 1
 */
__ALWAYS_INLINE uint32_t __SHSUB16(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("psubh.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  int32_t r, s;

  r = (((((int32_t)x << 16) >> 16) - (((int32_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;
  s = (((((int32_t)x      ) >> 16) - (((int32_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned subtraction with halved results.
  \details This function enables you to perform two unsigned 16-bit integer subtractions, halving the results.
  \param [in]    x   first two 16-bit summands.
  \param [in]    y   second two 16-bit summands.
  \return        the halved subtraction of the low halfwords, in the low halfword of the return value.\n
                 the halved subtraction of the high halfwords, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  - val2[15:0]) >> 1        \n
                 res[31:16] = (val1[31:16] - val2[31:16]) >> 1
 */
__ALWAYS_INLINE uint32_t __UHSUB16(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = ((((x << 16) >> 16) - ((y << 16) >> 16)) >> 1) & 0x0000FFFF;
  s = ((((x      ) >> 16) - ((y      ) >> 16)) >> 1) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Quad 8-bit signed addition with halved results.
  \details This function enables you to perform four signed 8-bit integer subtractions, halving the results.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the halved subtraction of the first bytes from each operand, in the first byte of the return value.\n
                 the halved subtraction of the second bytes from each operand, in the second byte of the return value.\n
                 the halved subtraction of the third bytes from each operand, in the third byte of the return value.\n
                 the halved subtraction of the fourth bytes from each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = (val1[7:0]   - val2[7:0]  ) >> 1    \n
                 res[15:8]  = (val1[15:8]  - val2[15:8] ) >> 1    \n
                 res[23:16] = (val1[23:16] - val2[23:16]) >> 1    \n
                 res[31:24] = (val1[31:24] - val2[31:24]) >> 1
 */
__ALWAYS_INLINE uint32_t __SHSUB8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = (((((int32_t)x << 24) >> 24) - (((int32_t)y << 24) >> 24)) >> 1) & (int32_t)0x000000FF;
  s = (((((int32_t)x << 16) >> 24) - (((int32_t)y << 16) >> 24)) >> 1) & (int32_t)0x000000FF;
  t = (((((int32_t)x <<  8) >> 24) - (((int32_t)y <<  8) >> 24)) >> 1) & (int32_t)0x000000FF;
  u = (((((int32_t)x      ) >> 24) - (((int32_t)y      ) >> 24)) >> 1) & (int32_t)0x000000FF;

  return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
}

/**
  \brief   Quad 8-bit unsigned subtraction with halved results.
  \details This function enables you to perform four unsigned 8-bit integer subtractions, halving the results.
  \param [in]    x   first four 8-bit summands.
  \param [in]    y   second four 8-bit summands.
  \return        the halved subtraction of the first bytes from each operand, in the first byte of the return value.\n
                 the halved subtraction of the second bytes from each operand, in the second byte of the return value.\n
                 the halved subtraction of the third bytes from each operand, in the third byte of the return value.\n
                 the halved subtraction of the fourth bytes from each operand, in the fourth byte of the return value.
  \remark
                 res[7:0]   = (val1[7:0]   - val2[7:0]  ) >> 1    \n
                 res[15:8]  = (val1[15:8]  - val2[15:8] ) >> 1    \n
                 res[23:16] = (val1[23:16] - val2[23:16]) >> 1    \n
                 res[31:24] = (val1[31:24] - val2[31:24]) >> 1
 */
__ALWAYS_INLINE uint32_t __UHSUB8(uint32_t x, uint32_t y)
{
  int32_t r, s, t, u;

  r = ((((x << 24) >> 24) - ((y << 24) >> 24)) >> 1) & 0x000000FF;
  s = ((((x << 16) >> 24) - ((y << 16) >> 24)) >> 1) & 0x000000FF;
  t = ((((x <<  8) >> 24) - ((y <<  8) >> 24)) >> 1) & 0x000000FF;
  u = ((((x      ) >> 24) - ((y      ) >> 24)) >> 1) & 0x000000FF;

  return ((u << 24) | (t << 16) | (s <<  8) | (r      ));
}

/**
  \brief   Dual 16-bit add and subtract with exchange.
  \details This function enables you to exchange the halfwords of the one operand,
           then add the high halfwords and subtract the low halfwords,
           saturating the results to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \param [in]    x   first operand for the subtraction in the low halfword,
                     and the first operand for the addition in the high halfword.
  \param [in]    y   second operand for the subtraction in the high halfword,
                     and the second operand for the addition in the low halfword.
  \return        the saturated subtraction of the high halfword in the second operand from the
                 low halfword in the first operand, in the low halfword of the return value.\n
                 the saturated addition of the high halfword in the first operand and the
                 low halfword in the second operand, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \remark
                 res[15:0]  = val1[15:0]  - val2[31:16]        \n
                 res[31:16] = val1[31:16] + val2[15:0]
 */
__ALWAYS_INLINE uint32_t __QASX(uint32_t x, uint32_t y)
{
  int32_t r, s;

#ifdef CSKY_SIMD
  r = __QSUB16(x, (int32_t)y >> 16) & (int32_t)0x0000FFFF;
  s = __QADD16(x, (int32_t)y << 16) & (int32_t)0xFFFF0000;

  return r | s;
#else
  r = __SSAT_16(((((int32_t)x << 16) >> 16) - (((int32_t)y      ) >> 16))) & (int32_t)0x0000FFFF;
  s = __SSAT_16(((((int32_t)x      ) >> 16) + (((int32_t)y << 16) >> 16))) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned saturating addition and subtraction with exchange.
  \details This function enables you to exchange the halfwords of the second operand and
           perform one unsigned 16-bit integer addition and one unsigned 16-bit subtraction,
           saturating the results to the 16-bit unsigned integer range 0 <= x <= 2^16 - 1.
  \param [in]    x   first operand for the subtraction in the low halfword,
                     and the first operand for the addition in the high halfword.
  \param [in]    y   second operand for the subtraction in the high halfword,
                     and the second operand for the addition in the low halfword.
  \return        the saturated subtraction of the high halfword in the second operand from the
                 low halfword in the first operand, in the low halfword of the return value.\n 
                 the saturated addition of the high halfword in the first operand and the
                 low halfword in the second operand, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit unsigned integer range 0 <= x <= 2^16 - 1.
  \remark
                 res[15:0]  = val1[15:0]  - val2[31:16]        \n
                 res[31:16] = val1[31:16] + val2[15:0]
 */
__ALWAYS_INLINE uint32_t __UQASX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = __IUSAT((((x << 16) >> 16) - ((y      ) >> 16)), 16) & 0x0000FFFF;
  s = __IUSAT((((x      ) >> 16) + ((y << 16) >> 16)), 16) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit addition and subtraction with exchange.
  \details It enables you to exchange the halfwords of the second operand, add the high halfwords
           and subtract the low halfwords.
  \param [in]    x   first operand for the subtraction in the low halfword,
                     and the first operand for the addition in the high halfword.
  \param [in]    y   second operand for the subtraction in the high halfword,
                     and the second operand for the addition in the low halfword.
  \return        the subtraction of the high halfword in the second operand from the
                 low halfword in the first operand, in the low halfword of the return value.\n
                 the addition of the high halfword in the first operand and the
                 low halfword in the second operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = val1[15:0]  - val2[31:16]        \n
                 res[31:16] = val1[31:16] + val2[15:0]
 */
__ALWAYS_INLINE uint32_t __SASX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = ((((int32_t)x << 16) >> 16) - (((int32_t)y      ) >> 16)) & (int32_t)0x0000FFFF;
  s = ((((int32_t)x      ) >> 16) + (((int32_t)y << 16) >> 16)) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
}

/**
  \brief   Dual 16-bit unsigned addition and subtraction with exchange.
  \details This function enables you to exchange the two halfwords of the second operand,
           add the high halfwords and subtract the low halfwords.
  \param [in]    x   first operand for the subtraction in the low halfword,
                     and the first operand for the addition in the high halfword.
  \param [in]    y   second operand for the subtraction in the high halfword,
                     and the second operand for the addition in the low halfword.
  \return        the subtraction of the high halfword in the second operand from the
                 low halfword in the first operand, in the low halfword of the return value.\n
                 the addition of the high halfword in the first operand and the
                 low halfword in the second operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = val1[15:0]  - val2[31:16]        \n
                 res[31:16] = val1[31:16] + val2[15:0]
 */
__ALWAYS_INLINE uint32_t __UASX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = (((x << 16) >> 16) - ((y      ) >> 16)) & 0x0000FFFF;
  s = (((x      ) >> 16) + ((y << 16) >> 16)) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit signed addition and subtraction with halved results.
  \details This function enables you to exchange the two halfwords of one operand, perform one
           signed 16-bit integer addition and one signed 16-bit subtraction, and halve the results.
  \param [in]    x   first 16-bit operands.
  \param [in]    y   second 16-bit operands.
  \return        the halved subtraction of the high halfword in the second operand from the
                 low halfword in the first operand, in the low halfword of the return value.\n
                 the halved addition of the low halfword in the second operand from the high
                 halfword in the first operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  - val2[31:16]) >> 1        \n
                 res[31:16] = (val1[31:16] + val2[15:0]) >> 1
 */
__ALWAYS_INLINE uint32_t __SHASX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = (((((int32_t)x << 16) >> 16) - (((int32_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;
  s = (((((int32_t)x      ) >> 16) + (((int32_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
}

/**
  \brief   Dual 16-bit unsigned addition and subtraction with halved results and exchange.
  \details This function enables you to exchange the halfwords of the second operand,
           add the high halfwords and subtract the low halfwords, halving the results.
  \param [in]    x   first operand for the subtraction in the low halfword, and
                     the first operand for the addition in the high halfword.
  \param [in]    y   second operand for the subtraction in the high halfword, and
                     the second operand for the addition in the low halfword.
  \return        the halved subtraction of the high halfword in the second operand from the
                 low halfword in the first operand, in the low halfword of the return value.\n
                 the halved addition of the low halfword in the second operand from the high
                 halfword in the first operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  - val2[31:16]) >> 1        \n
                 res[31:16] = (val1[31:16] + val2[15:0]) >> 1
 */
__ALWAYS_INLINE uint32_t __UHASX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = ((((x << 16) >> 16) - ((y      ) >> 16)) >> 1) & 0x0000FFFF;
  s = ((((x      ) >> 16) + ((y << 16) >> 16)) >> 1) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit subtract and add with exchange.
  \details This function enables you to exchange the halfwords of one operand,
           then subtract the high halfwords and add the low halfwords,
           saturating the results to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \param [in]    x   first operand for the addition in the low halfword,
                     and the first operand for the subtraction in the high halfword.
  \param [in]    y   second operand for the addition in the high halfword,
                     and the second operand for the subtraction in the low halfword.
  \return        the saturated addition of the low halfword of the first operand and the high
                 halfword of the second operand, in the low halfword of the return value.\n
                 the saturated subtraction of the low halfword of the second operand from the
                 high halfword of the first operand, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit signed integer range -2^15 <= x <= 2^15 - 1.
  \remark
                 res[15:0]  = val1[15:0]  + val2[31:16]        \n
                 res[31:16] = val1[31:16] - val2[15:0]
 */
__ALWAYS_INLINE uint32_t __QSAX(uint32_t x, uint32_t y)
{
  int32_t r, s;

#ifdef CSKY_SIMD
  r = __QADD16(x, (int32_t)y >> 16) & (int32_t)0x0000FFFF;
  s = __QSUB16(x, (int32_t)y << 16) & (int32_t)0xFFFF0000;

  return r | s;
#else
  r = __SSAT_16(((((int32_t)x << 16) >> 16) + (((int32_t)y      ) >> 16))) & (int32_t)0x0000FFFF;
  s = __SSAT_16(((((int32_t)x      ) >> 16) - (((int32_t)y << 16) >> 16))) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
#endif
}

/**
  \brief   Dual 16-bit unsigned saturating subtraction and addition with exchange.
  \details This function enables you to exchange the halfwords of the second operand and perform
           one unsigned 16-bit integer subtraction and one unsigned 16-bit addition, saturating
           the results to the 16-bit unsigned integer range 0 <= x <= 2^16 - 1.
  \param [in]    x   first operand for the addition in the low halfword,
                     and the first operand for the subtraction in the high halfword.
  \param [in]    y   second operand for the addition in the high halfword,
                     and the second operand for the subtraction in the low halfword.
  \return        the saturated addition of the low halfword of the first operand and the high
                 halfword of the second operand, in the low halfword of the return value.\n
                 the saturated subtraction of the low halfword of the second operand from the
                 high halfword of the first operand, in the high halfword of the return value.\n
                 The returned results are saturated to the 16-bit unsigned integer range 0 <= x <= 2^16 - 1.
  \remark
                 res[15:0]  = val1[15:0]  + val2[31:16]        \n
                 res[31:16] = val1[31:16] - val2[15:0]
 */
__ALWAYS_INLINE uint32_t __UQSAX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = __IUSAT((((x << 16) >> 16) + ((y      ) >> 16)), 16) & 0x0000FFFF;
  s = __IUSAT((((x      ) >> 16) - ((y << 16) >> 16)), 16) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit unsigned subtract and add with exchange.
  \details This function enables you to exchange the halfwords of the second operand,
           subtract the high halfwords and add the low halfwords.
  \param [in]    x   first operand for the addition in the low halfword,
                     and the first operand for the subtraction in the high halfword.
  \param [in]    y   second operand for the addition in the high halfword,
                     and the second operand for the subtraction in the low halfword.
  \return        the addition of the low halfword of the first operand and the high
                 halfword of the second operand, in the low halfword of the return value.\n
                 the subtraction of the low halfword of the second operand from the
                 high halfword of the first operand, in the high halfword of the return value.\n
  \remark
                 res[15:0]  = val1[15:0]  + val2[31:16]        \n
                 res[31:16] = val1[31:16] - val2[15:0]
 */
__ALWAYS_INLINE uint32_t __USAX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = (((x << 16) >> 16) + ((y      ) >> 16)) & 0x0000FFFF;
  s = (((x      ) >> 16) - ((y << 16) >> 16)) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit signed subtraction and addition with exchange.
  \details This function enables you to exchange the two halfwords of one operand and perform one
           16-bit integer subtraction and one 16-bit addition.
  \param [in]    x   first operand for the addition in the low halfword, and the first operand
                     for the subtraction in the high halfword.
  \param [in]    y   second operand for the addition in the high halfword, and the second
                     operand for the subtraction in the low halfword.
  \return        the addition of the low halfword of the first operand and the high
                 halfword of the second operand, in the low halfword of the return value.\n
                 the subtraction of the low halfword of the second operand from the
                 high halfword of the first operand, in the high halfword of the return value.\n
  \remark
                 res[15:0]  = val1[15:0]  + val2[31:16]        \n
                 res[31:16] = val1[31:16] - val2[15:0]
 */
__ALWAYS_INLINE uint32_t __SSAX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = ((((int32_t)x << 16) >> 16) + (((int32_t)y      ) >> 16)) & (int32_t)0x0000FFFF;
  s = ((((int32_t)x      ) >> 16) - (((int32_t)y << 16) >> 16)) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
}


/**
  \brief   Dual 16-bit signed subtraction and addition with halved results.
  \details This function enables you to exchange the two halfwords of one operand, perform one signed
           16-bit integer subtraction and one signed 16-bit addition, and halve the results.
  \param [in]    x   first 16-bit operands.
  \param [in]    y   second 16-bit operands.
  \return        the halved addition of the low halfword in the first operand and the
                 high halfword in the second operand, in the low halfword of the return value.\n
                 the halved subtraction of the low halfword in the second operand from the
                 high halfword in the first operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  + val2[31:16]) >> 1        \n
                 res[31:16] = (val1[31:16] - val2[15:0]) >> 1
 */
__ALWAYS_INLINE uint32_t __SHSAX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = (((((int32_t)x << 16) >> 16) + (((int32_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;
  s = (((((int32_t)x      ) >> 16) - (((int32_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;

  return ((uint32_t)((s << 16) | (r      )));
}

/**
  \brief   Dual 16-bit unsigned subtraction and addition with halved results and exchange.
  \details This function enables you to exchange the halfwords of the second operand,
           subtract the high halfwords and add the low halfwords, halving the results.
  \param [in]    x   first operand for the addition in the low halfword, and
                     the first operand for the subtraction in the high halfword.
  \param [in]    y   second operand for the addition in the high halfword, and
                     the second operand for the subtraction in the low halfword.
  \return        the halved addition of the low halfword in the first operand and the
                 high halfword in the second operand, in the low halfword of the return value.\n
                 the halved subtraction of the low halfword in the second operand from the
                 high halfword in the first operand, in the high halfword of the return value.
  \remark
                 res[15:0]  = (val1[15:0]  + val2[31:16]) >> 1        \n
                 res[31:16] = (val1[31:16] - val2[15:0]) >> 1
 */
__ALWAYS_INLINE uint32_t __UHSAX(uint32_t x, uint32_t y)
{
  int32_t r, s;

  r = ((((x << 16) >> 16) + ((y      ) >> 16)) >> 1) & 0x0000FFFF;
  s = ((((x      ) >> 16) - ((y << 16) >> 16)) >> 1) & 0x0000FFFF;

  return ((s << 16) | (r      ));
}

/**
  \brief   Dual 16-bit signed multiply with exchange returning difference.
  \details This function enables you to perform two 16-bit signed multiplications, subtracting
           one of the products from the other. The halfwords of the second operand are exchanged
           before performing the arithmetic. This produces top * bottom and bottom * top multiplication.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \return        the difference of the products of the two 16-bit signed multiplications.
  \remark
                 p1 = val1[15:0]  * val2[31:16]       \n
                 p2 = val1[31:16] * val2[15:0]        \n
                 res[31:0] = p1 - p2
 */
__ALWAYS_INLINE uint32_t __SMUSDX(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("mulcsx.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y      ) >> 16)) -
                     ((((int32_t)x      ) >> 16) * (((int32_t)y << 16) >> 16))   ));
#endif
}

/**
  \brief   Sum of dual 16-bit signed multiply with exchange.
  \details This function enables you to perform two 16-bit signed multiplications with exchanged
           halfwords of the second operand, adding the products together.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \return        the sum of the products of the two 16-bit signed multiplications with exchanged halfwords of the second operand.
  \remark
                 p1 = val1[15:0]  * val2[31:16]       \n
                 p2 = val1[31:16] * val2[15:0]        \n
                 res[31:0] = p1 + p2
 */
__ALWAYS_INLINE uint32_t __SMUADX(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("mulcax.s16 %0, %2, %1\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y      ) >> 16)) +
                     ((((int32_t)x      ) >> 16) * (((int32_t)y << 16) >> 16))   ));
#endif
}


/**
  \brief   Saturating add.
  \details This function enables you to obtain the saturating add of two integers.
  \param [in]    x   first summand of the saturating add operation.
  \param [in]    y   second summand of the saturating add operation.
  \return        the saturating addition of val1 and val2.
  \remark
                 res[31:0] = SAT(val1 + SAT(val2))
 */
__ALWAYS_INLINE int32_t __QADD(int32_t x, int32_t y)
{
  int32_t result;
#ifdef CSKY_SIMD
  __ASM volatile("add.s32.s %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
#else
  if (y >= 0) {
    if (x + y >= x) {
      result = x + y;
    } else {
      result = 0x7FFFFFFF;
    }
  } else {
    if (x + y < x) {
      result = x + y;
    } else {
      result = 0x80000000;
    }
  }
#endif

  return result;
}

/**
  \brief   Saturating subtract.
  \details This function enables you to obtain the saturating sub of two integers.
  \param [in]    x   first summand of the saturating add operation.
  \param [in]    y   second summand of the saturating add operation.
  \return        the saturating subtraction of val1 and val2.
  \remark
                 res[31:0] = SAT(val1 + SAT(val2))
 */
__ALWAYS_INLINE int32_t __QSUB(int32_t x, int32_t y)
{
  int32_t result;

#ifdef CSKY_SIMD
  __ASM volatile("sub.s32.s %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
#else
  int64_t tmp;
  tmp = (int64_t)x - (int64_t)y;
  if (tmp > 0x7fffffff) {
    tmp = 0x7fffffff;
  } else if (tmp < (-2147483647 - 1)){
    tmp = -2147483647-1;
  }

  result = tmp;
#endif

  return result;
}

/**
  \brief   Dual 16-bit signed multiply with single 32-bit accumulator.
  \details This function enables you to perform two signed 16-bit multiplications,
           adding both results to a 32-bit accumulate operand.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the product of each multiplication added to the accumulate value, as a 32-bit integer.
  \remark
                 p1 = val1[15:0]  * val2[15:0]      \n
                 p2 = val1[31:16] * val2[31:16]     \n
                 res[31:0] = p1 + p2 + val3[31:0]
 */
__ALWAYS_INLINE uint32_t __SMUAD(uint32_t x, uint32_t y);
__ALWAYS_INLINE uint32_t __SMUADX(uint32_t x, uint32_t y);
__ALWAYS_INLINE uint32_t __SMLAD(uint32_t x, uint32_t y, uint32_t sum)
{
#ifdef CSKY_SIMD
  return sum + __SMUAD(x, y);
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ((((int32_t)x      ) >> 16) * (((int32_t)y      ) >> 16)) +
                     ( ((int32_t)sum    )                                  )   ));
#endif
}

/**
  \brief   Pre-exchanged dual 16-bit signed multiply with single 32-bit accumulator.
  \details This function enables you to perform two signed 16-bit multiplications with exchanged
           halfwords of the second operand, adding both results to a 32-bit accumulate operand.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the product of each multiplication with exchanged halfwords of the second
                 operand added to the accumulate value, as a 32-bit integer.
  \remark
                 p1 = val1[15:0]  * val2[31:16]     \n
                 p2 = val1[31:16] * val2[15:0]      \n
                 res[31:0] = p1 + p2 + val3[31:0]
 */
__ALWAYS_INLINE uint32_t __SMLADX(uint32_t x, uint32_t y, uint32_t sum)
{
#ifdef CSKY_SIMD
  return sum + __SMUADX(x, y);
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y      ) >> 16)) +
                     ((((int32_t)x      ) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ( ((int32_t)sum    )                                  )   ));
#endif
}

/**
  \brief   Dual 16-bit signed multiply with exchange subtract with 32-bit accumulate.
  \details This function enables you to perform two 16-bit signed multiplications, take the
           difference of the products, subtracting the high halfword product from the low
           halfword product, and add the difference to a 32-bit accumulate operand.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the difference of the product of each multiplication, added to the accumulate value.
  \remark
                 p1 = val1[15:0]  * val2[15:0]       \n
                 p2 = val1[31:16] * val2[31:16]      \n
                 res[31:0] = p1 - p2 + val3[31:0]
 */
__ALWAYS_INLINE uint32_t __SMUSD(uint32_t x, uint32_t y);
__ALWAYS_INLINE uint32_t __SMUSDX(uint32_t x, uint32_t y);
__ALWAYS_INLINE uint32_t __SMLSD(uint32_t x, uint32_t y, uint32_t sum)
{
#ifdef CSKY_SIMD
  return __SMUSD(x, y) + sum;
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y << 16) >> 16)) -
                     ((((int32_t)x      ) >> 16) * (((int32_t)y      ) >> 16)) +
                     ( ((int32_t)sum    )                                  )   ));
#endif
}

/**
  \brief   Dual 16-bit signed multiply with exchange subtract with 32-bit accumulate.
  \details This function enables you to exchange the halfwords in the second operand, then perform two 16-bit
           signed multiplications. The difference of the products is added to a 32-bit accumulate operand.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the difference of the product of each multiplication, added to the accumulate value.
  \remark
                 p1 = val1[15:0]  * val2[31:16]     \n
                 p2 = val1[31:16] * val2[15:0]      \n
                 res[31:0] = p1 - p2 + val3[31:0]
 */
__ALWAYS_INLINE uint32_t __SMLSDX(uint32_t x, uint32_t y, uint32_t sum)
{
#ifdef CSKY_SIMD
  return __SMUSDX(x, y) + sum;
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y      ) >> 16)) -
                     ((((int32_t)x      ) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ( ((int32_t)sum    )                                  )   ));
#endif
}

/**
  \brief   Dual 16-bit signed multiply with single 64-bit accumulator.
  \details This function enables you to perform two signed 16-bit multiplications, adding both results
           to a 64-bit accumulate operand. Overflow is only possible as a result of the 64-bit addition.
           This overflow is not detected if it occurs. Instead, the result wraps around modulo2^64.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the product of each multiplication added to the accumulate value.
  \remark
                 p1 = val1[15:0]  * val2[15:0]      \n
                 p2 = val1[31:16] * val2[31:16]     \n
                 sum = p1 + p2 + val3[63:32][31:0]  \n
                 res[63:32] = sum[63:32]            \n
                 res[31:0]  = sum[31:0]
 */
__ALWAYS_INLINE uint64_t __SMLALD(uint32_t x, uint32_t y, uint64_t sum)
{
#ifdef CSKY_SIMD
  __ASM volatile("mulaca.s16.e %0, %R0, %1, %2\n\t"
                   :"=r" (sum), "=r" (x), "=r" (y) : "0" (sum), "1" (x), "2" (y));
  return sum;
#else
  return ((uint64_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ((((int32_t)x      ) >> 16) * (((int32_t)y      ) >> 16)) +
                     ( ((uint64_t)sum    )                                  )   ));
#endif
}

/**
  \brief   Dual 16-bit signed multiply with exchange with single 64-bit accumulator.
  \details This function enables you to exchange the halfwords of the second operand, and perform two
           signed 16-bit multiplications, adding both results to a 64-bit accumulate operand. Overflow
           is only possible as a result of the 64-bit addition. This overflow is not detected if it occurs.
           Instead, the result wraps around modulo2^64.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the product of each multiplication added to the accumulate value.
  \remark
                 p1 = val1[15:0]  * val2[31:16]     \n
                 p2 = val1[31:16] * val2[15:0]      \n
                 sum = p1 + p2 + val3[63:32][31:0]  \n
                 res[63:32] = sum[63:32]            \n
                 res[31:0]  = sum[31:0]
 */
__ALWAYS_INLINE uint64_t __SMLALDX(uint32_t x, uint32_t y, uint64_t sum)
{
#ifdef CSKY_SIMD
  __ASM volatile("mulacax.s16.e %0, %R0, %2, %1\n\t"
                   :"=r" (sum), "=r" (x), "=r" (y) : "0" (sum), "1" (x), "2" (y));
  return sum;
#else
  return ((uint64_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y      ) >> 16)) +
                     ((((int32_t)x      ) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ( ((uint64_t)sum    )                                  )   ));
#endif
}

/**
  \brief   dual 16-bit signed multiply subtract with 64-bit accumulate.
  \details This function It enables you to perform two 16-bit signed multiplications, take the difference
           of the products, subtracting the high halfword product from the low halfword product, and add the
           difference to a 64-bit accumulate operand. Overflow cannot occur during the multiplications or the
           subtraction. Overflow can occur as a result of the 64-bit addition, and this overflow is not
           detected. Instead, the result wraps round to modulo2^64.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the difference of the product of each multiplication, added to the accumulate value.
  \remark
                 p1 = val1[15:0]  * val2[15:0]      \n
                 p2 = val1[31:16] * val2[31:16]     \n
                 res[63:0] = p1 - p2 + val3[63:0]
 */
__ALWAYS_INLINE uint64_t __SMLSLD(uint32_t x, uint32_t y, uint64_t sum)
{
  return ((uint64_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y << 16) >> 16)) -
                     ((((int32_t)x      ) >> 16) * (((int32_t)y      ) >> 16)) +
                     ( ((uint64_t)sum    )                                  )   ));
}

/**
  \brief   Dual 16-bit signed multiply with exchange subtract with 64-bit accumulate.
  \details This function enables you to exchange the halfwords of the second operand, perform two 16-bit multiplications,
           adding the difference of the products to a 64-bit accumulate operand. Overflow cannot occur during the
           multiplications or the subtraction. Overflow can occur as a result of the 64-bit addition, and this overflow
           is not detected. Instead, the result wraps round to modulo2^64.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \param [in]  sum   accumulate value.
  \return        the difference of the product of each multiplication, added to the accumulate value.
  \remark
                 p1 = val1[15:0]  * val2[31:16]      \n
                 p2 = val1[31:16] * val2[15:0]       \n
                 res[63:0] = p1 - p2 + val3[63:0]
 */
__ALWAYS_INLINE uint64_t __SMLSLDX(uint32_t x, uint32_t y, uint64_t sum)
{
  return ((uint64_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y      ) >> 16)) -
                     ((((int32_t)x      ) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ( ((uint64_t)sum    )                                  )   ));
}

/**
  \brief   32-bit signed multiply with 32-bit truncated accumulator.
  \details This function enables you to perform a signed 32-bit multiplications, adding the most
           significant 32 bits of the 64-bit result to a 32-bit accumulate operand.
  \param [in]    x   first operand for multiplication.
  \param [in]    y   second operand for multiplication.
  \param [in]  sum   accumulate value.
  \return        the product of multiplication (most significant 32 bits) is added to the accumulate value, as a 32-bit integer.
  \remark
                 p = val1 * val2      \n
                 res[31:0] = p[61:32] + val3[31:0]
 */
__ALWAYS_INLINE uint32_t __SMMLA(int32_t x, int32_t y, int32_t sum)
{
  return (uint32_t)((int32_t)((int64_t)((int64_t)x * (int64_t)y) >> 32) + sum);
}

/**
  \brief   Sum of dual 16-bit signed multiply.
  \details This function enables you to perform two 16-bit signed multiplications, adding the products together.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \return        the sum of the products of the two 16-bit signed multiplications.
  \remark
                 p1 = val1[15:0]  * val2[15:0]      \n
                 p2 = val1[31:16] * val2[31:16]     \n
                 res[31:0] = p1 + p2
 */
__ALWAYS_INLINE uint32_t __SMUAD(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("mulca.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y << 16) >> 16)) +
                     ((((int32_t)x      ) >> 16) * (((int32_t)y      ) >> 16))   ));
#endif
}

/**
  \brief   Dual 16-bit signed multiply returning difference.
  \details This function enables you to perform two 16-bit signed multiplications, taking the difference
           of the products by subtracting the high halfword product from the low halfword product.
  \param [in]    x   first 16-bit operands for each multiplication.
  \param [in]    y   second 16-bit operands for each multiplication.
  \return        the difference of the products of the two 16-bit signed multiplications.
  \remark
                 p1 = val1[15:0]  * val2[15:0]      \n
                 p2 = val1[31:16] * val2[31:16]     \n
                 res[31:0] = p1 - p2
 */
__ALWAYS_INLINE uint32_t __SMUSD(uint32_t x, uint32_t y)
{
#ifdef CSKY_SIMD
  uint32_t result;
  __ASM volatile("mulcs.s16 %0, %1, %2\n\t"
                   :"=r" (result), "=r" (x), "=r" (y) : "0" (result), "1" (x), "2" (y));
  return result;
#else
  return ((uint32_t)(((((int32_t)x << 16) >> 16) * (((int32_t)y << 16) >> 16)) -
                     ((((int32_t)x      ) >> 16) * (((int32_t)y      ) >> 16))   ));
#endif
}

/**
  \brief   Dual extracted 8-bit to 16-bit signed addition.
  \details This function enables you to extract two 8-bit values from the second operand (at bit positions
           [7:0] and [23:16]), sign-extend them to 16-bits each, and add the results to the first operand.
  \param [in]    x   values added to the sign-extended to 16-bit values.
  \param [in]    x   two 8-bit values to be extracted and sign-extended.
  \return        the addition of val1 and val2, where the 8-bit values in val2[7:0] and
                 val2[23:16] have been extracted and sign-extended prior to the addition.
  \remark
                 res[15:0]  = val1[15:0] + SignExtended(val2[7:0])      \n
                 res[31:16] = val1[31:16] + SignExtended(val2[23:16])
 */
__ALWAYS_INLINE uint32_t __SXTAB16(uint32_t x, uint32_t y)
{
  return ((uint32_t)((((((int32_t)y << 24) >> 24) + (((int32_t)x << 16) >> 16)) & (int32_t)0x0000FFFF) |
                     (((((int32_t)y <<  8) >>  8)  + (((int32_t)x >> 16) << 16)) & (int32_t)0xFFFF0000)  ));
}

/**
  \brief   Extracted 16-bit to 32-bit unsigned addition.
  \details This function enables you to extract two 8-bit values from one operand, zero-extend
           them to 16 bits each, and add the results to two 16-bit values from another operand.
  \param [in]    x   values added to the zero-extended to 16-bit values.
  \param [in]    x   two 8-bit values to be extracted and zero-extended.
  \return        the addition of val1 and val2, where the 8-bit values in val2[7:0] and
                 val2[23:16] have been extracted and zero-extended prior to the addition.
  \remark
                 res[15:0]  = ZeroExt(val2[7:0]   to 16 bits) + val1[15:0]      \n
                 res[31:16] = ZeroExt(val2[31:16] to 16 bits) + val1[31:16]
 */
__ALWAYS_INLINE uint32_t __UXTAB16(uint32_t x, uint32_t y)
{
  return ((uint32_t)(((((y << 24) >> 24) + ((x << 16) >> 16)) & 0x0000FFFF) |
                     ((((y <<  8) >>  8) + ((x >> 16) << 16)) & 0xFFFF0000)  ));
}

/**
  \brief   Dual extract 8-bits and sign extend each to 16-bits.
  \details This function enables you to extract two 8-bit values from an operand and sign-extend them to 16 bits each.
  \param [in]    x   two 8-bit values in val[7:0] and val[23:16] to be sign-extended.
  \return        the 8-bit values sign-extended to 16-bit values.\n
                 sign-extended value of val[7:0] in the low halfword of the return value.\n
                 sign-extended value of val[23:16] in the high halfword of the return value.
  \remark
                 res[15:0]  = SignExtended(val[7:0])       \n
                 res[31:16] = SignExtended(val[23:16])
 */
__ALWAYS_INLINE uint32_t __SXTB16(uint32_t x)
{
#ifdef CSKY_SIMD
  uint32_t res = x;
  __ASM volatile("plsli.16 %0, %0, 8\n\t"
                 "pasri.16 %0, %0, 8\n\t"
                 :"=r" (res) : "0" (res));
  return res;
#else
  return ((uint32_t)(((((int32_t)x << 24) >> 24) & (int32_t)0x0000FFFF) |
                     ((((int32_t)x <<  8) >>  8) & (int32_t)0xFFFF0000)  ));
#endif
}

/**
  \brief   Dual extract 8-bits and zero-extend to 16-bits.
  \details This function enables you to extract two 8-bit values from an operand and zero-extend them to 16 bits each.
  \param [in]    x   two 8-bit values in val[7:0] and val[23:16] to be zero-extended.
  \return        the 8-bit values sign-extended to 16-bit values.\n
                 sign-extended value of val[7:0] in the low halfword of the return value.\n
                 sign-extended value of val[23:16] in the high halfword of the return value.
  \remark
                 res[15:0]  = ZeroExtended(val[7:0])       \n
                 res[31:16] = ZeroExtended(val[23:16])
 */
__ALWAYS_INLINE uint32_t __UXTB16(uint32_t x)
{
  return ((uint32_t)((((x << 24) >> 24) & 0x0000FFFF) |
                     (((x <<  8) >>  8) & 0xFFFF0000)  ));
}
/*@} end of group CSI_SIMD_intrinsics */

#ifdef CSKY_SIMD
/* SMMLAR */
__ALWAYS_INLINE int32_t multAcc_32x32_keep32_R(int32_t a, int32_t x, int32_t y)
{
    __ASM volatile("mula.s32.rh %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y) : "0" (a), "1" (x), "2" (y));
    return a;
}

/* SMMLSR */
__ALWAYS_INLINE int32_t multSub_32x32_keep32_R(int32_t a, int32_t x, int32_t y)
{
    __ASM volatile("muls.s32.rh %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

/* SMMULR */
__ALWAYS_INLINE int32_t mult_32x32_keep32_R(int32_t x, int32_t y)
{
    int32_t a;
    __ASM volatile("mul.s32.rh %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "1" (x), "2" (y));
    return a;
}

/* SMMLA */
__ALWAYS_INLINE int32_t multAcc_32x32_keep32(int32_t a, int32_t x, int32_t y)
{
    __ASM volatile("mula.s32.h %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

/* SMMLS */
__ALWAYS_INLINE int32_t multSub_32x32_keep32(int32_t a, int32_t x, int32_t y)
{
    __ASM volatile("muls.s32.h %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

/* SMMUL */
__ALWAYS_INLINE int32_t mult_32x32_keep32(int32_t x, int32_t y)
{
    int32_t a;
    __ASM volatile("mul.s32.h %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int32_t multAcc_16x16_keep32(int32_t a, int16_t x, int16_t y)
{
    __ASM volatile("mulall.s16 %0, %1, %2, %0\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int64_t multAcc_16x16_keep64(int64_t a, int16_t x, int16_t y)
{
    __ASM volatile("mulall.s16.e %0, %R0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int64_t mult_32x32_keep64(int32_t x, int32_t y)
{
    int64_t a;
    __ASM volatile("mul.s32 %0, %R0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int64_t multAcc_32x32_keep64(int64_t a, int32_t x, int32_t y)
{
    __ASM volatile("mula.s32 %0, %R0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "0" (a), "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int32_t mult_32x32_dext_31(int32_t x, int32_t y)
{
    int64_t tmp1;
    int32_t tmp2;
    __ASM volatile("mul.s32 %0, %R0, %1, %2\n\t"
                   "dext %3, %0, %R0, 31"
                   :"=r" (tmp1), "=r" (x), "=r" (y), "=r" (tmp2): "1" (x), "2" (y));
    return tmp2;
}

__ALWAYS_INLINE int32_t mult_32x32_dext_30(int32_t x, int32_t y)
{
    int64_t tmp1;
    int32_t tmp2;
    __ASM volatile("mul.s32 %0, %R0, %1, %2\n\t"
                   "dext %3, %0, %R0, 30"
                   :"=r" (tmp1), "=r" (x), "=r" (y), "=r" (tmp2): "1" (x), "2" (y));
    return tmp2;
}

__ALWAYS_INLINE int32_t mult_32x32_dext_4(int32_t x, int32_t y)
{
    int64_t tmp1;
    int32_t tmp2;
    __ASM volatile("mul.s32 %0, %R0, %1, %2\n\t"
                   "dext %3, %0, %R0, 4"
                   :"=r" (tmp1), "=r" (x), "=r" (y), "=r" (tmp2): "1" (x), "2" (y));
    return tmp2;
}

__ALWAYS_INLINE int32_t mult_32x32_dext_33(int32_t x, int32_t y)
{
    int64_t tmp1;
    int32_t tmp2;
    __ASM volatile("mul.s32 %0, %R0, %1, %2\n\t"
                   "lsri %3, %R0, 1"
                   :"=r" (tmp1), "=r" (x), "=r" (y), "=r" (tmp2): "1" (x), "2" (y));
    return tmp2;
}

__ALWAYS_INLINE int32_t dext_31(int64_t x)
{
    int32_t tmp1;
    __ASM volatile(
                   "dext %0, %1, %R1, 31"
                   :"=r" (tmp1), "=r" (x) : "1" (x));
    return tmp1;
}

__ALWAYS_INLINE int32_t mult_l16xl16_keep32(int32_t x, int32_t y)
{
    int32_t a;
    __ASM volatile("mulll.s16 %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int32_t mult_h16xl16_keep32(int32_t x, int32_t y)
{
    int32_t a;
    __ASM volatile("mulhl.s16 %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "1" (x), "2" (y));
    return a;
}

__ALWAYS_INLINE int32_t mult_h16xh16_keep32(int32_t x, int32_t y)
{
    int32_t a;
    __ASM volatile("mulhh.s16 %0, %1, %2\n\t"
                   :"=r" (a), "=r" (x), "=r" (y): "1" (x), "2" (y));
    return a;
}
//__ALWAYS_INLINE int32_t __CLPSFTS_31(int32_t x)
//{
//    int32_t tmp1;
//    __ASM volatile(
//                   "clpsfts %0, %1, 1, 0"
//                   :"=r" (tmp1), "=r" (x) : "1" (x));
//    return tmp1;
//}

#endif

#endif /* __CSI_GCC_H */
