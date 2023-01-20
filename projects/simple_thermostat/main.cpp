#include "global.h"

#include "proplibs/dht11.h"

#define T_UPPER     f16_t(21.1f) // 70 F
#define T_LOWER     f16_t(15.6f) // 60 F

DHT11 temp_sensor(p_T_SENSE);

void cooler_on() {
    printf("turning on cooler\n");
    OUTA |= 1 << p_RELAY;
}

void cooler_off() {
    printf("turning off cooler\n");
    OUTA &= ~(1 << p_RELAY);
}

int main() {

    printf("Start Simple Thermostat\n");

    DIRA |= 1 << p_RELAY;
    cooler_off();

    // very simple bang-bang controller
    // if temp is above threshold, turn off the coo
    while(1) {
        temp_sensor.read();
        printf("Current temperature: %f\n", (float)temp_sensor.T);
        if (temp_sensor.T > T_UPPER) {
            cooler_on();
        }

        if (temp_sensor.T < T_LOWER) {
            cooler_off();
        }
        waitcnt(CLKFREQ*10 + CNT);
    }
}