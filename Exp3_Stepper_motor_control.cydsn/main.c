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
#include "util.h"

CY_ISR_PROTO(isr_timer_handler);
CY_ISR_PROTO(isr_uart_rx_handler);

CY_ISR(isr_timer_handler)
{
    //UART_1_PutString("Interrupt!\n\r");
    //pos ++
    //pos --
    // hvilken mode?
    // if wave -> wavedrive();
    switch(CURRENT_MODE)
    {
        case MODE_WAVE_DRIVE:
        {
            //UART_1_PutString("wave!\n\r");
     
            waveDrive();
            break;
                        
        }
        case MODE_FULL_STEP:
        {
            //UART_1_PutString("full step\n\r");
            fullStep();
            break;
        }
        case MODE_HALF_STEP:
        {
            //UART_1_PutString("half step\n\r");
            halfStep();
            break;
        }
        default:
        {
            break;
            
        }
    }
    
}

CY_ISR(isr_uart_rx_handler)
{
    uint8 received = UART_1_ReadRxData();
    handleByteReceived(received);
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    init();
    isr_timer_StartEx(isr_timer_handler);
    isr_uart_rx_StartEx(isr_uart_rx_handler);    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
