/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 3

The goal of the program is to test the watchdog and systick drivers using a FSM that flashes the LED at 0.5 Hz (every 2 seconds). The timing of the FSM is controlled by the systick driver which runs the main loop everyone 1000 ms. The blocking function "while(pb_is_pressed());" is used to test the watchdog & reboot the processor by not feeding the watchdog; blocking code executes for an indefinite amount of time as long as the push button is being pressed

*/

#include "led0.h"
#include "pb0.h"
#include "systick.h"
#include "watchdog.h"

// function prototype
void pulse_led_2s();

int main(void)
{
    configure_led();
    configure_pb();
    configure_systick();
    configure_watchdog(1500); // 1500 microseconds = 1.5ms

    while(1)
    {
        while(pb_is_pressed());
        if(!systick_has_fired())
            continue;
        pulse_led_2s();
        feed_the_watchdog();
    }
    return 0;
}

void pulse_led_2s()
{
    static enum{WAIT, LED_ON} state = WAIT;
    static uint16_t cnt;

    switch(state)
    {
        case WAIT:
            if(cnt<999)
                cnt++;
            else
            {
                turn_on_led();
                state=LED_ON;
            }
            break;
        case LED_ON:
            if(cnt<1999)
                cnt++;
            else
            {
                cnt=0;
                turn_off_led();
                state=WAIT;
            }
            break;
    }
}