/* Low-level driver for NHD-0216K1Z wired in 4-Bit mode.
 *
 */
#include "lcd.h"
#include <rp2040/resets.h>
#include <rp2040/sio.h>
#include <rp2040/io_bank0.h>
#include <rp2040/pads_bank0.h>
#include <stdint.h>
#include <stdbool.h>

/*Important: This driver is written under the assumption that the LCD data bus
 * is mapped to four consecutive GPIO pins to facilitate bus writes
 */
#define DB4_LOC 18
#define DB5_LOC 19
#define DB6_LOC 20
#define DB7_LOC 21
#define E_LOC 17
#define RS_LOC 16

#define CONCAT2(x,y) x##y
#define CONCAT3(x,y,z) x##y##z
#define GPIO(x) CONCAT2(gpio,x)
#define GPIO_CTRL(x) CONCAT3(gpio,x,_ctrl)

#ifndef LCD_FIFO_SIZE
#define LCD_FIFO_SIZE 64
#endif

static uint32_t next_tail();
static uint32_t next_head();
static _Bool lcd_buffer_empty();
static _Bool lcd_buffer_full();
static _Bool lcd_command_or_data(_Bool is_cmd, uint8_t value);

void configure_lcd()
{
    resets -> clr_reset =
		RESETS_RESET_IO_BANK0_MASK | RESETS_RESET_PADS_BANK0_MASK;

    while(! (resets -> reset_done & RESETS_RESET_IO_BANK0_MASK))
		continue;

	while(! (resets -> reset_done & RESETS_RESET_PADS_BANK0_MASK))
		continue;

    uint32_t const out_pads_bank0_gpio = 
	PADS_BANK0_GPIO25_OD(0) 
	| PADS_BANK0_GPIO25_IE(0) 
	| PADS_BANK0_GPIO25_DRIVE(0) 
	| PADS_BANK0_GPIO25_PUE(0) 
	| PADS_BANK0_GPIO25_PDE(0) 
	| PADS_BANK0_GPIO25_SCHMITT(0) 
	| PADS_BANK0_GPIO25_SLEWFAST(0);

    uint32_t const out_io_bank0gpio_ctrl = 
	IO_BANK0_GPIO25_CTRL_IRQOVER(0) |
	IO_BANK0_GPIO25_CTRL_INOVER(0)  |
	IO_BANK0_GPIO25_CTRL_OEOVER(0)  |
	IO_BANK0_GPIO25_CTRL_OUTOVER(0) |
	IO_BANK0_GPIO25_CTRL_FUNCSEL(5);

	pads_bank0 -> GPIO(E_LOC) = out_pads_bank0_gpio;
	pads_bank0 -> GPIO(DB4_LOC) = out_pads_bank0_gpio;
	pads_bank0 -> GPIO(DB5_LOC) = out_pads_bank0_gpio;
	pads_bank0 -> GPIO(DB6_LOC) = out_pads_bank0_gpio;
	pads_bank0 -> GPIO(DB7_LOC) = out_pads_bank0_gpio;
	pads_bank0 -> GPIO(RS_LOC) = out_pads_bank0_gpio;
	io_bank0 -> GPIO_CTRL(RS_LOC) = out_io_bank0gpio_ctrl;
	io_bank0 -> GPIO_CTRL(E_LOC) = out_io_bank0gpio_ctrl;
	io_bank0 -> GPIO_CTRL(DB4_LOC) = out_io_bank0gpio_ctrl;
	io_bank0 -> GPIO_CTRL(DB5_LOC) = out_io_bank0gpio_ctrl;
	io_bank0 -> GPIO_CTRL(DB6_LOC) = out_io_bank0gpio_ctrl;
	io_bank0 -> GPIO_CTRL(DB7_LOC) = out_io_bank0gpio_ctrl;
	sio->gpio_out_clr = (0xf<<DB4_LOC) | (1<<RS_LOC) | (1<<E_LOC);
	sio->gpio_oe_set =  (0xf<<DB4_LOC) | (1<<RS_LOC) | (1<<E_LOC);
	lcd_command(0x33);
	lcd_command(0x32);
	lcd_command(0x28);
	lcd_command(0x10);
	lcd_command(0x0f);
	lcd_command(0x06);
	lcd_command(0x01);
}

static void lcd_output_nibble( uint8_t data)
{
	sio->gpio_out = (sio->gpio_out & ~(0xf<<DB4_LOC)) | (data&0xf)<<DB4_LOC;
}
static void lcd_set_e()
{
	sio->gpio_out_set = (1<<E_LOC);
}
static void lcd_clr_e()
{
	sio->gpio_out_clr = (1<<E_LOC);
}

static void lcd_set_rs()
{
	sio->gpio_out_set = (1<<RS_LOC);
}
static void lcd_clr_rs()
{
	sio->gpio_out_clr = (1<<RS_LOC);
}

static struct display_data{
	_Bool is_cmd;
	uint8_t value;
} lcd_buffer[LCD_FIFO_SIZE];

static uint32_t head,tail; // static has internal linkage

static uint32_t next_tail() { return (tail+1)%LCD_FIFO_SIZE;}
static uint32_t next_head() { return (head+1)%LCD_FIFO_SIZE;}
static _Bool lcd_buffer_empty() {return head == tail;}

static _Bool lcd_command_or_data(_Bool is_cmd, uint8_t value)
{
	if(!lcd_buffer_full())
	{
		lcd_buffer[head].is_cmd=is_cmd;
		lcd_buffer[head].value=value;
		head=next_head();
		return true;
	}
	return false;
}

_Bool lcd_command(uint8_t command)
{
	return lcd_command_or_data(true, command);
}

_Bool lcd_putchar(char data)
{
	return lcd_command_or_data(false, data);
}

void lcd_fsm()
{
	static enum {RESET,IDLE,CMD1,CMD2,CMD3} state=RESET;
	static uint8_t cntr=50;

	switch (state)
	{
		case RESET:
			cntr--;
			if(cntr==0)
				state=IDLE;
			break;
		case IDLE:
			if(!lcd_buffer_empty())
			{
				if(lcd_buffer[tail].is_cmd)
					lcd_clr_rs();
				else
					lcd_set_rs();
				lcd_output_nibble((lcd_buffer[tail].value)>>4);
				state=CMD1;
				cntr=2;
				break;
			}
			break;
		case CMD1:
			lcd_set_e();
			state=CMD2;
			break;
		case CMD2:
			lcd_set_e();
			state=CMD3;
			break;
		case CMD3:
			if(--cntr != 0)
			{
				state=CMD1;
				lcd_output_nibble(lcd_buffer[tail].value);
			}
			else
			{
				state=IDLE;
				tail=next_tail();
			}
			break;
	}
	return;
}
