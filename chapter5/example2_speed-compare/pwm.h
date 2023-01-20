#ifndef _PWM_H
#define _PWM_H

#include <stdint.h>

#define PWM_STACK_SIZE 64

/**
 * 
 * pin: the pin this cog will take over and output PWM on
 * 
 */
struct pwm_mailbox {
	uint8_t pin;
};

#endif

