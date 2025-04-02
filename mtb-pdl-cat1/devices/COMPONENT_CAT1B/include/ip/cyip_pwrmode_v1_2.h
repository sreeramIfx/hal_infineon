/***************************************************************************//**
* \file cyip_pwrmode_v1_2.h
*
* \brief
* PWRMODE IP definitions
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

#ifndef _CYIP_PWRMODE_V1_2_H_
#define _CYIP_PWRMODE_V1_2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   PWRMODE
*******************************************************************************/

#define PWRMODE_PD_SECTION_SIZE                 0x00000010UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_SECTION_SIZE  0x00001000UL
#define PWRMODE_PPU_MAIN_SECTION_SIZE           0x00001000UL
#define PWRMODE_SECTION_SIZE                    0x00010000UL

/**
  * \brief Power Domain Dependency Sense Register (PWRMODE_PD)
  */
typedef struct {
  __IOM uint32_t PD_SENSE;                      /*!< 0x00000000 Dependency Sense Register */
   __IM uint32_t PD_SPT;                        /*!< 0x00000004 Dependency Support Register */
   __IM uint32_t RESERVED[2];
} PWRMODE_PD_Type;                              /*!< Size = 16 (0x10) */

/**
  * \brief Power Policy Unit Registers for the main power domain (VCCACT_PD) (PWRMODE_PPU_MAIN_PPU_MAIN)
  */
typedef struct {
  __IOM uint32_t PWPR;                          /*!< 0x00000000 Power Policy Register */
  __IOM uint32_t PMER;                          /*!< 0x00000004 Power Mode Emulation Register */
   __IM uint32_t PWSR;                          /*!< 0x00000008 Power Status Register */
   __IM uint32_t RESERVED;
   __IM uint32_t DISR;                          /*!< 0x00000010 Device Interface Input Current Status Register */
   __IM uint32_t MISR;                          /*!< 0x00000014 Miscellaneous Input Current Status Register */
   __IM uint32_t STSR;                          /*!< 0x00000018 Stored Status Register */
  __IOM uint32_t UNLK;                          /*!< 0x0000001C Unlock register */
  __IOM uint32_t PWCR;                          /*!< 0x00000020 Power Configuration Register */
  __IOM uint32_t PTCR;                          /*!< 0x00000024 Power Mode Transition Configuration Register */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t IMR;                           /*!< 0x00000030 Interrupt Mask Register */
  __IOM uint32_t AIMR;                          /*!< 0x00000034 Additional Interrupt Mask Register */
  __IOM uint32_t ISR;                           /*!< 0x00000038 Interrupt Status Register */
  __IOM uint32_t AISR;                          /*!< 0x0000003C Additional Interrupt Status Register */
  __IOM uint32_t IESR;                          /*!< 0x00000040 Input Edge Sensitivity Register */
  __IOM uint32_t OPSR;                          /*!< 0x00000044 Operating Mode Active Edge Sensitivity Register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t FUNRR;                         /*!< 0x00000050 Functional Retention RAM Configuration Register */
  __IOM uint32_t FULRR;                         /*!< 0x00000054 Full Retention RAM Configuration Register */
  __IOM uint32_t MEMRR;                         /*!< 0x00000058 Memory Retention RAM Configuration Register */
   __IM uint32_t RESERVED3[65];
  __IOM uint32_t EDTR0;                         /*!< 0x00000160 Power Mode Entry Delay Register 0 */
  __IOM uint32_t EDTR1;                         /*!< 0x00000164 Power Mode Entry Delay Register 1 */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t DCDR0;                         /*!< 0x00000170 Device Control Delay Configuration Register 0 */
   __IM uint32_t DCDR1;                         /*!< 0x00000174 Device Control Delay Configuration Register 1 */
   __IM uint32_t RESERVED5[910];
   __IM uint32_t IDR0;                          /*!< 0x00000FB0 PPU Identification Register 0 */
   __IM uint32_t IDR1;                          /*!< 0x00000FB4 PPU Identification Register 1 */
   __IM uint32_t RESERVED6[4];
   __IM uint32_t IIDR;                          /*!< 0x00000FC8 Implementation Identification Register */
   __IM uint32_t AIDR;                          /*!< 0x00000FCC Architecture Identification Register */
   __IM uint32_t RESERVED7[12];
} PWRMODE_PPU_MAIN_PPU_MAIN_Type;               /*!< Size = 4096 (0x1000) */

