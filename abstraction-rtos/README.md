# RTOS Abstraction

## Overview

The RTOS abstraction layer provides simple RTOS services like threads, semaphores, mutexes, queues, and timers. It is not intended to be a full features RTOS interface, but the provide just enough support to allow for RTOS independent drivers and middleware. This allows middleware applications to be as portable as possible within ModusToolbox™. This library provides a unified API around the actual RTOS. This allows middleware libraries to be written once independent of the RTOS actually selected for the application. The abstraction layer provides access to all the standard RTOS resources listed in the feature section below.

While the primary purpose of the library is for middleware, the abstraction layer can be used by the application code. However, since this API does not provide all RTOS features and the application generally knows what RTOS is being used, this is typically an unnecessary overhead.

All the RTOS abstraction layer functions generally all work the same way. The basic process is:
1. Include the cyabs_rtos.h header file so that you have access to the RTOS functions.
2. Declare a variable of the right type (e.g. cy_mutex_t)
3. Call the appropriate create or initialize function (e.g. cy_rtos_init_mutex()). Provide it with a reference to the variable that was created in step 2.
4. Access the RTOS object using one of the access functions. e.g. cy_rtos_set_mutex().
5. If you don't need it anymore, free up the pointer with the appropriate de-init function (e.g. cy_rtos_deinit_mutex()).

NOTE: All these functions need a pointer, so it is generally best to declare these "shared" resources as static global variables within the file that they are used.

## Getting Started

To use the RTOS Abstraction, simply include a reference to `cyabs_rtos.h` and update the application's makefile to include the appropriate component. e.g. one of:
* COMPONENTS+=RTX
* COMPONENTS+=FREERTOS
* COMPONENTS+=THREADX

## Features

* APIs for interacting with common RTOS Features including:
    * Threads
    * Mutexes
    * Semaphores
    * Timers
    * Queues
    * Events
* Implementations are provided for
    * FreeRTOS
    * RTX (CMSIS RTOS)
    * ThreadX
    * WICED RTOS

## RTOS Configuration Requirements
### FreeRTOS
To enable all functionality when using with FreeRTOS, the following configuration options must be enabled in FreeRTOSConfig.h:
* configSUPPORT_DYNAMIC_ALLOCATION
* configSUPPORT_STATIC_ALLOCATION
* configUSE_COUNTING_SEMAPHORES
* configUSE_MUTEXES
* configUSE_NEWLIB_REENTRANT
* configUSE_RECURSIVE_MUTEXES
* configUSE_TASK_NOTIFICATIONS
* configUSE_TICKLESS_IDLE
* configUSE_TIMERS
* configUSE_TRACE_FACILITY

* INCLUDE_vTaskDelay
* INCLUDE_vTaskDelete
* INCLUDE_vTaskPrioritySet
* INCLUDE_uxTaskPriorityGet
* INCLUDE_xTimerPendFunctionCall
* INCLUDE_vTaskSuspend

Enabling configSUPPORT_STATIC_ALLOCATION requires the application to provide implementations for `vApplicationGetIdleTaskMemory` and
`vApplicationGetTimerTaskMemory`functions. Weak implementations for these functions are provided as a part of this library. These can
be overridden by the application if custom implementations of these functions are desired.<br>

#### Low Power Configuration
This library provides an API `vApplicationSleep` which can be used to enable tickless support in FreeRTOS. In order to enable tickless mode with this API, the following changes need to be made in `FreeRTOSConfig.h`:
* Enables tickless mode with user specified `portSUPPRESS_TICKS_AND_SLEEP` implementation.<br>
\c \#define `configUSE_TICKLESS_IDLE                       2`
* Hook `portSUPPRESS_TICKS_AND_SLEEP` macro to `vApplicationSleep` implementation.<br>
\c \#define `portSUPPRESS_TICKS_AND_SLEEP( xIdleTime )    vApplicationSleep( xIdleTime )`

