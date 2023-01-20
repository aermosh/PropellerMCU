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
    uint32_t p_hi = 1 << pin;
    uint32_t p_lo = ~p_hi;

	while(1) {
        OUTA |= p_hi;
        OUTA &= p_lo;
	}
}