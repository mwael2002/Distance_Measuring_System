/*
 * Ultrasonic_interface.h
 *
 *  Created on: Oct 11, 2022
 *      Author: mwael
 */

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

void Ultrasonic_init(void);
void Ultrasonic_trigger(void);
U16 Ultrasonic_get_reading(void);
void Ultrasonic_edge_processing(void);

#endif /* ULTRASONIC_INTERFACE_H_ */
