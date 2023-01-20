#include <propeller.h>
#include "pwm.h"

// We need to redefine CLKFREQ here due to a bug in PropGCC with cog files. 
// Supposedly fixed in newer versions?
// http://forums.parallax.com/discussion/152949/newbie-trouble-with-running-multiple-cogs
#undef CLKFREQ
#define CLKFREQ (*(int *)0)

/*
 * PWM Driver: 
 * 
 * The program reads settings out of the mailbox, and creates that PWM wave.
 * Whenever settings change, the output is changed on the next cycle
 *
 */
_NAKED int main(struct pwm_mailbox **ppmailbox) {
		
	struct pwm_mailbox *par = *ppmailbox;

	uint8_t pin = par->pin;
	DIRA |= 1 << pin;

	uint32_t period;
    uint32_t period_calc = CLKFREQ/par->freq;
	uint32_t on_time = (period_calc*par->duty_cycle)/100;

	uint32_t t;
	while(1) {
        // record the starting time of the loop
		t = CNT;

        // safety check: if the on_time is too small, we don't want to cause waitcnt to lock up because 
        // CNT has already passed t+on_time, which will cause the function to block for 53 seconds until CNT 
        // wraps back around
        if (CNT < t+on_time) {
            // output high for on_time counts, minus a few due to the instructions used to set this up
            OUTA |= 1 << pin;
            waitcnt(t+on_time);
        }

        // pin low, Now, we have time to do any kind of set up for the next loop that we can, 
        // such as recalculate the period and HI time of the PWM wave.
        OUTA &= ~(1 << pin);
        period = period_calc;
		on_time = (period*par->duty_cycle)/100;
        period_calc = CLKFREQ/par->freq;

        if (CNT < t+period) {
            // now, wait the remainder of the time for the wave
            waitcnt(t+period);
        }
        
	}
}