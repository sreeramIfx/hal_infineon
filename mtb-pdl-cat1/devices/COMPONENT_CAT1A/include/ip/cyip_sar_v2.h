/***************************************************************************//**
* \file cyip_sar_v2.h
*
* \brief
* SAR IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _CYIP_SAR_V2_H_
#define _CYIP_SAR_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     SAR
*******************************************************************************/

#define SAR_V2_SECTION_SIZE                     0x00010000UL

/**
  * \brief SAR ADC with Sequencer (SAR)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Analog control register. */
  __IOM uint32_t SAMPLE_CTRL;                   /*!< 0x00000004 Sample control register. */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t SAMPLE_TIME01;                 /*!< 0x00000010 Sample time specification ST0 and ST1 */
  __IOM uint32_t SAMPLE_TIME23;                 /*!< 0x00000014 Sample time specification ST2 and ST3 */
  __IOM uint32_t RANGE_THRES;                   /*!< 0x00000018 Global range detect threshold register. */
  __IOM uint32_t RANGE_COND;                    /*!< 0x0000001C Global range detect mode register. */
  __IOM uint32_t CHAN_EN;                       /*!< 0x00000020 Enable bits for the channels */
  __IOM uint32_t START_CTRL;                    /*!< 0x00000024 Start control register (firmware trigger). */
   __IM uint32_t RESERVED1[22];
  __IOM uint32_t CHAN_CONFIG[16];               /*!< 0x00000080 Channel configuration register. */
   __IM uint32_t RESERVED2[16];
   __IM uint32_t CHAN_WORK[16];                 /*!< 0x00000100 Channel working data register */
   __IM uint32_t RESERVED3[16];
   __IM uint32_t CHAN_RESULT[16];               /*!< 0x00000180 Channel result data register */
   __IM uint32_t RESERVED4[16];
   __IM uint32_t CHAN_WORK_UPDATED;             /*!< 0x00000200 Channel working data register 'updated' bits */
   __IM uint32_t CHAN_RESULT_UPDATED;           /*!< 0x00000204 Channel result data register 'updated' bits */
   __IM uint32_t CHAN_WORK_NEWVALUE;            /*!< 0x00000208 Channel working data register 'new value' bits */
   __IM uint32_t CHAN_RESULT_NEWVALUE;          /*!< 0x0000020C Channel result data register 'new value' bits */
  __IOM uint32_t INTR;                          /*!< 0x00000210 Interrupt request register. */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000214 Interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000218 Interrupt mask register. */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000021C Interrupt masked request register */
  __IOM uint32_t SATURATE_INTR;                 /*!< 0x00000220 Saturate interrupt request register. */
  __IOM uint32_t SATURATE_INTR_SET;             /*!< 0x00000224 Saturate interrupt set request register */
  __IOM uint32_t SATURATE_INTR_MASK;            /*!< 0x00000228 Saturate interrupt mask register. */
   __IM uint32_t SATURATE_INTR_MASKED;          /*!< 0x0000022C Saturate interrupt masked request register */
  __IOM uint32_t RANGE_INTR;                    /*!< 0x00000230 Range detect interrupt request register. */
  __IOM uint32_t RANGE_INTR_SET;                /*!< 0x00000234 Range detect interrupt set request register */
  __IOM uint32_t RANGE_INTR_MASK;               /*!< 0x00000238 Range detect interrupt mask register. */
   __IM uint32_t RANGE_INTR_MASKED;             /*!< 0x0000023C Range interrupt masked request register */
   __IM uint32_t INTR_CAUSE;                    /*!< 0x00000240 Interrupt cause register */
   __IM uint32_t RESERVED5[15];
  __IOM uint32_t INJ_CHAN_CONFIG;               /*!< 0x00000280 Injection channel configuration register. */
   __IM uint32_t RESERVED6[3];
   __IM uint32_t INJ_RESULT;                    /*!< 0x00000290 Injection channel result register */
   __IM uint32_t RESERVED7[3];
   __IM uint32_t STATUS;                        /*!< 0x000002A0 Current status of internal SAR registers (mostly for debug) */
   __IM uint32_t AVG_STAT;                      /*!< 0x000002A4 Current averaging status (for debug) */
   __IM uint32_t RESERVED8[22];
  __IOM uint32_t MUX_SWITCH0;                   /*!< 0x00000300 SARMUX Firmware switch controls */
  __IOM uint32_t MUX_SWITCH_CLEAR0;             /*!< 0x00000304 SARMUX Firmware switch control clear */
   __IM uint32_t RESERVED9[15];
  __IOM uint32_t MUX_SWITCH_SQ_CTRL;            /*!< 0x00000344 SARMUX switch Sar Sequencer control */
   __IM uint32_t MUX_SWITCH_STATUS;             /*!< 0x00000348 SARMUX switch status */
} SAR_V2_Type;                                  /*!< Size = 844 (0x34C) */


