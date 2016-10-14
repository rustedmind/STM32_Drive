/*
 * application_data.h
 *
 *  Created on: 14 окт. 2016 г.
 *      Author: nafilaretov
 */

#include "misra_types.h"

#ifndef APPLICATION_DATA_H_
#define APPLICATION_DATA_H_

/*
 *
 */
struct counter_data
{
	boolean CLK;
	boolean ISR;
	boolean RST;
	uint8_t ACC;
	uint8_t TRSHLD;
} counter_data_tag;

typedef struct counter_data counter_t;

/*!
 *
 */
struct appdata
{
	counter_t counter_state;
	uint8_t external_command;

} appdata_tag;

typedef struct appdata appdata_t;

extern appdata_t APPLICATION_DATA;

#endif /* APPLICATION_DATA_H_ */
