/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 3

NEED TO press Column: 0, 1, 2
Then HOLD key on keypad for corresponding column 
While HOLDING key on keypad, press SPACE BAR
*/

#include "keypad.h"
#include "usbcdc.h"
#include "uclib.h"

int main()
{
    char c;
    configure_usbcdc();
    configure_keypad();

    while(1)
    {
        if(usbcdc_getchar(&c))
            switch(c)
            {
                case '0':
                    keypad_scan_column(0);
                    break;
                case '1':
                    keypad_scan_column(1);
                    break;
                case '2':
                    keypad_scan_column(2);
                    break;
                case ' ':
                    print_hex(1,keypad_get_row(0));
                    break;
                default:
                    keypad_scan_column(0xF);
                    print_string("\n\r");
            }
    }

    return 0;
}