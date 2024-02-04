#include "systick.h"
#include "lcd.h"
#include "led.h"
#include "watchdog.h"
#include <stdbool.h>
#include <stdint.h>

const char hello_str[] = "Hello World!";
const char init_str[] = {0x33, 0x32, 0x28, 0x10, 0x0f, 0x06, 0x02, 0x00};

int main(void)
{
    uint16_t cnt = 0;
    uint8_t lcd_data;
    _Bool lcd_ready = false;
    _Bool lcd_is_cmd = true;
    _Bool initializing_lcd = true;
    char const *ptr = init_str;

    configure_led();
    configure_systick();
    configure_watchdog(1500);
    configure_lcd();

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