/* ========================================
 *
 * Copyright LTEBS srl, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF LTEBS srl.
 *
 * \file  InterruptRoutines.c
 * \brief Source file with ISR bodies for the Assignment_2
 *
 * Sets the behaviour of an (external) RGB LED based on the press of a button
 *
 * \author: Andrea Rescalli
 * \date:   13/10/2020 
 *
 * ========================================
*/

// Include ISR header
#include "InterruptRoutines.h"

uint8 counter_timer;
uint8 flag_push;

CY_ISR(Custom_ISR_Timer_LED) {

    // Read timer status register to bring interrupt line low
    Timer_LED_ReadStatusRegister();
    
    // Count every 250 ms
    counter_timer++;

}

CY_ISR(Custom_ISR_Push) {

    /* No need to clear any interrupt source:
     * interrupt component is configured for RISING_EDGE mode.
    */
    
    // Increment the push counter
    flag_push = 1;

}




/* [] END OF FILE */
