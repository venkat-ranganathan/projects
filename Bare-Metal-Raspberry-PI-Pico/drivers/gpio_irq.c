#include "gpio_irq.h"

void register_gpio_irq_callback(uint8_t gpio, void (*pf) ())
{
    resets -> clr_reset = GPIO_IRQ_RESETS;
    while((resets -> reset_done & GPIO_IRQ_RESETS) != GPIO_IRQ_RESETS)
        continue;
    callback[num_registered_callbacks] = pf;
    callback_gpio_loc[num_registered_callbacks] = gpio;
    num_registered_callbacks++;
    (( void (**) () ) m0plus -> vtor) [16+13] = gpio_irq_handler;
    m0plus -> nvic_ipr3 = (m0plus -> nvic_ipr3 & ~M0PLUS_NVIC_IPR3_IP_13_MASK) | M0PLUS_NVIC_IPR3_IP_13(GPIO_IRQ_PRIO);
    m0plus -> nvic_iser = (1<<13);
}

void __attribute__((isr)) gpio_irq_handler()
{
    uint32_t volatile *p_irq_status=&(io_bank0->proc0_ints0);
    uint32_t volatile *p_irq_ack=&(io_bank0 -> intr0);

    m0plus -> nvic_icpr = (1<<13);

    for( uint8_t i = 0; i < num_registered_callbacks; i++)
    {
        uint8_t gpio = callback_gpio_loc[i];
        uint8_t reg = gpio/8; // to get register index
        uint32_t mask = 0xf << ((gpio%8)*4); // generates mask
        if( p_irq_status[reg] & mask)
        {
            callback[i]();
            p_irq_ack[reg] = mask;
        }
    }
}


