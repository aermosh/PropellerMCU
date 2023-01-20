#ifndef _PWM_H
#define _PWM_H

#include <stdint.h>

#define PWM_STACK_SIZE 64

/**
 * 
 * pin: the pin this cog will take over and output PWM on
 * duty_cycle: Duty cycle (in units of percent*10) of the output wave
 * freq: Frequency (in Hz) of the PWM wave.
 * 
 */
struct pwm_mailbox {
	uint8_t pin;
	uint32_t duty_cycle;
	uint32_t freq;
};

#endif

