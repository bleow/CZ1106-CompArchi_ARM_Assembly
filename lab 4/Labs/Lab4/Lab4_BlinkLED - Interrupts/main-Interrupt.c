/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//***************************************************************************************
//  Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP432P4xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  E. Chen
//  Texas Instruments, Inc
//  March 2015
//  Built with Code Composer Studio v6
//***************************************************************************************

//#include <driverlib.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

void PORT3_IRQHandler(void);
void PORT5_IRQHandler(void);

volatile uint32_t global_i=100000;
volatile uint32_t debounce_delay=1000;

void main(void)
{
    volatile uint32_t i;

    // Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);

    // Set P1.0 to output direction
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    // Set P3.5 to input direction
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN5);

    // Edge select for P3.5
    GPIO_interruptEdgeSelect(GPIO_PORT_P3, GPIO_PIN5, GPIO_HIGH_TO_LOW_TRANSITION);

    //Clear Pending Interrupts
    GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN5);

    //Enable Interrupt for Pin3.5
    GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN5);

    GPIO_registerInterrupt(GPIO_PORT_P3, PORT3_IRQHandler);

    Interrupt_enableInterrupt(INT_PORT3);

    // Set P5.1 to input direction
    GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN1);

    // Edge select for P5.1
    GPIO_interruptEdgeSelect( GPIO_PORT_P5, GPIO_PIN1, GPIO_HIGH_TO_LOW_TRANSITION);

    //Clear Pending Interrupts
    GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN1);

    //Enable Interrupt for Pin5.1
    GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN1);

    GPIO_registerInterrupt(GPIO_PORT_P5, PORT5_IRQHandler);

    Interrupt_enableInterrupt(INT_PORT5);


    while(1)
    {
        PCM_gotoLPM3();
    }
}

/* GPIO ISR */
void PORT3_IRQHandler(void)
{
    uint32_t status;

    // ISR for button S2
    status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P3);
    GPIO_clearInterruptFlag(GPIO_PORT_P3, status);

    /* Turn LED ON */
    if(status & GPIO_PIN5)
    {
        GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }
}

void PORT5_IRQHandler(void)
{
    uint32_t status;

    // ISR for button S1
    status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P5);
    GPIO_clearInterruptFlag(GPIO_PORT_P5, status);

    /* Turn LED OFF */
    if(status & GPIO_PIN1)
    {
        GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }
}
