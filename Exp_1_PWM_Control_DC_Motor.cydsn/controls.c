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
#include "controls.h"
#include <stdio.h>

/*
 Decrease speed by 10%. Stops at 0%
*/
void decreaseSpeed()
{
    uint8 curr = PWM_1_ReadCompare();
    
    if (curr > 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
            "Decreasing speed to %d\n\r", curr - 10);
        UART_1_PutString(buffer);
        PWM_1_WriteCompare(curr - 10);
    }
    else
    {
        UART_1_PutString("Minimum speed reached\n\r");
    }
}
/*
    Increase speed by 10%. Stops at 100%
*/
void increaseSpeed()
{
    uint8 curr = PWM_1_ReadCompare();
    if (curr < 100)
    {   
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
            "Increasing speed to %d\n\r", curr + 10);
        UART_1_PutString(buffer);
        PWM_1_WriteCompare(curr + 10);
        
    }
    else
    {
        UART_1_PutString("Maximum speed reached\n\r");
    }
}
void driveForwards()
{
    UART_1_PutString("Set direction: forwards\r\n");
}

void driveBackwards()
{
    UART_1_PutString("Set direction: backwards\r\n");
}

/*
    Stops motor. Sets speed to 0%
*/
void stop()
{
    UART_1_PutString("Stop\r\n");
    PWM_1_WriteCompare(0);
}
/* [] END OF FILE */
