/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 2

Program takes in a memory address, its size then outputs a hex dump of starting to ending location

*/

#include "usbcdc.h"
#include "uclib.h"

int main()
{
	char c;
	configure_usbcdc();

	while(1)
	{
		if(usbcdc_getchar(&c))
		{
				hex_dump(0x200006a6,16);
				print_string("\n\r");
		}
	}
	return 0;
}