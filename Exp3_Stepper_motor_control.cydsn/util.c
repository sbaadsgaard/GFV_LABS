/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "util.h"
#include "controls.h"

/*
Prints command options in terminal.
*/
void print_help()
{
    UART_1_PutString("0: Stop\r\n");
    UART_1_PutString("1: Drive forwards\r\n");
    UART_1_PutString("2: Drive backwards\r\n");
    UART_1_PutString("q: Decrease speed\r\n");
    UART_1_PutString("w: Increase speed\r\n");
    UART_1_PutString("h: Show options\r\n");    
}

/*
Handle incoming commands from UART. Calls relevant control functions.
*/
void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'q' :
        {
            decreaseSpeed();
        }
        break;
        case 'w' :
        {
            increaseSpeed();
        }
        break;
        case 'h' :
        {
            print_help();
        }
        break;
        case '2' :
        {
            set_clockwise();
        }
        break;
        case '1' :
        {
            set_counter_clockwise();
        }
        break;
        case '0' :
        {
            stop();
            break;
        }
        
        case '9' :
        {
            start();
            break;
            
        }
      
        
        case 'z':
        {
            UART_1_PutString("Running wave drive\n");
            CURRENT_MODE = MODE_WAVE_DRIVE;
            stator = STATOR_STATE_1A;
            
            break;
        }
        
        case 'x':
        {
            UART_1_PutString("Running full step\n");
            CURRENT_MODE = MODE_FULL_STEP;
            stator = STATOR_STATE_1A_1B;
            
            break;
        }
        
        case 'c':
        {
            UART_1_PutString("Running half step\n");
            CURRENT_MODE = MODE_HALF_STEP;
            stator = STATOR_STATE_1A;
            break;
        }
        default :
        {
            break;
                        
        }
    }
}

/*
    Initialise motor. Starts UART and PWN and prints options.
*/
void init()
{
    UART_1_Start();
    UART_1_PutString("started");
    stator = STATOR_STATE_1A;
    CURRENT_MODE = MODE_WAVE_DRIVE;
}

/* [] END OF FILE */
