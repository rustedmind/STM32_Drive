/*
 * counter.h
 *
 *  Created on: 19 сент. 2016 г.
 *      Author: nafilaretov
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include "misra_types.h"
#include "application_data.h"


counter_t counter_state_machine(boolean);
counter_t counter_step( void );
counter_t counter_init(Counter_data);


#endif /* COUNTER_H_ */
