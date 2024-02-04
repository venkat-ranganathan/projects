/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 5

*/

#include "systick.h"
#include "lcd.h"
#include "led.h"
#include "watchdog.h"
#include <stdbool.h>
#include <stdint.h>

const char  *hello_str = "Hello World!";
const char init_str[] = {0x33, 0x32, 0x28, 0x10, 0x0f, 0x06, 0x02, 0x00};

int main(void)
{
    uint16_t cnt = 0;
    uint8_t lcd_data;
    _Bool lcd_ready = false;
    _Bool lcd_is_cmd = true;
    _Bool initializing_lcd = true;
    char const *ptr = init_str;

    _Bool keypad_input(uint8_t * key);

    char keypad_lookup[12] = {'1', '4', '7', '*', '2', '5', '8', '0', '3', '6', '9', '#'};

    configure_led();
    configure_keypad();
    configure_systick();
    configure_watchdog(1500);
    configure_lcd();

    uint8_t key;

    while(1)
    {
       if(!systick_has_fired())
            continue;
        if(++cnt == 500)
        {
            toggle_led();
            cnt=0;
        }

        if(lcd_ready && *ptr)
            ptr++;
    
        if(initializing_lcd)
        {
            if(*ptr == 0)
            {
                initializing_lcd = false;
                ptr = hello_str;
                lcd_is_cmd = false;
            }
        }

        lcd_data = *ptr;
        lcd_ready = lcd_fsm(lcd_is_cmd, lcd_data);

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