In tickless mode `vApplicationSleep` updates the number of RTOS ticks that have passed since the tick interrupt was stopped using `vTaskStepTick`, taking into account the sleep/deepsleep latency.
* The maximum tickless idle time can be calculated as follow:
    * `MaxIdleTime = LPtimerDelay + latency` where: `latency = PreSleepLatency + PostSleepLatency`, `LPtimerDelay = xExpectedIdleTime - latency`. 

    **Note**: The `LPtimerDelay` represents the duration in which the IP is configured to Wake-up the device. Wake-up can happen before its expiration if one other configured interrupt triggers during this time.

* In case of `xExpectedIdleTime <= latency` WFI is executed instead, and normal sleep is expected to be reached (SCR->SLEEPDEEP = 0).

* The actual Idle time for which the Systick timer is disabled, is always update in vTaskStepTick to keep the RTOS alwyas up to date, independently from if the tickless sleep is reached or not successfully. The reason for this is to find in the sequence of operations to reach the sleep, the Systick is disabled before the (deep)sleep callbacks are called, so if one of them will not allow (deep)sleep, the ticks for which the check is performed needs to be anyway counted in the RTOS.

Functions cy_rtos_scheduler_suspend/cy_rtos_scheduler_resume can be called from ISR but calls need to be paired to restore the saved interrupt status correctly so a structure to save these values has been implemented.
The size of this structure can be controlled with CY_RTOS_MAX_SUSPEND_NESTING. This macro is overridable and its default value is 3.

For further details on Low power support in FreeRTOS please refer to documentation [here](https://www.freertos.org/low-power-tickless-rtos.html)

#### Known Limitations
The cy_rtos_event_* functions accept a 32-bit event as an argument. However, FreeRTOS requires 8-bits(`configUSE_16_BIT_TICKS` == 1) or 24-bits (`configUSE_16_BIT_TICKS` == 0) to run successfully. Hence the application should not reference these unsupported bits. Check the FreeRTOS implementation of `eventEVENT_BITS_CONTROL_BYTES` in event_group.c for internal details.

### RTX / ThreadX
No specific requirements exist

## Porting Notes
In order to port to a new environment, the file cyabs_rtos_impl.h must be provided with definitions of some basic types for the abstraction layer.  The types expected to be defined are:

- `cy_thread_t` : typedef from underlying RTOS thread type
- `cy_thread_arg_t` : typedef from the RTOS type that is passed to the entry function of a thread.
- `cy_mutex_t` : typedef from the underlying RTOS mutex type
- `cy_semaphore_t`: typedef from the underlying RTOS semaphore type
- `cy_event_t` : typedef from the underlying RTOS event type
- `cy_queue_t` : typedef from the underlying RTOS queue type
- `cy_timer_callback_arg_t` : typedef from the RTOS type that is passed to the timer callback function
- `cy_timer_t` : typedef from the underlying RTOS timer type
- `cy_time_t` : count of time in milliseconds
- `cy_rtos_error_t` : typedef from the underlying RTOS error type

The enum `cy_thread_priority_t` needs to have the following priority values defined and mapped to RTOS specific values:
- `CY_RTOS_PRIORITY_MIN`
- `CY_RTOS_PRIORITY_LOW`
- `CY_RTOS_PRIORITY_BELOWNORMAL`
- `CY_RTOS_PRIORITY_NORMAL`
- `CY_RTOS_PRIORITY_ABOVENORMAL`
- `CY_RTOS_PRIORITY_HIGH`
- `CY_RTOS_PRIORITY_REALTIME`
- `CY_RTOS_PRIORITY_MAX`

Finally, the following macros need to be defined for memory allocations:
- `CY_RTOS_MIN_STACK_SIZE`
- `CY_RTOS_ALIGNMENT`
- `CY_RTOS_ALIGNMENT_MASK`

## More information
* [API Reference Guide](https://infineon.github.io/abstraction-rtos/html/modules.html)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2019-2022.
