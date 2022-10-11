/*
 * main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: mwael
 */
#include <avr/delay.h>
#include "STD_Types.h"
#include "GIE_interface.h"
#include "Timer_interface.h"
#include "LCD_interface.h"
#include "Ultrasonic_interface.h"

U16 desired_count;
U16 measured_distance;

void  Display_Distance(void);

void main(void){

        Ultrasonic_init();
        LCD_init();

	    Timer0_init();
        desired_count=Overflow_time_calculate(TIMER0_ID);
        Timer_callback(TIMER0_ID,Display_Distance);

        Global_Int_En_Dis(Global_Int_Enable);


while(1){

	measured_distance=Ultrasonic_get_reading();

  }
}

void Display_Distance(void){

	static U16 count=0;
	count++;

	if(count==desired_count){
		Overflow_restart_count(TIMER0_ID);
		count=0;

        LCD_clear();
        LCD_write_string_pos("Distance=",0,0);
		LCD_write_no_pos(measured_distance,0,10);
		LCD_write_string_pos("cm",0,13);

	}
	}

