/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 3
*/

#include "keypad.h"

#define ALL_KEYPAD_COLUMNS 0xff

void configure_keypad()
{
    resets -> clr_reset = 
	    RESETS_RESET_IO_BANK0_MASK
	    | RESETS_RESET_PADS_BANK0_MASK;

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

    uint32_t const out_io_bank0_gpio_ctrl = 
        IO_BANK0_GPIO25_CTRL_IRQOVER(0) |
        IO_BANK0_GPIO25_CTRL_INOVER(0)  |
        IO_BANK0_GPIO25_CTRL_OEOVER(0)  |
        IO_BANK0_GPIO25_CTRL_OUTOVER(0) |
        IO_BANK0_GPIO25_CTRL_FUNCSEL(5);

    // columns 13, 14, 15
    pads_bank0 -> gpio13 = out_pads_bank0_gpio;
    pads_bank0 -> gpio14 = out_pads_bank0_gpio;
    pads_bank0 -> gpio15 = out_pads_bank0_gpio;
    io_bank0 -> gpio13_ctrl = out_io_bank0_gpio_ctrl;
    io_bank0 -> gpio14_ctrl = out_io_bank0_gpio_ctrl;
    io_bank0 -> gpio15_ctrl = out_io_bank0_gpio_ctrl;

     uint32_t const in_pads_bank0_gpio = 
        PADS_BANK0_GPIO25_OD(0) 
        | PADS_BANK0_GPIO25_IE(1) 
        | PADS_BANK0_GPIO25_DRIVE(0) 
        | PADS_BANK0_GPIO25_PUE(1) 
        | PADS_BANK0_GPIO25_PDE(0) 
        | PADS_BANK0_GPIO25_SCHMITT(0) 
        | PADS_BANK0_GPIO25_SLEWFAST(0);

    uint32_t const in_io_bank0_gpio_ctrl = 
        IO_BANK0_GPIO25_CTRL_IRQOVER(0) |
        IO_BANK0_GPIO25_CTRL_INOVER(0)  |
        IO_BANK0_GPIO25_CTRL_OEOVER(0)  |
        IO_BANK0_GPIO25_CTRL_OUTOVER(0) |
        IO_BANK0_GPIO25_CTRL_FUNCSEL(5);

    // rows 10, 11, 12, 13
    pads_bank0 -> gpio9 = in_pads_bank0_gpio;
    pads_bank0 -> gpio10 = in_pads_bank0_gpio;
    pads_bank0 -> gpio11 = in_pads_bank0_gpio;
    pads_bank0 -> gpio12 = in_pads_bank0_gpio;
    io_bank0 -> gpio9_ctrl = in_io_bank0_gpio_ctrl;
    io_bank0 -> gpio10_ctrl = in_io_bank0_gpio_ctrl;
    io_bank0 -> gpio11_ctrl = in_io_bank0_gpio_ctrl;
    io_bank0 -> gpio12_ctrl = in_io_bank0_gpio_ctrl;

    keypad_scan_column(ALL_KEYPAD_COLUMNS);
}

void keypad_scan_column(uint8_t col)
{
     sio -> gpio_oe_clr = (1 << 13) | (1 << 14) | (1 << 15);
     sio -> gpio_out_clr = (1 << 13) | (1 << 14) | (1 << 15);
     
    switch(col)
    {
        case 0:
            sio -> gpio_oe_set = (1 << 13);
            break;
        case 1:
            sio -> gpio_oe_set = (1 << 14);
            break;
        case 2:
            sio -> gpio_oe_set = (1 << 15);
            break;
        default:
            sio -> gpio_oe_set = (1 << 13) | (1 << 14) | (1 << 15);
            break;
    }
}

uint8_t keypad_get_row()
{
    uint32_t row = sio -> gpio_in & ((1 << 9)|(1 << 10)|(1 << 11)|(1 << 12));

    switch(row)
    {
        case 0xE<<9: // E = 1110, shifted left by 10
            return 0;
        case 0xD<<9: // D = 1101
            return 1;
        case 0xB<<9: // B = 1011
            return 2;
        case 0x7<<9: // 7 = 0111
            return 3;
        default:
            return 0xf;
    }
}