/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville

*/

#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <rp2040/watchdog.h>
#include <rp2040/psm.h>
#include <stdint.h>

void configure_watchdog(uint32_t reload);
void feed_the_watchdog();

#endif