/*
 * led_control.h
 *
 *  Created on: 28 окт. 2016 г.
 *      Author: nafilaretov
 */

#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

enum uint8_t
{
	LOW_POWER = 101U,
	MID_POWER = 178U,
	HIGH_POWER = 255U
} WIDTH_TABLE;

void led_switch(uint8_t);
void set_led(uint8_t);

#endif /* LED_CONTROL_H_ */
