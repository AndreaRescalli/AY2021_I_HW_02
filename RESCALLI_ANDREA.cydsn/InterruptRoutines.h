/* ========================================
 *
 * Copyright LTEBS srl, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF LTEBS srl.
 *
 * \file  InterruptRoutines.h
 * \brief Header file containing ISR declaration for the Assignment_2
 *
 * Sets the behaviour of an (external) RGB LED based on the press of a button
 *
 * \author: Andrea Rescalli
 * \date:   13/10/2020 
 *
 * ========================================
*/

#ifndef __INTERRUPT_ROUTINES_H_
    #define __INTERRUPT_ROUTINES_H_
    
    #include "Timer_LED.h"
    
    CY_ISR_PROTO(Custom_ISR_Timer_LED);
    CY_ISR_PROTO(Custom_ISR_Push);
    
#endif


/* [] END OF FILE */
