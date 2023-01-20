#include <propeller.h>

#define p_LED 16

void main() {
	DIRA |= 1 << p_LED;

	while (1) {
		OUTA ^= 1 << p_LED;
		waitcnt(CNT + CLKFREQ/2);
	}
}