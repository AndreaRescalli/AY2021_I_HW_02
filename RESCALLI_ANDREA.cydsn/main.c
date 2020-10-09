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
 * \brief  Set the status of an (external) RGB LED based on the press of a button
 *
 * ========================================
*/

// Include header(s)
#include "project.h"
#include "InterruptRoutines.h"

/* 
 * Defining the states for the RGB configuration.
 * Mismatch is due to C starting from 0, while states from 1, and from counter
 * being set to count_down
*/
#define STATE_1 6
#define STATE_2 5
#define STATE_3 4
#define STATE_4 3
#define STATE_5 2
#define STATE_6 1
#define STATE_7 0


// Set globals
uint8 counter_timer = 0; // keeps track of how many 250ms have passed
uint8 state = STATE_1;   // keeps track of the state we're in
uint8 x = 0;             // helps counter_timer in STATE_6 and STATE_7


int main(void) {

    CyGlobalIntEnable; /* Enable global interrupts. */

    Timer_LED_Start();
    ISR_Timer_LED_StartEx(Custom_Timer_ISR);
    State_Counter_Init();
    
    
    for(;;) {
        
        if (state == STATE_1) {
            /* 
             * In STATE_1 the requirements are:
             * - RED   always ON 
             * - GREEN always ON
             *
            */
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            
            // Check the LEDs; if they're OFF turn them ON
            if (!Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read());
            }
            if (!Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read());
            }
            
            while (state == STATE_1) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();
                
                // Condition to not let counter_timer overflow: reset each 2s
                if (counter_timer == 8) {
                    counter_timer = 0;
                }
            }
            
        } // end STATE_1
        
        else if (state == STATE_2) {
            /* 
             * In STATE_2 the requirements are:
             * - RED   always ON 
             * - GREEN ON for initial 50%
             *
            */    
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            
            // Check the LEDs; if they're OFF turn them ON
            if (!Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read());
            }
            if (!Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read());
            }

            while (state == STATE_2) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();
                
                // GREEN has a DC of 50%, so it toggles each second
                if (counter_timer == 4) {
                    Green_LED_Write(!Green_LED_Read());
                    counter_timer = 0; // reset timer-tracking variable
                }
            }
        
        } // end STATE_2
        
        else if (state == STATE_3) {
            /* 
             * In STATE_3 the requirements are:
             * - RED   OFF for initial 50% 
             * - GREEN always ON
             *
            */    
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            
            // Check the LEDs
            if (Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read()); // If RED is ON, switch it OFF
            }
            if (!Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read()); // If GREEN is OFF, switch it ON
            }

            while (state == STATE_3) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();
                
                // RED has a DC of 50%, so it toggles each second
                if (counter_timer == 4) {
                    Red_LED_Write(!Red_LED_Read());
                    counter_timer = 0; // reset timer-tracking variable
                }
            }

        } // end STATE_3
        
        else if (state == STATE_4) {
            /* 
             * In STATE_4 the requirements are:
             * - RED   ON for initial 25% 
             * - GREEN opposite of RED
             *
            */    
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            
            // Check the LEDs
            if (!Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read()); // If RED is OFF, switch it ON
            }
            if (Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read()); // If GREEN is ON, switch it OFF
            }

            while (state == STATE_4) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();
                
                // RED has a DC of 25%, so it toggles each half second
                if (counter_timer == 2) {
                    Red_LED_Write(!Red_LED_Read());
                    Green_LED_Write(!Red_LED_Read()); // opposite of what RED is
                    counter_timer = 0; // reset timer-tracking variable
                }
            }
        
        } // end STATE_4
        
        else if (state == STATE_5) {
            /* 
             * In STATE_5 the requirements are:
             * - RED   OFF for initial 12.5% 
             * - GREEN opposite of RED
             *
            */    
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            
            // Check the LEDs
            if (Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read()); // If RED is ON, switch it OFF
            }
            if (!Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read()); // If GREEN is OFF, switch it ON
            }

            while (state == STATE_5) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();
                
                // RED has a DC of 12.5%, so it toggles each 250ms
                if (counter_timer == 1) {
                    Red_LED_Write(!Red_LED_Read());
                    Green_LED_Write(!Red_LED_Read()); // opposite of what RED is
                    counter_timer = 0; // reset timer-tracking variable
                }
            }
        
        } // end STATE_5
        
        else if (state == STATE_6) {
            /* 
             * In STATE_6 the requirements are:
             * - RED   ON for initial 75% 
             * - GREEN ON for initial 50%
             *
            */    
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            
            // Check the LEDs
            if (!Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read()); // If RED is OFF, switch it ON
            }
            if (!Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read()); // If GREEN is OFF, switch it ON
            }

            while (state == STATE_6) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();

                if (counter_timer == 2) {
                    x++; // Keep track of each 500ms passing
                    
                    if (x == 2) {
                        // 1s has passed --> toggle of GREEN
                        Green_LED_Write(!Green_LED_Read());
                    }
                    
                    if (x == 3) {
                        // 1.5s has passes --> toggle of RED
                        Red_LED_Write(!Red_LED_Read());
                    }
                    
                    if (x == 4) {
                        // 2s have passed --> toggle both
                        Red_LED_Write(!Red_LED_Read());
                        Green_LED_Write(!Green_LED_Read());
                        x = 0; // reset helping variable
                    }
                    
                    counter_timer = 0; // reset timer-tracking variable
                }
            }
        
        } // end STATE_6
        
        else if (state == STATE_7) {
            /* 
             * In STATE_7 the requirements are:
             * - RED   OFF for initial 50% 
             * - GREEN ON for initial 25%
             *
            */    
            
            Timer_LED_Init();  // reset of the timer
            counter_timer = 0; // reset of the timer-tracking variable
            x = 0;             // reset helping variable
            
            // Check the LEDs
            if (Red_LED_Read()) {
                Red_LED_Write(!Red_LED_Read()); // If RED is ON, switch it OFF
            }
            if (!Green_LED_Read()) {
                Green_LED_Write(!Green_LED_Read()); // If GREEN is OFF, switch it ON
            }

            while (state == STATE_7) {
                // Check the counter to verify the button has not been pressed
                state = State_Counter_ReadCounter();
                
                // GREEN has a DC of 25%, so it toggles each half second
                if (counter_timer == 2) {
                    Green_LED_Write(!Green_LED_Read());
                    counter_timer = 0; // reset timer-tracking variable
                    x++;
                    
                    // RED toggles each second, so with a frequency half of GREEN
                    if (x == 2) {
                        Red_LED_Write(!Red_LED_Read());
                        x = 0; // reset helping variable
                    }
                }                
            }
        
        } // end STATE_7
        
    } // end for cycle
    
} // end main

/* [] END OF FILE */
