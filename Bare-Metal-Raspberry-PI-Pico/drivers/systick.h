/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville

*/

#ifndef SYSTICK_H
#define SYSTICK_H

#include <rp2040/m0plus.h>
#include <stdbool.h>

void configure_systick();
_Bool systick_has_fired();
void __attribute__((isr)) SystickHandler();
_Bool systick_register_callback(void (*p_fn)());
_Bool get_isr_flag();
_Bool clear_isr_flag();
_Bool get_and_clear_isr_flag();


#endif