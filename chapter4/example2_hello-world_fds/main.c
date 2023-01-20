#include <propeller.h>
#include <stdio.h>

extern _Driver _FullDuplexSerialDriver;

_Driver *_driverlist[] = {
  &_FullDuplexSerialDriver,
  NULL
};

void main() {
	stdin->_flag |= _IONONBLOCK;
	stdin->_flag &= ~_IOCOOKED;

	char buf[64] = {0};
	while(1) {
		waitcnt(CNT + CLKFREQ*2);
		fgets(buf, sizeof(buf), stdin);
		printf("while waiting, I received: %s\n", buf);
	}
}