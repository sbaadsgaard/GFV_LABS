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
        case '1' :
        {
            driveForwards();
        }
        break;
        case '2' :
        {
            driveBackwards();
        }
        break;
        case '0' :
        {
            stop();
            
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}

/*
    Initialise motor. Starts UART and PWN and prints options.
*/
void init()
{
    UART_1_Start();
    PWM_1_Start();
    UART_1_PutString("DC-Motor-PWM application started\r\n");
    print_help();
    driveForwards();
}


/* [] END OF FILE */
