#include "uart0.h"

#ifndef NUM_CALLBACKS
#define NUM_CALLBACKS 5
#endif

static uint16_t rx_data;
static _Bool rx_data_received;
static _Bool rx_data_sent;

static uint16_t tx_data;
static _Bool tx_data_received;
static _Bool tx_data_sent;

static void (*callback[NUM_CALLBACKS])();
static uint32_t num_callbacks;

char tdata;

_Bool uart0_register_callback(void (*p_fn)())
{
    if(NUM_CALLBACKS == num_callbacks)
        return false;
    callback[num_callbacks++]=p_fn;
    return true;
}

void configure_uart()
{
    // first enable peripheral clock for clk_sys 125 MHz
   clocks->clk_peri_ctrl=CLOCKS_CLK_PERI_CTRL_AUXSRC(0) 
   | CLCOKS_CLK_PERI_CTRL_ENABLE(1);


    // bring UART and PADS out of reset
    resets->clr_reset = RESETS_RESET_UART0_MASK 
    | RESETS_RESET_PADS_BANK0_MASK;

    while(! (resets -> reset_done & RESETS_RESET_UART0_MASK))
        continue;
    
    while(! (resets -> reset_done & RESETS_RESET_PADS_BANK0_MASK))
        continue;

    // configure TX/RX pins
    uart0_tx -> gpio1 = 
	UART0_UARTCR_CTSEN(0) 
	| UART0_UARTCR_RTSEN(0) 
	| UART0_UARTCR_OUT2(0) 
	| UART0_UARTCR_OUT1(0) 
	| UART0_UARTCR_RTX(0) 
	| UART0_UARTCR_DTR(0) 
	| UART0_UARTCR_RXE(0)
    | UART0_UARTCR_TXE(1)
    | UART0_UARTCR_LBE(1)
    | UART0_UARTCR_UARTEN(1);

    uart0_rx -> gpio2 = 
	UART0_UARTCR_CTSEN(0) 
	| UART0_UARTCR_RTSEN(0) 
	| UART0_UARTCR_OUT2(0) 
	| UART0_UARTCR_OUT1(0) 
	| UART0_UARTCR_RTS(0) 
	| UART0_UARTCR_DTR(0) 
	| UART0_UARTCR_RXE(1)
    | UART0_UARTCR_TXE(0)
    | UART0_UARTCR_LBE(1)
    | UART0_UARTCR_UARTEN(1);

    // confiure baud rate
    uart0 -> uartibrd = 1085;

    // configure frame format
    uart0 -> uartfbrd = 4;
}

_Bool uart0_getchar(char *data)
{
    _Bool retval;
    // atomic start
    retval = rx_data_received;

    if(rx_data & 0x300)
        retval=false;
    rx_data_received=false;
    *data=rx_data;
    // atomic end
    return retval;
}

_Bool uart0_putchar(char *data)
{
      _Bool retval;
    // atomic start
    retval = rx_data_sent;

    uint8_t rec_data = uart0->uartdr;
    
    if(rx_data & 0x300)
        retval=false;
    rx_data_sent=false;
    *data=rx_data;
    // atomic end
    return retval;
}

void __attribute__((isr)) UART0_Handler()
{
    // single line sequence with shared variable SV so doesn't need to be atomic
    rx_data_received=true;
    rx_data= uart0 -> uartdr;
}
