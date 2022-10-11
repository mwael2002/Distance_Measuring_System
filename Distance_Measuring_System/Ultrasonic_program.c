/*
 * Ultrasonic_program.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mwael
 */

#include <avr/delay.h>
#include "STD_Types.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "Ultrasonic_config.h"
#include "Ultrasonic_interface.h"


U16 pulse_time;

void Ultrasonic_init(void){
    DIO_set_pin_direction(Group_D,ULTRASONIC_TRIGGER_PIN,OUTPUT);
    DIO_set_pin_direction(Group_D,ULTRASONIC_ECHO_PIN,INPUT);

    Timer1_init();
    ICU_CallBack(Ultrasonic_edge_processing);

}

void Ultrasonic_trigger(void){

       DIO_set_pin_value(Group_D,ULTRASONIC_TRIGGER_PIN,HIGH);
      _delay_us(10);
       DIO_set_pin_value(Group_D,ULTRASONIC_TRIGGER_PIN,LOW);

   }


U16 Ultrasonic_get_reading(void){
	  F32 distance;

	  Ultrasonic_trigger();
	  distance=pulse_time*34300/2.0/125000;

     return ((U16)distance);
}



void Ultrasonic_edge_processing(void){

static U8  edge_flag=0;
static U16 no1,no2;

if(edge_flag==0){
	no1=ICU_Read_Input_Capture();
        edge_flag=1;
	ICU_Set_Trigger(FALLING_EDGE);
      }
else{
	no2=ICU_Read_Input_Capture();
	pulse_time=(no2-no1);

    edge_flag=0;
    ICU_Set_Trigger(RISING_EDGE);

     }

}
