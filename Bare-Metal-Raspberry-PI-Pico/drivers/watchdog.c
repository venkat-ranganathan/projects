/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville

the watchdog driver has a countdown timer (1500 ms) that restarts the processor if the watchdog isn't fed
*/

#include "watchdog.h"

static uint32_t reload_value;

void configure_watchdog(uint32_t reload)
{
    //DISABLE WD TIMER
    watchdog->clr_ctrl = WATCHDOG_CTRL_ENABLE_MASK;

    //Write WDSEL
    psm->wdsel = 0x0000FFFC;

    //Configure TICK Generator for 1us
    watchdog->tick = WATCHDOG_TICK_CYCLES(12) | WATCHDOG_TICK_ENABLE(1);


    reload_value = reload*2;
    feed_the_watchdog();

    //Enable WD Timer
    watchdog->set_ctrl = WATCHDOG_CTRL_ENABLE_MASK;
}

void feed_the_watchdog()
{
    //Write reload value to WATCHDOG LOAD register
    watchdog->load = reload_value;
}