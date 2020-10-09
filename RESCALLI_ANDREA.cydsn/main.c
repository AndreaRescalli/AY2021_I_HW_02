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

// Include header(s)
#include "project.h"
#include "InterruptRoutines.h"

// Set globals
uint8 counter_timer = 0;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_LED_Start();
    ISR_Timer_LED_StartEx(Custom_Timer_ISR);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
