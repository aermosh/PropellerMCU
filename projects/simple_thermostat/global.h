#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <propeller.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* Pin Definitions */

#define p_T_SENSE           0
#define p_RELAY             15

#define p_I2C_SCL           28 // there will be a reserved i2c address.
#define p_I2C_SDA           29
#define p_UART_TX           30
#define p_UART_RX           31

/* Address Definitions (if any) */


/* Global Constants */

/* Macros */

#define reset() __builtin_propeller_clkset(0x80)

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define US_TO_CLOCK_TICKS(x) ((CLKFREQ/1000000)*(x)) // divide first to avoid overflow
#define CLOCK_TICKS_TO_US(x) ((x)/(CLKFREQ/1000000))

// replace printf definition if not allowing debug printing
#ifdef SILENCE_PRINT
    #define fprintf(...)
    #define printf(...)
#endif

#endif