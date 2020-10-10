/* ========================================
 *
 * Copyright LTEBS srl, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF LTEBS srl.
 *
 * \file  user_functions.c
 * \brief Source file containing user's functions body for the Assignment_2
 *
 * Sets the behaviour of an (external) RGB LED based on the press of a button
 *
 * \author: Andrea Rescalli
 * \date:   13/10/2020
 *
 * ========================================
*/

// Include of needed header files
#include "Timer_LED.h"
#include "user_functions.h"

// Declaration of global variable in charge of keeping track of the timer ISR
extern uint8 counter_timer;

/*
 * This function is in charge of the reset of the timer.
 * Will be used each time we enter in a new state to re-synchronize the pattern
 *
*/
void reset_timer(void) {
    
    // Reset the timer
    Timer_LED_Stop();
    Timer_LED_WriteCounter(249);
    Timer_LED_Enable();
    counter_timer = 0; // reset the timer-tracking variable
    
}

/* [] END OF FILE */
