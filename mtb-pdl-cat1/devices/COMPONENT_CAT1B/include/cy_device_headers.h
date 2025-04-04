/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Common header file to be included by the drivers.
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

#ifndef _CY_DEVICE_HEADERS_H_
#define _CY_DEVICE_HEADERS_H_

#if defined (CYW20829B0LKML)
    #include "cyw20829b0lkml.h"
#elif defined (CYW89829B0022)
    #include "cyw89829b0022.h"
#elif defined (CYW89829B0232)
    #include "cyw89829b0232.h"
#elif defined (CYW20829B0000)
    #include "cyw20829b0000.h"
#elif defined (CYW20829B0010)
    #include "cyw20829b0010.h"
#elif defined (CYW20829B0021)
    #include "cyw20829b0021.h"
#elif defined (CYW20829A0LKML)
    #include "cyw20829a0lkml.h"
#elif defined (CYW20829A0KML)
    #include "cyw20829a0kml.h"
#elif defined (CYW89829A0KML)
    #include "cyw89829a0kml.h"
#elif defined (CYW20829B0KML)
    #include "cyw20829b0kml.h"
#elif defined (CYW89829B0KML)
    #include "cyw89829b0kml.h"
#else
    #error Undefined part number
#endif


#endif /* _CY_DEVICE_HEADERS_H_ */


/* [] END OF FILE */
