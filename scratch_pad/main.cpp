#include <math.h>
#include <propeller.h>
#include <stdio.h>
#include <stdlib.h>

#include "proplibs/fmath.h"

#define p_STAT1     6
#define p_STAT2     7

// this program tests clock speed setting. see Makefile
int main() {

    DIRA |= 1<<p_STAT1;
    DIRA |= 1<<p_STAT2;

    while(1) {
        OUTA ^= 1<<p_STAT1;
        OUTA ^= 1<<p_STAT2;
        waitcnt(CLKFREQ + CNT);
    }
}