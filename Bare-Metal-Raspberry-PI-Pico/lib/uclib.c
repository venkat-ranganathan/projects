/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 2

assignment relevant notes:

print_string function used in similar fashion to printf, uses usbcdc_putchar from usbcdc.c/h

print_hex function takes in a hex address and its size, then prints it to the minicom terminal run on the Raspberry Pi Pico

hex_dump function uses both print_string and print_hex functions

starting memory address' LSB is lowered by a factor of eight and set as "addr". "end_addr" is the starting address plus the bytes

if byte is set to zero program ends

while loop runs runs until the end address is reached

primary for loop prints the current memory address, enters a tab, then executes the secondary for loop. Secondary loop prints two bytes of the address at a time, separated by a space, and runs eight times to print 16 bytes

after for loops a print_string produces a new line, then addr is incremented by one and the while loop continues. the proecss is repeated until the ending address is reached

*/

// preprocessor directives
#include <uclib.h>

static uint32_t random_number_state;

uint16_t rand() //LCG based on ANSI C
{
    random_number_state= (1103515245*random_number_state+12345)&0x7fffffff;
    return random_number_state>>16;
}

void srand(uint32_t x)
{
    random_number_state=x;
}

void print_string(char const * str)
{
    while(*str && usbcdc_putchar(*str++))
        continue;
}

void print_hex(uint8_t num_digits, uint32_t value)
{
    int8_t i;

    if( num_digits > 8)
        num_digits = 8;
    
    for(i = num_digits-1; i>=0; i--)
    {
        uint8_t hex_digit=(value>>4*i)&0xf;
        usbcdc_putchar(hex_digit+((hex_digit<10)?'0':'A'-10));
    }
}

void hex_dump(uint32_t start, uint8_t bytes)
{
    uint32_t addr = start & 0xFFFFFFF8;
    uint32_t end_addr = addr + bytes;

    if(bytes==0)
        return;

    while(addr < end_addr)
    {
        for (uint8_t i = 0; i < bytes; i++)
        {
            print_string("0x");
            print_hex(16,addr);
            print_string("  ");

            for (uint8_t j = 0; j < 8; j++)
            {
                print_hex(2,*(uint8_t *)addr<<j);
                print_string(" ");
            }

            print_string("\n\r");
            addr++;
        }
    }
}

uint16_t div10(uint16_t x)
{
    // return x/10;
    return (x*0x199a)>>16;
}

uint16_t mod10(uint16_t x)
{
    // return x%10, leaves fractional part 1994 computed to 1990
    return x-div10(x)*10;
}

