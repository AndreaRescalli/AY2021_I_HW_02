/* ========================================
 *
 * Copyright LTEBS srl, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF LTEBS srl.
 *
 *
 * \author Andrea Rescalli
 * \brief  Header file for the interrupt routines
 *
 * ========================================
*/

// Include ISR header
#include "InterruptRoutines.h"

// Include required header files
#include "Timer_LED.h"

CY_ISR(Custom_Timer_ISR) {

    // Read timer status register to bring interrupt line low
    Timer_LED_ReadStatusRegister();
    
    // Count
    counter_timer++;

}




/* [] END OF FILE */
