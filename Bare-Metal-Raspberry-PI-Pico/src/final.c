#include "uart0.h"
#include "usbcdc.h"
#include "uclib.h"
#include "systick.h"
#include "watchdog.h"

int main()
{  
    configure_usbcdc();
    configure_uart();
    configure_led();
    configure_systick();
    configure_watchdog(1500);
    
    char c;

    while(1)
    {
        if(!systick_has_fired())
            continue;
        if(systick_register_callback(&c))
            continue;
        get_and_clear_isr_flag();

        if(uart0_getchar(&c))
        {  
            uart0_putchar(&c);
            pulse_led_2s();
        }
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