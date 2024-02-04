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
			//for(uint8_t i=0; i<10; i++)
			//{
				print_hex(16, 0x2000000A);
				print_string("\n\r");
			//}
		}
	}
	return 0;
}
