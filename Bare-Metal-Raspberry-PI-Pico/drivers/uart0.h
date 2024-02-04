#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <rp2040/resets.h>
#include <rp2040/sio.h>
#include <rp2040/io_bank0.h>
#include <rp2040/pads_bank0.h>
#include <rp2040/uart.h>
#include <rp2040/clocks.h>

void configure_uart();
_Bool uart0_getchar(char *data);
_Bool uart0_putchar(char *data);
_Bool uart0_register_callback(void (*p_fn)());
void __attribute__((isr)) UART0_Handler();