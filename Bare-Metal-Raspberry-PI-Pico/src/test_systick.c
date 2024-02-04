#include "systick.h"
#include "led.h"
#include "watchdog.h"
#include <stdint.h>

int main(void)
{
    uint16_t cnt=0;
    configure_led();
    turn_on_led();
    configure_systick();
    configure_watchdog(1001); // 1001 ms

    while(1)
    {
        if(!systick_has_fired())
            continue;
        if(++cnt==500)
        {
            turn_off_led();
        }
        feed_the_watchdog();
    }

    return 0;
}