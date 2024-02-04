#include "systick.h"
#include "lcd.h"
#include "led.h"
#include "watchdog.h"
#include <stdbool.h>
#include <stdint.h>

int main(void)
{
    uint16_t cnt=0;
    configure_led();
    configure_systick();
    configure_watchdog(1500);
    configure_lcd();

    lcd_putchar('H');
    lcd_putchar('e');
    lcd_putchar('l');
    lcd_putchar('l');
    lcd_putchar('o');
    lcd_command(0x02); // go home

    while(1)
    {
        if(!systick_has_fired())
            continue;
        if(++cnt ==500)
        {
            toggle_led();
            cnt=0;
        }

        lcd_fsm();
        feed_the_watchdog();
    }

    return(0);
}