/**
  * \brief Power Policy Unit for Active Domain (PWRMODE_PPU_MAIN)
  */
typedef struct {
        PWRMODE_PPU_MAIN_PPU_MAIN_Type PPU_MAIN; /*!< 0x00000000 Power Policy Unit Registers for the main power domain
                                                                (VCCACT_PD) */
} PWRMODE_PPU_MAIN_Type;                        /*!< Size = 4096 (0x1000) */

/**
  * \brief SRSS Power Mode Control Registers (PWRMODE)
  */
typedef struct {
        PWRMODE_PD_Type PD[16];                 /*!< 0x00000000 Power Domain Dependency Sense Register */
   __IM uint32_t RESERVED[960];
        PWRMODE_PPU_MAIN_Type PPU_MAIN;         /*!< 0x00001000 Power Policy Unit for Active Domain */
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00002000 Clock Selection for Power Mode Components */
} PWRMODE_Type;                                 /*!< Size = 8196 (0x2004) */


/* PWRMODE_PD.PD_SENSE */
#define PWRMODE_PD_PD_SENSE_PD_ON_Pos           0UL
#define PWRMODE_PD_PD_SENSE_PD_ON_Msk           0xFFFFUL
/* PWRMODE_PD.PD_SPT */
#define PWRMODE_PD_PD_SPT_PD_FORCE_ON_Pos       0UL
#define PWRMODE_PD_PD_SPT_PD_FORCE_ON_Msk       0xFFFFUL
#define PWRMODE_PD_PD_SPT_PD_CONFIG_ON_Pos      16UL
#define PWRMODE_PD_PD_SPT_PD_CONFIG_ON_Msk      0xFFFF0000UL


