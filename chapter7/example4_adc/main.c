#include <propeller.h>
#include <stdio.h>

#define p_IN				25
#define p_FB				27
#define CTR_POS_FB			0x09

#define ADC_SAMPLE_T		(1<<14)
#define ADC_FILT_BITS		2

// Some calibration values
#define MIN_VAL 			270
#define MAX_VAL				884

uint32_t sample_adc() {
	uint32_t acc;
	uint32_t t = CNT;
	acc = PHSA;
	waitcnt(t + ADC_SAMPLE_T);
	acc = PHSA-acc;
	return acc>>ADC_FILT_BITS;
}

int32_t get_adc_voltage() {
	int32_t r = sample_adc();
	int32_t val = ((r-MIN_VAL)*(ADC_SAMPLE_T>>ADC_FILT_BITS))/(MAX_VAL-MIN_VAL);

	return (3300*val)/(ADC_SAMPLE_T>>ADC_FILT_BITS);
}

void main() {

	FRQA = 1;
	CTRA = (CTR_POS_FB << 26) | (p_FB << 9) | p_IN;
	DIRA |= 1 << p_FB;

	// FRQB = 0x8000000;
	// CTRB = (0x04 << 26) | 26;
	// DIRA |= 1 << 26;

	stdin->_flag &= ~_IOCOOKED;

	printf("press 'g' to read out 10 values\n");
	while (1) {
		if (getchar() == 'g') {
			for (int i = 0; i < 10; i++) {
				int32_t r = sample_adc();
				printf("%d, ", r);

				waitcnt(CLKFREQ/100 + CNT);
			}
			printf("\n");
		}
	}
}