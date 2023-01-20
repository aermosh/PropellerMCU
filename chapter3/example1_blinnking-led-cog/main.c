#include <propeller.h>

#define p_LED 16

unsigned stack1[64];
unsigned stack2[64];
unsigned stack3[64];

struct led_param_t {
	uint8_t pin;
	uint32_t delay_time;
};

void blink_led(void* par) {
	struct led_param_t *led = par;

	DIRA |= 1 << led->pin; 

	while (1) {
		OUTA ^= 1 << led->pin;
		waitcnt(CNT + led->delay_time);
	}
}

void main() {
	struct led_param_t led1 = {19, CLKFREQ/2};
	struct led_param_t led2 = {20, CLKFREQ/3};
	struct led_param_t led3 = {21, CLKFREQ/5};

	cogstart(blink_led, &led1, stack1, sizeof(stack1));
	cogstart(blink_led, &led2, stack2, sizeof(stack2));
	cogstart(blink_led, &led3, stack3, sizeof(stack3));

	while(1);

}
