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

bool dir = false;

/*
 Decrease speed by 10%. Stops at 0%
*/
void decreaseSpeed()
{
    uint8 curr1 = PWM_1_ReadCompare1();
    uint8 curr2 = PWM_1_ReadCompare2();
    
    if (dir) {
        
        if (curr1 > 0)
        {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
            "Decreasing speed to %d\n\r", curr1 - 10);
        UART_1_PutString(buffer);
        
        PWM_1_WriteCompare1(curr1 - 10);
        return;
        }
        else
        {
            UART_1_PutString("Minimum speed reached\n\r");
            return;
        }
        
    } 
    else {
    
    if (curr2 > 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
            "Decreasing speed to %d\n\r", curr2 - 10);
        UART_1_PutString(buffer);
        
        PWM_1_WriteCompare2(curr2 - 10);
        return;
    }
    else
    {
        UART_1_PutString("Minimum speed reached\n\r");
        return;
    }
    }
}
/*
    Increase speed by 10%. Stops at 100%
*/
void increaseSpeed()
{
    uint8 curr1 = PWM_1_ReadCompare1();
    uint8 curr2 = PWM_1_ReadCompare2();
    
    if (dir) {
    
    if (curr1 < 100)
    {   
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
            "Increasing speed to %d\n\r", curr1 + 10);
        UART_1_PutString(buffer);
        PWM_1_WriteCompare1(curr1 + 10);
        
    }
    else
    {
        UART_1_PutString("Maximum speed reached\n\r");
    }
    } else { 
    
          if (curr2 < 100)
        {   
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
            "Increasing speed to %d\n\r", curr2 + 10);
        UART_1_PutString(buffer);
        PWM_1_WriteCompare2(curr2 + 10);
        
         }
        else
        {
        UART_1_PutString("Maximum speed reached\n\r");
        }
       
    
    }
    
    
    
    
    
}
void driveForwards()
{
    if(!dir)
    {
        PWM_1_WriteCompare1(PWM_1_ReadCompare2());
        PWM_1_WriteCompare2(0);
        UART_1_PutString("Set direction: forwards\r\n");
        dir = true;
        return;
    }
}

void driveBackwards()
{
    if(dir)
    {
        PWM_1_WriteCompare2(PWM_1_ReadCompare1());
        PWM_1_WriteCompare1(0);
        UART_1_PutString("Set direction: backwards\r\n");
        dir = false;
        return;
    }
}

/*
    Stops motor. Sets speed to 0%
*/
void stop()
{
    UART_1_PutString("Stop\r\n");
    PWM_1_WriteCompare1(0);
    PWM_1_WriteCompare2(0);
}

/* [] END OF FILE */
