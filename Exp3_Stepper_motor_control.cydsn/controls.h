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

Driver  to control motor

*/


typedef enum
{
	STATOR_STATE_1A,
    STATOR_STATE_1A_1B,
	STATOR_STATE_1B,
    STATOR_STATE_1B_2A,
    STATOR_STATE_2A,
    STATOR_STATE_2A_2B,
    STATOR_STATE_2B,
    STATOR_STATE_2B_1A,
} STATOR_STATE;

typedef enum
{
    MODE_WAVE_DRIVE,
    MODE_FULL_STEP,
    MODE_HALF_STEP
} MODE;


STATOR_STATE stator;
MODE CURRENT_MODE;

void waveDrive();
void fullStep();
void halfStep();
void increaseSpeed();
void decreaseSpeed();
void start();
void stop();
void set_clockwise();
void set_counter_clockwise();
/* [] END OF FILE */