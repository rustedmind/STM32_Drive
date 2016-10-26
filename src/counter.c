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

counter_t counter_state_machine(boolean CLK, boolean RST)
{

		// State reset
		// If reset is TRUE
		if (RST)
		{
			APPLICATION_DATA.counter_state = counter_reset(APPLICATION_DATA.counter_state);
		}
		else if(!CLK && !RST)
		{
			//State off
			// If CLK is False and reset is FALSE
			//do nothing
		}
		else if(CLK && !RST)
		{
			//State counting
			// If CLK is TRUE and RST is FALSE, Make a count
			// If ACC > Threshold ISR is True, RST is True

			APPLICATION_DATA.counter_state.ACC++;
			if(APPLICATION_DATA.counter_state.ACC >= APPLICATION_DATA.counter_state.TRSHLD)
			{
				APPLICATION_DATA.counter_state.ISR = (boolean)1;
				APPLICATION_DATA.counter_state.RST = (boolean)1;
			}
		}

	//	if(ACC > Threshold)

	return APPLICATION_DATA.counter_state;
}

counter_t counter_step()
{

	APPLICATION_DATA.counter_state = counter_state_machine(APPLICATION_DATA.counter_state.CLK,APPLICATION_DATA.counter_state.RST);

	return APPLICATION_DATA.counter_state;
}
