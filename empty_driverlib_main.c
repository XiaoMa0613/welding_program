//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "m_epwm.h"
#include "m_gpio.h"
#include "m_adc.h"
#include "F28x_Project.h"
//
// Main
//
uint16_t adcAResult0;
uint16_t adcAResult1;

void delay_us(long int c)
{
    long int a = c;
    while(a--) {};
}
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();
    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    init_GPIO();
    init_All_EPWM();
    init_ADC();
    while(1)
    {
        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 0);  //ON
        delay_us(500000);
        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1);  //OFF
        delay_us(500000);
#if 0
        // 2808是软件触发ADC转换�?
        // Convert, wait for completion, and store results
        ADC_forceSOC(ADCA_BASE, ADC_SOC_NUMBER0);
        ADC_forceSOC(ADCA_BASE, ADC_SOC_NUMBER1);
        ADC_forceSOC(ADCB_BASE, ADC_SOC_NUMBER0);
        ADC_forceSOC(ADCB_BASE, ADC_SOC_NUMBER1);
#endif
        // 等待ADC转换完成，并清除中断标志�?
        while(ADC_getInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1) == false)
        {
        }
        ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);

        // 储存结果,测试能正常采�?
        adcAResult0 = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
        adcAResult1 = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER1);

        // 用于调试的软件暂停�?
//        ESTOP0;
    }
}

//
// End of File
//
