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
#include <stdbool.h>
//Kode til "controls.h".
//Kode til "controls.c". Funktionerne fastholder stepmotoren i et state angivet af 'stator', men skifter ikke mellem dem:


uint8 position = 0;
bool started = false;
bool clockwise = true;

void setState(STATOR_STATE s)
{
    stator = s;
}

void waveDrive()
{
	UART_1_PutString("Wave drive mode\r\n");
    switch(stator)
    {
        case STATOR_STATE_1A:
        {
            Pin_1b_Write(0);
            Pin_2a_Write(0);
            Pin_2b_Write(0);
            Pin_1a_Write(1);
            
            if (clockwise)
            {
                stator = STATOR_STATE_1B;
            }
            else 
            {
                stator = STATOR_STATE_2B;
            }

        }
        break;
        case STATOR_STATE_1B:
        {
            Pin_1a_Write(0);
            Pin_2a_Write(0);
            Pin_2b_Write(0);
            Pin_1b_Write(1);
            
            if (clockwise)
            {
                stator = STATOR_STATE_2A;
            }
            else 
            {
                stator = STATOR_STATE_1A;
            }
        }
        break;
        case STATOR_STATE_2A:
        {
            Pin_1a_Write(0);
            Pin_1b_Write(0);
            Pin_2b_Write(0);
            Pin_2a_Write(1);
            if (clockwise)
            {
                stator = STATOR_STATE_2B;
            } 
            else 
            {
                stator = STATOR_STATE_1B;
            }
        }
        break;
        case STATOR_STATE_2B:
        {
            Pin_1a_Write(0);
            Pin_1b_Write(0);
            Pin_2a_Write(0);
            Pin_2b_Write(1);
            if(clockwise)
            {
                stator = STATOR_STATE_1A;
            }
            else
            {
                stator = STATOR_STATE_2A;
            }
        }
        break;
    }
    
    
}

void fullStep()
{
	UART_1_PutString("Full step mode\r\n");
    switch(stator)
    {
        case STATOR_STATE_1A_1B:
        {
            
            Pin_2a_Write(0);
            Pin_2b_Write(0);
            Pin_1a_Write(1);
            Pin_1b_Write(1);
            stator = STATOR_STATE_1B_2A;
            break;
            
        }
        case STATOR_STATE_1B_2A:
        {
            Pin_1a_Write(0);
            Pin_2b_Write(0);
            Pin_1b_Write(1);
            Pin_2a_Write(1);
            stator = STATOR_STATE_2A_2B;
            break;
            
        }
        case STATOR_STATE_2A_2B:
        {
            Pin_1a_Write(0);
            Pin_1b_Write(0);
            Pin_2a_Write(1);
            Pin_2b_Write(1);
            stator = STATOR_STATE_2B_1A;
            
            break;
            
        }
        case STATOR_STATE_2B_1A:
        {
            
            Pin_1b_Write(0);
            Pin_2a_Write(0);
            Pin_1a_Write(1);
            Pin_2b_Write(1);
            stator = STATOR_STATE_1A_1B;
            break;  
        }
        default:
        {
            UART_1_PutString("no match - full step");
        }
    }
    
}

void halfStep()
{
	UART_1_PutString("Half step mode\r\n");
    switch(stator)
    {
        case STATOR_STATE_1A:
        {
            
            Pin_1b_Write(0);
            Pin_2a_Write(0);
            Pin_2b_Write(0);
            Pin_1a_Write(1);
            stator = STATOR_STATE_1A_1B;
            
        }
        break;
        case STATOR_STATE_1A_1B:
        {
            Pin_2a_Write(0);
            Pin_2b_Write(0);
            Pin_1a_Write(1);
            Pin_1b_Write(1);
            stator = STATOR_STATE_1B;
            
        }
        break;
        case STATOR_STATE_1B:
        {
            
            Pin_2a_Write(0);
            Pin_2b_Write(0);
            Pin_1a_Write(0);
            Pin_1b_Write(1);
            stator = STATOR_STATE_1B_2A;
            
        }
        break;
        case STATOR_STATE_1B_2A:
        {
            Pin_1a_Write(0);
            Pin_2b_Write(0);
            Pin_1b_Write(1);
            Pin_2a_Write(1);
            stator = STATOR_STATE_2A;
            
        }
        break;
        case STATOR_STATE_2A:
        {
            Pin_1a_Write(0);
            Pin_1b_Write(0);
            Pin_2b_Write(0);
            Pin_2a_Write(1);
            stator = STATOR_STATE_2A_2B;
        }
        break;
        case STATOR_STATE_2A_2B:
        {
            Pin_1a_Write(0);
            Pin_1b_Write(0);
            Pin_2a_Write(1);
            Pin_2b_Write(1);
            stator = STATOR_STATE_2B;
        }
        break;
        case STATOR_STATE_2B:
        {
            Pin_1a_Write(0);
            Pin_1b_Write(0);
            Pin_2a_Write(0);
            Pin_2b_Write(1);
            stator = STATOR_STATE_2B_1A;
        }
        break;
        case STATOR_STATE_2B_1A:
        {
            Pin_1b_Write(0);
            Pin_2a_Write(0);
            Pin_2b_Write(1);
            Pin_1a_Write(1);
            stator = STATOR_STATE_1A;
        }
        break;
    }
    
}

void increaseSpeed()
{
    uint16 current = Timer_1_ReadPeriod();
    
    if (current - 5000 > 0)
    {
        Timer_1_WritePeriod(current - 5000);     
    }
}

void decreaseSpeed()
{
    
    uint16 current = Timer_1_ReadPeriod();
    
    if (current + 5000 < 65536)
    {
        Timer_1_WritePeriod(current + 5000);
     
    }
}

void start()
{
    if (!started)
    {
        Timer_1_Start();
        started = true;
    }
}

void stop()
{
    if (started)
    {
        Timer_1_Stop();
        started = false;
    }
}

void set_clockwise()
{
    clockwise = true;
}

void set_counter_clockwise()
{
    clockwise = false;
}
