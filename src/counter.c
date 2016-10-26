#include "counter.h"
#include <string.h>



counter_t counter_init(counter_t MyCounter)
{
	memset(&MyCounter,0,sizeof(MyCounter));
	return MyCounter;
}


counter_t counter_reset(counter_t MyCounter)
{
	MyCounter.ACC = 0U;
	MyCounter.ISR = (boolean)0;
    return MyCounter;
}

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

counter_t counter_step()
{

	APPLICATION_DATA.counter_state = counter_state_machine(APPLICATION_DATA.counter_state.CLK);
	if(APPLICATION_DATA.counter_state.ACC == (uint8_t) 255)
	{
		APPLICATION_DATA.counter_state = counter_reset(APPLICATION_DATA.counter_state);
	}

	return APPLICATION_DATA.counter_state;
}