/* PWRMODE_PPU_MAIN_PPU_MAIN.PWPR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_PWR_POLICY_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_PWR_POLICY_Msk 0xFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_PWR_DYN_EN_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_PWR_DYN_EN_Msk 0x100UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_LOCK_EN_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_LOCK_EN_Msk 0x1000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_OP_POLICY_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_OP_POLICY_Msk 0xF0000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_OP_DYN_EN_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWPR_OP_DYN_EN_Msk 0x1000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.PMER */
#define PWRMODE_PPU_MAIN_PPU_MAIN_PMER_EMU_EN_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PMER_EMU_EN_Msk 0x1UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.PWSR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_PWR_STATUS_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_PWR_STATUS_Msk 0xFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_PWR_DYN_STATUS_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_PWR_DYN_STATUS_Msk 0x100UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_LOCK_STATUS_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_LOCK_STATUS_Msk 0x1000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_OP_STATUS_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_OP_STATUS_Msk 0xF0000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_OP_DYN_STATUS_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWSR_OP_DYN_STATUS_Msk 0x1000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.DISR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_DISR_PWR_DEVACTIVE_STATUS_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DISR_PWR_DEVACTIVE_STATUS_Msk 0x7FFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DISR_OP_DEVACTIVE_STATUS_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DISR_OP_DEVACTIVE_STATUS_Msk 0xFF000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.MISR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_MISR_PCSMPACCEPT_STATUS_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_MISR_PCSMPACCEPT_STATUS_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_MISR_DEVACCEPT_STATUS_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_MISR_DEVACCEPT_STATUS_Msk 0xFF00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_MISR_DEVDENY_STATUS_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_MISR_DEVDENY_STATUS_Msk 0xFF0000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.STSR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_STSR_STORED_DEVDENY_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_STSR_STORED_DEVDENY_Msk 0xFFUL
/* PWRMODE_PPU_MAIN_PPU_MAIN.UNLK */
#define PWRMODE_PPU_MAIN_PPU_MAIN_UNLK_UNLOCK_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_UNLK_UNLOCK_Msk 0x1UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.PWCR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWCR_DEVREQEN_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWCR_DEVREQEN_Msk 0xFFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWCR_PWR_DEVACTIVEEN_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWCR_PWR_DEVACTIVEEN_Msk 0x7FF00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWCR_OP_DEVACTIVEEN_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PWCR_OP_DEVACTIVEEN_Msk 0xFF000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.PTCR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_PTCR_WARM_RST_DEVREQEN_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PTCR_WARM_RST_DEVREQEN_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PTCR_DBG_RECOV_PORST_EN_Pos 1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_PTCR_DBG_RECOV_PORST_EN_Msk 0x2UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.IMR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_STA_POLICY_TRN_IRQ_MASK_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_STA_POLICY_TRN_IRQ_MASK_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_STA_ACCEPT_IRQ_MASK_Pos 1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_STA_ACCEPT_IRQ_MASK_Msk 0x2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_STA_DENY_IRQ_MASK_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_STA_DENY_IRQ_MASK_Msk 0x4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_EMU_ACCEPT_IRQ_MASK_Pos 3UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_EMU_ACCEPT_IRQ_MASK_Msk 0x8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_EMU_DENY_IRQ_MASK_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_EMU_DENY_IRQ_MASK_Msk 0x10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_LOCKED_IRQ_MASK_Pos 5UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IMR_LOCKED_IRQ_MASK_Msk 0x20UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.AIMR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_UNSPT_POLICY_IRQ_MASK_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_UNSPT_POLICY_IRQ_MASK_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_DYN_ACCEPT_IRQ_MASK_Pos 1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_DYN_ACCEPT_IRQ_MASK_Msk 0x2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_DYN_DENY_IRQ_MASK_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_DYN_DENY_IRQ_MASK_Msk 0x4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_STA_POLICY_PWR_IRQ_MASK_Pos 3UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_STA_POLICY_PWR_IRQ_MASK_Msk 0x8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_STA_POLICY_OP_IRQ_MASK_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIMR_STA_POLICY_OP_IRQ_MASK_Msk 0x10UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.ISR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_STA_POLICY_TRN_IRQ_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_STA_POLICY_TRN_IRQ_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_STA_ACCEPT_IRQ_Pos 1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_STA_ACCEPT_IRQ_Msk 0x2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_STA_DENY_IRQ_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_STA_DENY_IRQ_Msk 0x4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_EMU_ACCEPT_IRQ_Pos 3UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_EMU_ACCEPT_IRQ_Msk 0x8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_EMU_DENY_IRQ_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_EMU_DENY_IRQ_Msk 0x10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_LOCKED_IRQ_Pos 5UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_LOCKED_IRQ_Msk 0x20UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_OTHER_IRQ_Pos 7UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_OTHER_IRQ_Msk 0x80UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_PWR_ACTIVE_EDGE_IRQ_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_PWR_ACTIVE_EDGE_IRQ_Msk 0x7FF00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_OP_ACTIVE_EDGE_IRQ_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_ISR_OP_ACTIVE_EDGE_IRQ_Msk 0xFF000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.AISR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_UNSPT_POLICY_IRQ_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_UNSPT_POLICY_IRQ_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_DYN_ACCEPT_IRQ_Pos 1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_DYN_ACCEPT_IRQ_Msk 0x2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_DYN_DENY_IRQ_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_DYN_DENY_IRQ_Msk 0x4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_STA_POLICY_PWR_IRQ_Pos 3UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_STA_POLICY_PWR_IRQ_Msk 0x8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_STA_POLICY_OP_IRQ_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AISR_STA_POLICY_OP_IRQ_Msk 0x10UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.IESR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE00_EDGE_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE00_EDGE_Msk 0x3UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE01_EDGE_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE01_EDGE_Msk 0xCUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE02_EDGE_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE02_EDGE_Msk 0x30UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE03_EDGE_Pos 6UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE03_EDGE_Msk 0xC0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE04_EDGE_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE04_EDGE_Msk 0x300UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE05_EDGE_Pos 10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE05_EDGE_Msk 0xC00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE06_EDGE_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE06_EDGE_Msk 0x3000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE07_EDGE_Pos 14UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE07_EDGE_Msk 0xC000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE08_EDGE_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE08_EDGE_Msk 0x30000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE09_EDGE_Pos 18UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE09_EDGE_Msk 0xC0000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE10_EDGE_Pos 20UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IESR_DEVACTIVE10_EDGE_Msk 0x300000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.OPSR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE16_EDGE_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE16_EDGE_Msk 0x3UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE17_EDGE_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE17_EDGE_Msk 0xCUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE18_EDGE_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE18_EDGE_Msk 0x30UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE19_EDGE_Pos 6UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE19_EDGE_Msk 0xC0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE20_EDGE_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE20_EDGE_Msk 0x300UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE21_EDGE_Pos 10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE21_EDGE_Msk 0xC00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE22_EDGE_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE22_EDGE_Msk 0x3000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE23_EDGE_Pos 14UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_OPSR_DEVACTIVE23_EDGE_Msk 0xC000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.FUNRR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_FUNRR_FUNC_RET_RAM_CFG_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_FUNRR_FUNC_RET_RAM_CFG_Msk 0xFFUL
/* PWRMODE_PPU_MAIN_PPU_MAIN.FULRR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_FULRR_FULL_RET_RAM_CFG_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_FULRR_FULL_RET_RAM_CFG_Msk 0xFFUL
/* PWRMODE_PPU_MAIN_PPU_MAIN.MEMRR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_MEMRR_MEM_RET_RAM_CFG_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_MEMRR_MEM_RET_RAM_CFG_Msk 0xFFUL
/* PWRMODE_PPU_MAIN_PPU_MAIN.EDTR0 */
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_OFF_DEL_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_OFF_DEL_Msk 0xFFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_MEM_RET_DEL_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_MEM_RET_DEL_Msk 0xFF00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_LOGIC_RET_DEL_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_LOGIC_RET_DEL_Msk 0xFF0000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_FULL_RET_DEL_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR0_FULL_RET_DEL_Msk 0xFF000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.EDTR1 */
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR1_MEM_OFF_DEL_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR1_MEM_OFF_DEL_Msk 0xFFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR1_FUNC_RET_DEL_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_EDTR1_FUNC_RET_DEL_Msk 0xFF00UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.DCDR0 */
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR0_CLKEN_RST_DLY_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR0_CLKEN_RST_DLY_Msk 0xFFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR0_ISO_CLKEN_DLY_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR0_ISO_CLKEN_DLY_Msk 0xFF00UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR0_RST_HWSTAT_DLY_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR0_RST_HWSTAT_DLY_Msk 0xFF0000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.DCDR1 */
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR1_ISO_RST_DLY_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR1_ISO_RST_DLY_Msk 0xFFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR1_CLKEN_ISO_DLY_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_DCDR1_CLKEN_ISO_DLY_Msk 0xFF00UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.IDR0 */
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DEVCHAN_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DEVCHAN_Msk 0xFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_NUM_OPMODE_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_NUM_OPMODE_Msk 0xF0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_OFF_SPT_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_OFF_SPT_Msk 0x100UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_OFF_EMU_SPT_Pos 9UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_OFF_EMU_SPT_Msk 0x200UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_MEM_RET_SPT_Pos 10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_MEM_RET_SPT_Msk 0x400UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_MEM_RET_EMU_SPT_Pos 11UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_MEM_RET_EMU_SPT_Msk 0x800UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_LGC_RET_SPT_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_LGC_RET_SPT_Msk 0x1000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_MEM_OFF_SPT_Pos 13UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_MEM_OFF_SPT_Msk 0x2000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_FULL_RET_SPT_Pos 14UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_FULL_RET_SPT_Msk 0x4000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_FUNC_RET_SPT_Pos 15UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_FUNC_RET_SPT_Msk 0x8000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_ON_SPT_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_ON_SPT_Msk 0x10000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_WRM_RST_SPT_Pos 17UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_WRM_RST_SPT_Msk 0x20000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_DBG_RECOV_SPT_Pos 18UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_STA_DBG_RECOV_SPT_Msk 0x40000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_OFF_SPT_Pos 20UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_OFF_SPT_Msk 0x100000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_OFF_EMU_SPT_Pos 21UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_OFF_EMU_SPT_Msk 0x200000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_MEM_RET_SPT_Pos 22UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_MEM_RET_SPT_Msk 0x400000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_MEM_RET_EMU_SPT_Pos 23UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_MEM_RET_EMU_SPT_Msk 0x800000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_LGC_RET_SPT_Pos 24UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_LGC_RET_SPT_Msk 0x1000000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_MEM_OFF_SPT_Pos 25UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_MEM_OFF_SPT_Msk 0x2000000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_FULL_RET_SPT_Pos 26UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_FULL_RET_SPT_Msk 0x4000000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_FUNC_RET_SPT_Pos 27UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_FUNC_RET_SPT_Msk 0x8000000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_ON_SPT_Pos 28UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_ON_SPT_Msk 0x10000000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_WRM_RST_SPT_Pos 29UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR0_DYN_WRM_RST_SPT_Msk 0x20000000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.IDR1 */
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_PWR_MODE_ENTRY_DEL_SPT_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_PWR_MODE_ENTRY_DEL_SPT_Msk 0x1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_SW_DEV_DEL_SPT_Pos 1UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_SW_DEV_DEL_SPT_Msk 0x2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_LOCK_SPT_Pos 2UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_LOCK_SPT_Msk 0x4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_MEM_RET_RAM_REG_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_MEM_RET_RAM_REG_Msk 0x10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_FULL_RET_RAM_REG_Pos 5UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_FULL_RET_RAM_REG_Msk 0x20UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_FUNC_RET_RAM_REG_Pos 6UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_FUNC_RET_RAM_REG_Msk 0x40UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_STA_POLICY_PWR_IRQ_SPT_Pos 8UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_STA_POLICY_PWR_IRQ_SPT_Msk 0x100UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_STA_POLICY_OP_IRQ_SPT_Pos 9UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_STA_POLICY_OP_IRQ_SPT_Msk 0x200UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_OP_ACTIVE_Pos 10UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_OP_ACTIVE_Msk 0x400UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_OFF_MEM_RET_TRANS_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IDR1_OFF_MEM_RET_TRANS_Msk 0x1000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.IIDR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_IMPLEMENTER_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_IMPLEMENTER_Msk 0xFFFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_REVISION_Pos 12UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_REVISION_Msk 0xF000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_VARIANT_Pos 16UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_VARIANT_Msk 0xF0000UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_PRODUCT_ID_Pos 20UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_IIDR_PRODUCT_ID_Msk 0xFFF00000UL
/* PWRMODE_PPU_MAIN_PPU_MAIN.AIDR */
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIDR_ARCH_REV_MINOR_Pos 0UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIDR_ARCH_REV_MINOR_Msk 0xFUL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIDR_ARCH_REV_MAJOR_Pos 4UL
#define PWRMODE_PPU_MAIN_PPU_MAIN_AIDR_ARCH_REV_MAJOR_Msk 0xF0UL


/* PWRMODE.CLK_SELECT */
#define PWRMODE_CLK_SELECT_CLK_PWR_DIV_Pos      0UL
#define PWRMODE_CLK_SELECT_CLK_PWR_DIV_Msk      0xFFUL
#define PWRMODE_CLK_SELECT_CLK_PWR_MUX_Pos      16UL
#define PWRMODE_CLK_SELECT_CLK_PWR_MUX_Msk      0x30000UL


#endif /* _CYIP_PWRMODE_V1_2_H_ */


/* [] END OF FILE */
