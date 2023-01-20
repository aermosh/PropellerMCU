#include <propeller.h>
#include <stdio.h>

#define p_LED 16
#define NCO_SINGLE (0x04 << 26)
#define LOOP_T (CLKFREQ/1000)

void main() {

	// set P16 as output
	DIRA |= 1 << p_LED;

	// setup counter for NCO mode, A pin output is P16
	PHSA = 0;
	FRQA = 1;
	CTRA = NCO_SINGLE | p_LED;

	// setup a loop timer and variables for duty cycle
	uint32_t t = CNT;
	uint32_t duty = 0;
	int32_t sign = 1;
	while(1) {
		// set PHSA to negative of desired "on" time, determined by duty cycle variable
		// we define our duty cycle to be from 0 to 100 (1/10th of a percent)
		PHSA = -duty*(LOOP_T/1000);

		// update duty cycle variable for next loop iteration.
		// This will simply ramp linearly from 0 to 100 back to 0 forever.

		duty += sign;
		if (duty == 1000 || duty == 0) {
			sign *= -1;
		}

		// wait until LOOP_T amount of time has passed since the last time this
		// waitcnt was called. See Example X.X for an explanation of how this works
		waitcnt(t += LOOP_T);
	}

}