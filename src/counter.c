#include "counter.h"
#include <string.h>


/*!
 * @brief initialize a counter
 * @param counter_t object corresponding to counter
 * @return counter_t type object, same object as input
 */
counter_t counter_init(counter_t MyCounter)
{
	memset(&MyCounter,0,sizeof(MyCounter));
	return MyCounter;
}

/*!
 * @brief Reset a counter
 * @param counter_t object corresponding to counter
 * @return counter_t type object, same object as input
 */
counter_t counter_reset(counter_t MyCounter)
{
	MyCounter.ACC = 0U;
	MyCounter.ISR = (boolean)0;
    return MyCounter;
}

/*!
 * @brief State machine, describing dehavior of counter
 * @param CLK, signal to allow conter to increase
 * @return counter_t type object, same object as input
 */
counter_t counter_state_machine(boolean CLK)
{

		if(CLK == (boolean)1)
		{
			APPLICATION_DATA.counter_state.ACC++;
		}
		if(APPLICATION_DATA.counter_state.ACC <= APPLICATION_DATA.counter_state.TRSHLD)
		{
			APPLICATION_DATA.counter_state.ISR = (boolean)0;
		}
		else
		{
			APPLICATION_DATA.counter_state.ISR = (boolean)1;
		}

	return APPLICATION_DATA.counter_state;
}

/*!
 * @brief Wrapper for counter state machine with accumulator overflow control
 * @return counter_t type object
 */
counter_t counter_step()
{

	APPLICATION_DATA.counter_state = counter_state_machine(APPLICATION_DATA.counter_state.CLK);
	if(APPLICATION_DATA.counter_state.ACC == (uint8_t) 255)
	{
		APPLICATION_DATA.counter_state = counter_reset(APPLICATION_DATA.counter_state);
	}

	return APPLICATION_DATA.counter_state;
}
