/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 4

The goal of this assignment is to implement the keypad driver and create a finite state machine that outputs the value of the key pressed on the keypad to terminal

The finite state machine is implemented based on what was taught in lecture 9, fsm_switching_interfacing lecture. 

This finite statement machine includes an initial "wait press" state that doesn't proceed until a key is pressed on the keypad; 

followed by a "debounce" state that increments a counter until a set time is elapsed (variable 'N'); 

once the counter is equal to the set elapsed time & the keypad has been pressed, the state will change to check column 0; 

if a key is pressed in column 0, then the key variable will be udpated and the state will be changed to "release"; if there is no key pressed in column 0, it will move to check column 1;

the above process for column 0 is repeated for column 1 and column 2; specifically for column 2, if no keys are pressed in column 2, then the column is reset to 0 and the state changes to "wait press"

the "release" state does not change if a key is pressed; if no keys are pressed, the column is reset to 0 and the state is changed to "wait press"

The watchdog is used to reset the processor based on the specified reset time in the configure_watchdog() function. The systick driver controls the timing of the main loop and prevents the watchdog from reseting the processor by feeding the watchdog timer

the blocking function is used to test the watchdog; blocking function is not needed bc we only want watchdog to reset the processor if something in the program triggers it 

the main function loop has a blocking function to reset the processor; then a conditinoal statement that continues with the code as long as the systick hasn't fired; following that, the finite statement machine function, keypad_input(), is called and the memory address of the variable "key" is passed to the function; the function then updates the value store in the memory address and returns a true/false; lastly, the watchdog is fed; the loop then continues

Program wasn't working because I had my keypad driver keypad_scan_column()'s default state programmed incorrectly -- I was using "sio -> gpio_out_set" when the correct statement is "sio -> gpio_oe_set"

*/

#include "keypad.h"
#include "usbcdc.h"
#include "uclib.h"
#include "systick.h"
#include "watchdog.h"

_Bool keypad_input(uint8_t * key);

char keypad_lookup[12] = {'1', '4', '7', '*', '2', '5', '8', '0', '3', '6', '9', '#'};

int main()
{  
    configure_usbcdc();
    configure_keypad();
    configure_systick();
    configure_watchdog(1500);
    
    uint8_t key;

    while(1)
    {
        if(!systick_has_fired())
            continue;
        if(keypad_input(&key))
        {  
            usbcdc_putchar(keypad_lookup[key]);
        }
        feed_the_watchdog();
    }
    return 0;
}

_Bool keypad_input(uint8_t * key)
{
    static enum{WAIT_PRESS, DEBOUNCE, CHECK_C0, CHECK_C1, CHECK_C2, RELEASE} state = WAIT_PRESS;
    static uint16_t cntr;
    const uint16_t wait_time_ms = 5;
    _Bool retval = false;

    switch(state)
    {
        case WAIT_PRESS:
            if(keypad_get_row() == 0xF)
            {
                state = WAIT_PRESS;
            }
            else
            {
                cntr = 0;
                state = DEBOUNCE;
            }
            break;
        case DEBOUNCE:
            if((keypad_get_row() != 0xF) && (cntr < wait_time_ms))
            {
                cntr++;
            }
            else if ((keypad_get_row() != 0xF) && (cntr >= wait_time_ms))
            {
                keypad_scan_column(0);
                state = CHECK_C0;
            }
            else
            {
                state = WAIT_PRESS;
            }
            break;
        case CHECK_C0:
            if(keypad_get_row() != 0xF)
            {
                retval = true;
                * key = keypad_get_row();
                state = RELEASE;
            }
            else
            {
                keypad_scan_column(1);
                state = CHECK_C1;
            }
            break;
        case CHECK_C1:
            if(keypad_get_row() != 0xF)
            {
                retval = true;
                * key = 4 + keypad_get_row();
                state = RELEASE;
            }
            else
            {
                keypad_scan_column(2);
                state = CHECK_C2;
            }
            break;
        case CHECK_C2:
            if(keypad_get_row() != 0xF)
            {
                retval = true;
                * key = 8 + keypad_get_row();
                state = RELEASE;
            }
            else
            {
                keypad_scan_column(0xF);
                state = WAIT_PRESS;
            }
            break;
        case RELEASE:
            if(keypad_get_row() != 0xF)
            {
                state = RELEASE;
            }
            else
            {
                keypad_scan_column(0xF);
                state = WAIT_PRESS;
            }
            break;
    }
    return retval;
}