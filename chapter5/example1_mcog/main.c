#include <propeller.h>
#include <stdio.h>

#include "pwm.h"

// When we compile an object as a cog object, the compiler generates a symbol for us
// that we use to reference where the start of the cog code is in memory. We use "extern"
// to let the compiler know that this symbol will exist at the linking stage of the program
extern unsigned int _load_start_pwm_cog[];
// We also need to define a stack for the cog. The size of the stack should be the size 
// required by the cog plus 1. 
static unsigned stack_pwm[PWM_STACK_SIZE + 1];

// Lastly, we define an instance of the mailbox struct for the cog. We make it volatile so
// that the compiler doesn't try to optimize it away because it looks like we don't do anything
// meaningful with it in this source file. 
volatile struct pwm_mailbox pwm_par; 

void main() {

	pwm_par.pin = 0; // use pin 0
	pwm_par.duty_cycle = 50; // start with 50% duty cycle
	pwm_par.freq = 9500; // start with a frequnecy of 9.5KHz (max)

	// set the first thing in the stack to be our mailbox
	stack_pwm[PWM_STACK_SIZE] = (unsigned)&pwm_par;

	// now we start our cog
	cognew(_load_start_pwm_cog, &stack_pwm[PWM_STACK_SIZE]);

	// change the parameters in the mailbox and the cog updates!
	while(1) {
		for (int i = 0; i <= 100; i++) {
			pwm_par.duty_cycle = i;
			waitcnt(CLKFREQ/100 + CNT);
		}

		for (int i = 100; i >= 0; i--) {
			pwm_par.duty_cycle = i;
			waitcnt(CLKFREQ/100 + CNT);
		}
	}
}