/* SAR.CTRL */
#define SAR_V2_CTRL_PWR_CTRL_VREF_Pos           0UL
#define SAR_V2_CTRL_PWR_CTRL_VREF_Msk           0x7UL
#define SAR_V2_CTRL_VREF_SEL_Pos                4UL
#define SAR_V2_CTRL_VREF_SEL_Msk                0x70UL
#define SAR_V2_CTRL_VREF_BYP_CAP_EN_Pos         7UL
#define SAR_V2_CTRL_VREF_BYP_CAP_EN_Msk         0x80UL
#define SAR_V2_CTRL_NEG_SEL_Pos                 9UL
#define SAR_V2_CTRL_NEG_SEL_Msk                 0xE00UL
#define SAR_V2_CTRL_SAR_HW_CTRL_NEGVREF_Pos     13UL
#define SAR_V2_CTRL_SAR_HW_CTRL_NEGVREF_Msk     0x2000UL
#define SAR_V2_CTRL_COMP_DLY_Pos                14UL
#define SAR_V2_CTRL_COMP_DLY_Msk                0xC000UL
#define SAR_V2_CTRL_SPARE_Pos                   16UL
#define SAR_V2_CTRL_SPARE_Msk                   0xF0000UL
#define SAR_V2_CTRL_BOOSTPUMP_EN_Pos            20UL
#define SAR_V2_CTRL_BOOSTPUMP_EN_Msk            0x100000UL
#define SAR_V2_CTRL_REFBUF_EN_Pos               21UL
#define SAR_V2_CTRL_REFBUF_EN_Msk               0x200000UL
#define SAR_V2_CTRL_COMP_PWR_Pos                24UL
#define SAR_V2_CTRL_COMP_PWR_Msk                0x7000000UL
#define SAR_V2_CTRL_DEEPSLEEP_ON_Pos            27UL
#define SAR_V2_CTRL_DEEPSLEEP_ON_Msk            0x8000000UL
#define SAR_V2_CTRL_DSI_SYNC_CONFIG_Pos         28UL
#define SAR_V2_CTRL_DSI_SYNC_CONFIG_Msk         0x10000000UL
#define SAR_V2_CTRL_DSI_MODE_Pos                29UL
#define SAR_V2_CTRL_DSI_MODE_Msk                0x20000000UL
#define SAR_V2_CTRL_SWITCH_DISABLE_Pos          30UL
#define SAR_V2_CTRL_SWITCH_DISABLE_Msk          0x40000000UL
#define SAR_V2_CTRL_ENABLED_Pos                 31UL
#define SAR_V2_CTRL_ENABLED_Msk                 0x80000000UL
/* SAR.SAMPLE_CTRL */
#define SAR_V2_SAMPLE_CTRL_LEFT_ALIGN_Pos       1UL
#define SAR_V2_SAMPLE_CTRL_LEFT_ALIGN_Msk       0x2UL
#define SAR_V2_SAMPLE_CTRL_SINGLE_ENDED_SIGNED_Pos 2UL
#define SAR_V2_SAMPLE_CTRL_SINGLE_ENDED_SIGNED_Msk 0x4UL
#define SAR_V2_SAMPLE_CTRL_DIFFERENTIAL_SIGNED_Pos 3UL
#define SAR_V2_SAMPLE_CTRL_DIFFERENTIAL_SIGNED_Msk 0x8UL
#define SAR_V2_SAMPLE_CTRL_AVG_CNT_Pos          4UL
#define SAR_V2_SAMPLE_CTRL_AVG_CNT_Msk          0x70UL
#define SAR_V2_SAMPLE_CTRL_AVG_SHIFT_Pos        7UL
#define SAR_V2_SAMPLE_CTRL_AVG_SHIFT_Msk        0x80UL
#define SAR_V2_SAMPLE_CTRL_AVG_MODE_Pos         8UL
#define SAR_V2_SAMPLE_CTRL_AVG_MODE_Msk         0x100UL
#define SAR_V2_SAMPLE_CTRL_CONTINUOUS_Pos       16UL
#define SAR_V2_SAMPLE_CTRL_CONTINUOUS_Msk       0x10000UL
#define SAR_V2_SAMPLE_CTRL_DSI_TRIGGER_EN_Pos   17UL
#define SAR_V2_SAMPLE_CTRL_DSI_TRIGGER_EN_Msk   0x20000UL
#define SAR_V2_SAMPLE_CTRL_DSI_TRIGGER_LEVEL_Pos 18UL
#define SAR_V2_SAMPLE_CTRL_DSI_TRIGGER_LEVEL_Msk 0x40000UL
#define SAR_V2_SAMPLE_CTRL_DSI_SYNC_TRIGGER_Pos 19UL
#define SAR_V2_SAMPLE_CTRL_DSI_SYNC_TRIGGER_Msk 0x80000UL
#define SAR_V2_SAMPLE_CTRL_UAB_SCAN_MODE_Pos    22UL
#define SAR_V2_SAMPLE_CTRL_UAB_SCAN_MODE_Msk    0x400000UL
#define SAR_V2_SAMPLE_CTRL_REPEAT_INVALID_Pos   23UL
#define SAR_V2_SAMPLE_CTRL_REPEAT_INVALID_Msk   0x800000UL
#define SAR_V2_SAMPLE_CTRL_VALID_SEL_Pos        24UL
#define SAR_V2_SAMPLE_CTRL_VALID_SEL_Msk        0x7000000UL
#define SAR_V2_SAMPLE_CTRL_VALID_SEL_EN_Pos     27UL
#define SAR_V2_SAMPLE_CTRL_VALID_SEL_EN_Msk     0x8000000UL
#define SAR_V2_SAMPLE_CTRL_VALID_IGNORE_Pos     28UL
#define SAR_V2_SAMPLE_CTRL_VALID_IGNORE_Msk     0x10000000UL
#define SAR_V2_SAMPLE_CTRL_TRIGGER_OUT_EN_Pos   30UL
#define SAR_V2_SAMPLE_CTRL_TRIGGER_OUT_EN_Msk   0x40000000UL
#define SAR_V2_SAMPLE_CTRL_EOS_DSI_OUT_EN_Pos   31UL
#define SAR_V2_SAMPLE_CTRL_EOS_DSI_OUT_EN_Msk   0x80000000UL
/* SAR.SAMPLE_TIME01 */
#define SAR_V2_SAMPLE_TIME01_SAMPLE_TIME0_Pos   0UL
#define SAR_V2_SAMPLE_TIME01_SAMPLE_TIME0_Msk   0x3FFUL
#define SAR_V2_SAMPLE_TIME01_SAMPLE_TIME1_Pos   16UL
#define SAR_V2_SAMPLE_TIME01_SAMPLE_TIME1_Msk   0x3FF0000UL
/* SAR.SAMPLE_TIME23 */
#define SAR_V2_SAMPLE_TIME23_SAMPLE_TIME2_Pos   0UL
#define SAR_V2_SAMPLE_TIME23_SAMPLE_TIME2_Msk   0x3FFUL
#define SAR_V2_SAMPLE_TIME23_SAMPLE_TIME3_Pos   16UL
#define SAR_V2_SAMPLE_TIME23_SAMPLE_TIME3_Msk   0x3FF0000UL
/* SAR.RANGE_THRES */
#define SAR_V2_RANGE_THRES_RANGE_LOW_Pos        0UL
#define SAR_V2_RANGE_THRES_RANGE_LOW_Msk        0xFFFFUL
#define SAR_V2_RANGE_THRES_RANGE_HIGH_Pos       16UL
#define SAR_V2_RANGE_THRES_RANGE_HIGH_Msk       0xFFFF0000UL
/* SAR.RANGE_COND */
#define SAR_V2_RANGE_COND_RANGE_COND_Pos        30UL
#define SAR_V2_RANGE_COND_RANGE_COND_Msk        0xC0000000UL
/* SAR.CHAN_EN */
#define SAR_V2_CHAN_EN_CHAN_EN_Pos              0UL
#define SAR_V2_CHAN_EN_CHAN_EN_Msk              0xFFFFUL
/* SAR.START_CTRL */
#define SAR_V2_START_CTRL_FW_TRIGGER_Pos        0UL
#define SAR_V2_START_CTRL_FW_TRIGGER_Msk        0x1UL
/* SAR.CHAN_CONFIG */
#define SAR_V2_CHAN_CONFIG_POS_PIN_ADDR_Pos     0UL
#define SAR_V2_CHAN_CONFIG_POS_PIN_ADDR_Msk     0x7UL
#define SAR_V2_CHAN_CONFIG_POS_PORT_ADDR_Pos    4UL
#define SAR_V2_CHAN_CONFIG_POS_PORT_ADDR_Msk    0x70UL
#define SAR_V2_CHAN_CONFIG_DIFFERENTIAL_EN_Pos  8UL
#define SAR_V2_CHAN_CONFIG_DIFFERENTIAL_EN_Msk  0x100UL
#define SAR_V2_CHAN_CONFIG_AVG_EN_Pos           10UL
#define SAR_V2_CHAN_CONFIG_AVG_EN_Msk           0x400UL
#define SAR_V2_CHAN_CONFIG_SAMPLE_TIME_SEL_Pos  12UL
#define SAR_V2_CHAN_CONFIG_SAMPLE_TIME_SEL_Msk  0x3000UL
#define SAR_V2_CHAN_CONFIG_NEG_PIN_ADDR_Pos     16UL
#define SAR_V2_CHAN_CONFIG_NEG_PIN_ADDR_Msk     0x70000UL
#define SAR_V2_CHAN_CONFIG_NEG_PORT_ADDR_Pos    20UL
#define SAR_V2_CHAN_CONFIG_NEG_PORT_ADDR_Msk    0x700000UL
#define SAR_V2_CHAN_CONFIG_NEG_ADDR_EN_Pos      24UL
#define SAR_V2_CHAN_CONFIG_NEG_ADDR_EN_Msk      0x1000000UL
#define SAR_V2_CHAN_CONFIG_DSI_OUT_EN_Pos       31UL
#define SAR_V2_CHAN_CONFIG_DSI_OUT_EN_Msk       0x80000000UL
/* SAR.CHAN_WORK */
#define SAR_V2_CHAN_WORK_WORK_Pos               0UL
#define SAR_V2_CHAN_WORK_WORK_Msk               0xFFFFUL
#define SAR_V2_CHAN_WORK_CHAN_WORK_NEWVALUE_MIR_Pos 27UL
#define SAR_V2_CHAN_WORK_CHAN_WORK_NEWVALUE_MIR_Msk 0x8000000UL
#define SAR_V2_CHAN_WORK_CHAN_WORK_UPDATED_MIR_Pos 31UL
#define SAR_V2_CHAN_WORK_CHAN_WORK_UPDATED_MIR_Msk 0x80000000UL
/* SAR.CHAN_RESULT */
#define SAR_V2_CHAN_RESULT_RESULT_Pos           0UL
#define SAR_V2_CHAN_RESULT_RESULT_Msk           0xFFFFUL
#define SAR_V2_CHAN_RESULT_CHAN_RESULT_NEWVALUE_MIR_Pos 27UL
#define SAR_V2_CHAN_RESULT_CHAN_RESULT_NEWVALUE_MIR_Msk 0x8000000UL
#define SAR_V2_CHAN_RESULT_SATURATE_INTR_MIR_Pos 29UL
#define SAR_V2_CHAN_RESULT_SATURATE_INTR_MIR_Msk 0x20000000UL
#define SAR_V2_CHAN_RESULT_RANGE_INTR_MIR_Pos   30UL
#define SAR_V2_CHAN_RESULT_RANGE_INTR_MIR_Msk   0x40000000UL
#define SAR_V2_CHAN_RESULT_CHAN_RESULT_UPDATED_MIR_Pos 31UL
#define SAR_V2_CHAN_RESULT_CHAN_RESULT_UPDATED_MIR_Msk 0x80000000UL
/* SAR.CHAN_WORK_UPDATED */
#define SAR_V2_CHAN_WORK_UPDATED_CHAN_WORK_UPDATED_Pos 0UL
#define SAR_V2_CHAN_WORK_UPDATED_CHAN_WORK_UPDATED_Msk 0xFFFFUL
/* SAR.CHAN_RESULT_UPDATED */
#define SAR_V2_CHAN_RESULT_UPDATED_CHAN_RESULT_UPDATED_Pos 0UL
#define SAR_V2_CHAN_RESULT_UPDATED_CHAN_RESULT_UPDATED_Msk 0xFFFFUL
/* SAR.CHAN_WORK_NEWVALUE */
#define SAR_V2_CHAN_WORK_NEWVALUE_CHAN_WORK_NEWVALUE_Pos 0UL
#define SAR_V2_CHAN_WORK_NEWVALUE_CHAN_WORK_NEWVALUE_Msk 0xFFFFUL
/* SAR.CHAN_RESULT_NEWVALUE */
#define SAR_V2_CHAN_RESULT_NEWVALUE_CHAN_RESULT_NEWVALUE_Pos 0UL
#define SAR_V2_CHAN_RESULT_NEWVALUE_CHAN_RESULT_NEWVALUE_Msk 0xFFFFUL
/* SAR.INTR */
#define SAR_V2_INTR_EOS_INTR_Pos                0UL
#define SAR_V2_INTR_EOS_INTR_Msk                0x1UL
#define SAR_V2_INTR_OVERFLOW_INTR_Pos           1UL
#define SAR_V2_INTR_OVERFLOW_INTR_Msk           0x2UL
#define SAR_V2_INTR_FW_COLLISION_INTR_Pos       2UL
#define SAR_V2_INTR_FW_COLLISION_INTR_Msk       0x4UL
#define SAR_V2_INTR_DSI_COLLISION_INTR_Pos      3UL
#define SAR_V2_INTR_DSI_COLLISION_INTR_Msk      0x8UL
#define SAR_V2_INTR_INJ_EOC_INTR_Pos            4UL
#define SAR_V2_INTR_INJ_EOC_INTR_Msk            0x10UL
#define SAR_V2_INTR_INJ_SATURATE_INTR_Pos       5UL
#define SAR_V2_INTR_INJ_SATURATE_INTR_Msk       0x20UL
#define SAR_V2_INTR_INJ_RANGE_INTR_Pos          6UL
#define SAR_V2_INTR_INJ_RANGE_INTR_Msk          0x40UL
#define SAR_V2_INTR_INJ_COLLISION_INTR_Pos      7UL
#define SAR_V2_INTR_INJ_COLLISION_INTR_Msk      0x80UL
/* SAR.INTR_SET */
#define SAR_V2_INTR_SET_EOS_SET_Pos             0UL
#define SAR_V2_INTR_SET_EOS_SET_Msk             0x1UL
#define SAR_V2_INTR_SET_OVERFLOW_SET_Pos        1UL
#define SAR_V2_INTR_SET_OVERFLOW_SET_Msk        0x2UL
#define SAR_V2_INTR_SET_FW_COLLISION_SET_Pos    2UL
#define SAR_V2_INTR_SET_FW_COLLISION_SET_Msk    0x4UL
#define SAR_V2_INTR_SET_DSI_COLLISION_SET_Pos   3UL
#define SAR_V2_INTR_SET_DSI_COLLISION_SET_Msk   0x8UL
#define SAR_V2_INTR_SET_INJ_EOC_SET_Pos         4UL
#define SAR_V2_INTR_SET_INJ_EOC_SET_Msk         0x10UL
#define SAR_V2_INTR_SET_INJ_SATURATE_SET_Pos    5UL
#define SAR_V2_INTR_SET_INJ_SATURATE_SET_Msk    0x20UL
#define SAR_V2_INTR_SET_INJ_RANGE_SET_Pos       6UL
#define SAR_V2_INTR_SET_INJ_RANGE_SET_Msk       0x40UL
#define SAR_V2_INTR_SET_INJ_COLLISION_SET_Pos   7UL
#define SAR_V2_INTR_SET_INJ_COLLISION_SET_Msk   0x80UL
/* SAR.INTR_MASK */
#define SAR_V2_INTR_MASK_EOS_MASK_Pos           0UL
#define SAR_V2_INTR_MASK_EOS_MASK_Msk           0x1UL
#define SAR_V2_INTR_MASK_OVERFLOW_MASK_Pos      1UL
#define SAR_V2_INTR_MASK_OVERFLOW_MASK_Msk      0x2UL
#define SAR_V2_INTR_MASK_FW_COLLISION_MASK_Pos  2UL
#define SAR_V2_INTR_MASK_FW_COLLISION_MASK_Msk  0x4UL
#define SAR_V2_INTR_MASK_DSI_COLLISION_MASK_Pos 3UL
#define SAR_V2_INTR_MASK_DSI_COLLISION_MASK_Msk 0x8UL
#define SAR_V2_INTR_MASK_INJ_EOC_MASK_Pos       4UL
#define SAR_V2_INTR_MASK_INJ_EOC_MASK_Msk       0x10UL
#define SAR_V2_INTR_MASK_INJ_SATURATE_MASK_Pos  5UL
#define SAR_V2_INTR_MASK_INJ_SATURATE_MASK_Msk  0x20UL
#define SAR_V2_INTR_MASK_INJ_RANGE_MASK_Pos     6UL
#define SAR_V2_INTR_MASK_INJ_RANGE_MASK_Msk     0x40UL
#define SAR_V2_INTR_MASK_INJ_COLLISION_MASK_Pos 7UL
#define SAR_V2_INTR_MASK_INJ_COLLISION_MASK_Msk 0x80UL
/* SAR.INTR_MASKED */
#define SAR_V2_INTR_MASKED_EOS_MASKED_Pos       0UL
#define SAR_V2_INTR_MASKED_EOS_MASKED_Msk       0x1UL
#define SAR_V2_INTR_MASKED_OVERFLOW_MASKED_Pos  1UL
#define SAR_V2_INTR_MASKED_OVERFLOW_MASKED_Msk  0x2UL
#define SAR_V2_INTR_MASKED_FW_COLLISION_MASKED_Pos 2UL
#define SAR_V2_INTR_MASKED_FW_COLLISION_MASKED_Msk 0x4UL
#define SAR_V2_INTR_MASKED_DSI_COLLISION_MASKED_Pos 3UL
#define SAR_V2_INTR_MASKED_DSI_COLLISION_MASKED_Msk 0x8UL
#define SAR_V2_INTR_MASKED_INJ_EOC_MASKED_Pos   4UL
#define SAR_V2_INTR_MASKED_INJ_EOC_MASKED_Msk   0x10UL
#define SAR_V2_INTR_MASKED_INJ_SATURATE_MASKED_Pos 5UL
#define SAR_V2_INTR_MASKED_INJ_SATURATE_MASKED_Msk 0x20UL
#define SAR_V2_INTR_MASKED_INJ_RANGE_MASKED_Pos 6UL
#define SAR_V2_INTR_MASKED_INJ_RANGE_MASKED_Msk 0x40UL
#define SAR_V2_INTR_MASKED_INJ_COLLISION_MASKED_Pos 7UL
#define SAR_V2_INTR_MASKED_INJ_COLLISION_MASKED_Msk 0x80UL
/* SAR.SATURATE_INTR */
#define SAR_V2_SATURATE_INTR_SATURATE_INTR_Pos  0UL
#define SAR_V2_SATURATE_INTR_SATURATE_INTR_Msk  0xFFFFUL
/* SAR.SATURATE_INTR_SET */
#define SAR_V2_SATURATE_INTR_SET_SATURATE_SET_Pos 0UL
#define SAR_V2_SATURATE_INTR_SET_SATURATE_SET_Msk 0xFFFFUL
/* SAR.SATURATE_INTR_MASK */
#define SAR_V2_SATURATE_INTR_MASK_SATURATE_MASK_Pos 0UL
#define SAR_V2_SATURATE_INTR_MASK_SATURATE_MASK_Msk 0xFFFFUL
/* SAR.SATURATE_INTR_MASKED */
#define SAR_V2_SATURATE_INTR_MASKED_SATURATE_MASKED_Pos 0UL
#define SAR_V2_SATURATE_INTR_MASKED_SATURATE_MASKED_Msk 0xFFFFUL
/* SAR.RANGE_INTR */
#define SAR_V2_RANGE_INTR_RANGE_INTR_Pos        0UL
#define SAR_V2_RANGE_INTR_RANGE_INTR_Msk        0xFFFFUL
/* SAR.RANGE_INTR_SET */
#define SAR_V2_RANGE_INTR_SET_RANGE_SET_Pos     0UL
#define SAR_V2_RANGE_INTR_SET_RANGE_SET_Msk     0xFFFFUL
/* SAR.RANGE_INTR_MASK */
#define SAR_V2_RANGE_INTR_MASK_RANGE_MASK_Pos   0UL
#define SAR_V2_RANGE_INTR_MASK_RANGE_MASK_Msk   0xFFFFUL
/* SAR.RANGE_INTR_MASKED */
#define SAR_V2_RANGE_INTR_MASKED_RANGE_MASKED_Pos 0UL
#define SAR_V2_RANGE_INTR_MASKED_RANGE_MASKED_Msk 0xFFFFUL
/* SAR.INTR_CAUSE */
#define SAR_V2_INTR_CAUSE_EOS_MASKED_MIR_Pos    0UL
#define SAR_V2_INTR_CAUSE_EOS_MASKED_MIR_Msk    0x1UL
#define SAR_V2_INTR_CAUSE_OVERFLOW_MASKED_MIR_Pos 1UL
#define SAR_V2_INTR_CAUSE_OVERFLOW_MASKED_MIR_Msk 0x2UL
#define SAR_V2_INTR_CAUSE_FW_COLLISION_MASKED_MIR_Pos 2UL
#define SAR_V2_INTR_CAUSE_FW_COLLISION_MASKED_MIR_Msk 0x4UL
#define SAR_V2_INTR_CAUSE_DSI_COLLISION_MASKED_MIR_Pos 3UL
#define SAR_V2_INTR_CAUSE_DSI_COLLISION_MASKED_MIR_Msk 0x8UL
#define SAR_V2_INTR_CAUSE_INJ_EOC_MASKED_MIR_Pos 4UL
#define SAR_V2_INTR_CAUSE_INJ_EOC_MASKED_MIR_Msk 0x10UL
#define SAR_V2_INTR_CAUSE_INJ_SATURATE_MASKED_MIR_Pos 5UL
#define SAR_V2_INTR_CAUSE_INJ_SATURATE_MASKED_MIR_Msk 0x20UL
#define SAR_V2_INTR_CAUSE_INJ_RANGE_MASKED_MIR_Pos 6UL
#define SAR_V2_INTR_CAUSE_INJ_RANGE_MASKED_MIR_Msk 0x40UL
#define SAR_V2_INTR_CAUSE_INJ_COLLISION_MASKED_MIR_Pos 7UL
#define SAR_V2_INTR_CAUSE_INJ_COLLISION_MASKED_MIR_Msk 0x80UL
#define SAR_V2_INTR_CAUSE_SATURATE_MASKED_RED_Pos 30UL
#define SAR_V2_INTR_CAUSE_SATURATE_MASKED_RED_Msk 0x40000000UL
#define SAR_V2_INTR_CAUSE_RANGE_MASKED_RED_Pos  31UL
#define SAR_V2_INTR_CAUSE_RANGE_MASKED_RED_Msk  0x80000000UL
/* SAR.INJ_CHAN_CONFIG */
#define SAR_V2_INJ_CHAN_CONFIG_INJ_PIN_ADDR_Pos 0UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_PIN_ADDR_Msk 0x7UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_PORT_ADDR_Pos 4UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_PORT_ADDR_Msk 0x70UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_DIFFERENTIAL_EN_Pos 8UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_DIFFERENTIAL_EN_Msk 0x100UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_AVG_EN_Pos   10UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_AVG_EN_Msk   0x400UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_SAMPLE_TIME_SEL_Pos 12UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_SAMPLE_TIME_SEL_Msk 0x3000UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_TAILGATING_Pos 30UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_TAILGATING_Msk 0x40000000UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_START_EN_Pos 31UL
#define SAR_V2_INJ_CHAN_CONFIG_INJ_START_EN_Msk 0x80000000UL
/* SAR.INJ_RESULT */
#define SAR_V2_INJ_RESULT_INJ_RESULT_Pos        0UL
#define SAR_V2_INJ_RESULT_INJ_RESULT_Msk        0xFFFFUL
#define SAR_V2_INJ_RESULT_INJ_NEWVALUE_Pos      27UL
#define SAR_V2_INJ_RESULT_INJ_NEWVALUE_Msk      0x8000000UL
#define SAR_V2_INJ_RESULT_INJ_COLLISION_INTR_MIR_Pos 28UL
#define SAR_V2_INJ_RESULT_INJ_COLLISION_INTR_MIR_Msk 0x10000000UL
#define SAR_V2_INJ_RESULT_INJ_SATURATE_INTR_MIR_Pos 29UL
#define SAR_V2_INJ_RESULT_INJ_SATURATE_INTR_MIR_Msk 0x20000000UL
#define SAR_V2_INJ_RESULT_INJ_RANGE_INTR_MIR_Pos 30UL
#define SAR_V2_INJ_RESULT_INJ_RANGE_INTR_MIR_Msk 0x40000000UL
#define SAR_V2_INJ_RESULT_INJ_EOC_INTR_MIR_Pos  31UL
#define SAR_V2_INJ_RESULT_INJ_EOC_INTR_MIR_Msk  0x80000000UL
/* SAR.STATUS */
#define SAR_V2_STATUS_CUR_CHAN_Pos              0UL
#define SAR_V2_STATUS_CUR_CHAN_Msk              0x1FUL
#define SAR_V2_STATUS_SW_VREF_NEG_Pos           30UL
#define SAR_V2_STATUS_SW_VREF_NEG_Msk           0x40000000UL
#define SAR_V2_STATUS_BUSY_Pos                  31UL
#define SAR_V2_STATUS_BUSY_Msk                  0x80000000UL
/* SAR.AVG_STAT */
#define SAR_V2_AVG_STAT_CUR_AVG_ACCU_Pos        0UL
#define SAR_V2_AVG_STAT_CUR_AVG_ACCU_Msk        0xFFFFFUL
#define SAR_V2_AVG_STAT_INTRLV_BUSY_Pos         23UL
#define SAR_V2_AVG_STAT_INTRLV_BUSY_Msk         0x800000UL
#define SAR_V2_AVG_STAT_CUR_AVG_CNT_Pos         24UL
#define SAR_V2_AVG_STAT_CUR_AVG_CNT_Msk         0xFF000000UL
/* SAR.MUX_SWITCH0 */
#define SAR_V2_MUX_SWITCH0_MUX_FW_P0_VPLUS_Pos  0UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P0_VPLUS_Msk  0x1UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P1_VPLUS_Pos  1UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P1_VPLUS_Msk  0x2UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P2_VPLUS_Pos  2UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P2_VPLUS_Msk  0x4UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P3_VPLUS_Pos  3UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P3_VPLUS_Msk  0x8UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P4_VPLUS_Pos  4UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P4_VPLUS_Msk  0x10UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P5_VPLUS_Pos  5UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P5_VPLUS_Msk  0x20UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P6_VPLUS_Pos  6UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P6_VPLUS_Msk  0x40UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P7_VPLUS_Pos  7UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P7_VPLUS_Msk  0x80UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P0_VMINUS_Pos 8UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P0_VMINUS_Msk 0x100UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P1_VMINUS_Pos 9UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P1_VMINUS_Msk 0x200UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P2_VMINUS_Pos 10UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P2_VMINUS_Msk 0x400UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P3_VMINUS_Pos 11UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P3_VMINUS_Msk 0x800UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P4_VMINUS_Pos 12UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P4_VMINUS_Msk 0x1000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P5_VMINUS_Pos 13UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P5_VMINUS_Msk 0x2000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P6_VMINUS_Pos 14UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P6_VMINUS_Msk 0x4000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P7_VMINUS_Pos 15UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P7_VMINUS_Msk 0x8000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_VSSA_VMINUS_Pos 16UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_VSSA_VMINUS_Msk 0x10000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_TEMP_VPLUS_Pos 17UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_TEMP_VPLUS_Msk 0x20000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSA_VPLUS_Pos 18UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSA_VPLUS_Msk 0x40000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSB_VPLUS_Pos 19UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSB_VPLUS_Msk 0x80000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSA_VMINUS_Pos 20UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSA_VMINUS_Msk 0x100000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSB_VMINUS_Pos 21UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_AMUXBUSB_VMINUS_Msk 0x200000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS0_VPLUS_Pos 22UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS0_VPLUS_Msk 0x400000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS1_VPLUS_Pos 23UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS1_VPLUS_Msk 0x800000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS0_VMINUS_Pos 24UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS0_VMINUS_Msk 0x1000000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS1_VMINUS_Pos 25UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_SARBUS1_VMINUS_Msk 0x2000000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P4_COREIO0_Pos 26UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P4_COREIO0_Msk 0x4000000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P5_COREIO1_Pos 27UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P5_COREIO1_Msk 0x8000000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P6_COREIO2_Pos 28UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P6_COREIO2_Msk 0x10000000UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P7_COREIO3_Pos 29UL
#define SAR_V2_MUX_SWITCH0_MUX_FW_P7_COREIO3_Msk 0x20000000UL
/* SAR.MUX_SWITCH_CLEAR0 */
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P0_VPLUS_Pos 0UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P0_VPLUS_Msk 0x1UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P1_VPLUS_Pos 1UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P1_VPLUS_Msk 0x2UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P2_VPLUS_Pos 2UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P2_VPLUS_Msk 0x4UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P3_VPLUS_Pos 3UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P3_VPLUS_Msk 0x8UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P4_VPLUS_Pos 4UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P4_VPLUS_Msk 0x10UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P5_VPLUS_Pos 5UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P5_VPLUS_Msk 0x20UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P6_VPLUS_Pos 6UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P6_VPLUS_Msk 0x40UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P7_VPLUS_Pos 7UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P7_VPLUS_Msk 0x80UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P0_VMINUS_Pos 8UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P0_VMINUS_Msk 0x100UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P1_VMINUS_Pos 9UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P1_VMINUS_Msk 0x200UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P2_VMINUS_Pos 10UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P2_VMINUS_Msk 0x400UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P3_VMINUS_Pos 11UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P3_VMINUS_Msk 0x800UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P4_VMINUS_Pos 12UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P4_VMINUS_Msk 0x1000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P5_VMINUS_Pos 13UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P5_VMINUS_Msk 0x2000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P6_VMINUS_Pos 14UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P6_VMINUS_Msk 0x4000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P7_VMINUS_Pos 15UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P7_VMINUS_Msk 0x8000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_VSSA_VMINUS_Pos 16UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_VSSA_VMINUS_Msk 0x10000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_TEMP_VPLUS_Pos 17UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_TEMP_VPLUS_Msk 0x20000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSA_VPLUS_Pos 18UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSA_VPLUS_Msk 0x40000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSB_VPLUS_Pos 19UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSB_VPLUS_Msk 0x80000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSA_VMINUS_Pos 20UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSA_VMINUS_Msk 0x100000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSB_VMINUS_Pos 21UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_AMUXBUSB_VMINUS_Msk 0x200000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS0_VPLUS_Pos 22UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS0_VPLUS_Msk 0x400000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS1_VPLUS_Pos 23UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS1_VPLUS_Msk 0x800000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS0_VMINUS_Pos 24UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS0_VMINUS_Msk 0x1000000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS1_VMINUS_Pos 25UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_SARBUS1_VMINUS_Msk 0x2000000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P4_COREIO0_Pos 26UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P4_COREIO0_Msk 0x4000000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P5_COREIO1_Pos 27UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P5_COREIO1_Msk 0x8000000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P6_COREIO2_Pos 28UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P6_COREIO2_Msk 0x10000000UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P7_COREIO3_Pos 29UL
#define SAR_V2_MUX_SWITCH_CLEAR0_MUX_FW_P7_COREIO3_Msk 0x20000000UL
/* SAR.MUX_SWITCH_SQ_CTRL */
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P0_Pos 0UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P0_Msk 0x1UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P1_Pos 1UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P1_Msk 0x2UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P2_Pos 2UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P2_Msk 0x4UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P3_Pos 3UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P3_Msk 0x8UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P4_Pos 4UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P4_Msk 0x10UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P5_Pos 5UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P5_Msk 0x20UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P6_Pos 6UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P6_Msk 0x40UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P7_Pos 7UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P7_Msk 0x80UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_VSSA_Pos 16UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_VSSA_Msk 0x10000UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_TEMP_Pos 17UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_TEMP_Msk 0x20000UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_AMUXBUSA_Pos 18UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_AMUXBUSA_Msk 0x40000UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_AMUXBUSB_Pos 19UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_AMUXBUSB_Msk 0x80000UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_SARBUS0_Pos 22UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_SARBUS0_Msk 0x400000UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_SARBUS1_Pos 23UL
#define SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_SARBUS1_Msk 0x800000UL
/* SAR.MUX_SWITCH_STATUS */
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P0_VPLUS_Pos 0UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P0_VPLUS_Msk 0x1UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P1_VPLUS_Pos 1UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P1_VPLUS_Msk 0x2UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P2_VPLUS_Pos 2UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P2_VPLUS_Msk 0x4UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P3_VPLUS_Pos 3UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P3_VPLUS_Msk 0x8UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P4_VPLUS_Pos 4UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P4_VPLUS_Msk 0x10UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P5_VPLUS_Pos 5UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P5_VPLUS_Msk 0x20UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P6_VPLUS_Pos 6UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P6_VPLUS_Msk 0x40UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P7_VPLUS_Pos 7UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P7_VPLUS_Msk 0x80UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P0_VMINUS_Pos 8UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P0_VMINUS_Msk 0x100UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P1_VMINUS_Pos 9UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P1_VMINUS_Msk 0x200UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P2_VMINUS_Pos 10UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P2_VMINUS_Msk 0x400UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P3_VMINUS_Pos 11UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P3_VMINUS_Msk 0x800UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P4_VMINUS_Pos 12UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P4_VMINUS_Msk 0x1000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P5_VMINUS_Pos 13UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P5_VMINUS_Msk 0x2000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P6_VMINUS_Pos 14UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P6_VMINUS_Msk 0x4000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P7_VMINUS_Pos 15UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_P7_VMINUS_Msk 0x8000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_VSSA_VMINUS_Pos 16UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_VSSA_VMINUS_Msk 0x10000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_TEMP_VPLUS_Pos 17UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_TEMP_VPLUS_Msk 0x20000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSA_VPLUS_Pos 18UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSA_VPLUS_Msk 0x40000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSB_VPLUS_Pos 19UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSB_VPLUS_Msk 0x80000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSA_VMINUS_Pos 20UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSA_VMINUS_Msk 0x100000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSB_VMINUS_Pos 21UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_AMUXBUSB_VMINUS_Msk 0x200000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS0_VPLUS_Pos 22UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS0_VPLUS_Msk 0x400000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS1_VPLUS_Pos 23UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS1_VPLUS_Msk 0x800000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS0_VMINUS_Pos 24UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS0_VMINUS_Msk 0x1000000UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS1_VMINUS_Pos 25UL
#define SAR_V2_MUX_SWITCH_STATUS_MUX_FW_SARBUS1_VMINUS_Msk 0x2000000UL


#endif /* _CYIP_SAR_V2_H_ */


/* [] END OF FILE */
