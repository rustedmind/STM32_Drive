/*
 * led_control.c
 *
 *  Created on: 28 окт. 2016 г.
 *      Author: nafilaretov
 */

#include "application_data.h"
#include "led_control.h"

/*!
 * @brief Control LED indication based on PWM value
 * @param threshold - counter_t THRSLD value
 */
void led_switch(uint8_t threshold)
{
	static uint8_t width;
	width = threshold;

	/*check for value*/
	if(width < (LOW_POWER+1))
	{
		set_led(LOW_POWER);
	}
	else if (width < (MID_POWER+1))
	{
		set_led(MID_POWER);
	}
	else
	{
		set_led(HIGH_POWER);
	}
}

/*!
 * @brief Direct control of GPIO for corresponding LEDs
 * @param mode
 * @todo add code to control GPIO lines
 */
void set_led(uint8_t mode)
{
	switch (mode) {
		case LOW_POWER:

			break;
		case MID_POWER:

			break;
		case HIGH_POWER:

			break;
		default:
			break;
	}
}
