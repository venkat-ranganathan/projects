#include "usbcdc.h"
#include "uclib.h"
#include "i2c0.h"
#include <stdbool.h>
#include <stdio.h>
#include <rp2040/i2c.h>

int main()
{
    char c;
    configure_i2c0();
    configure_usbcdc();

    int16_t a_x = 0;
    int16_t a_y = 0;
    int16_t a_z = 0;

    while(1)
    {
        if(usbcdc_getchar(&c))
        {
            uint16_t data;
            uint16_t transaction[8];
            switch(c)
            {
            _Bool flag;
            case 'w':
                transaction[0]=0x0f; 
                transaction[1]=I2C_READ|I2C_STOP;
                if(i2c0_do_transaction(0x19,2,transaction))
                    print_string("WhoamI sent \n\r");
                else
                    print_string("WhoamI not sent \n\r");
                break;
            case 's':
                transaction[0]=0x27; 
                transaction[1]=I2C_READ|I2C_RESTART|I2C_STOP;
                if(i2c0_do_transaction(0x19,2,transaction))
                    print_string("Status sent \n\r");
                else
                    print_string("Status not sent \n\r");
                break;
            case 'r':
                do
                {
                   if((flag=i2c0_get_data(&data)))
                   {
                    print_string("\nRead ByteL: 0x");
                    print_hex(2,data);
                    print_string("\n\r");
                   }
                   else print_string("No more data\n\r");
                } while(flag);
                break; 
            case 'a':
                transaction[0]=0xA8; // address 8 auto inc
                transaction[1]=I2C_READ|I2C_RESTART;
                transaction[2]=I2C_READ;
                transaction[3]=I2C_READ;
                transaction[4]=I2C_READ;
                transaction[5]=I2C_READ;
                transaction[6]=I2C_READ|I2C_STOP;
                if(i2c0_do_transaction(0x19,7,transaction))
                    print_string("Requested 6B Accel Data \n\r");
                break;
            case 'x':
                transaction[0]=0xA8;
                transaction[1]=I2C_READ | I2C_RESTART;
                transaction[6]=I2C_READ | I2C_STOP;
                if(i2c0_do_transaction(0x19,3,transaction))
                    print_string("Requested 6B Accel Data \n\r");

                a_x = i2c0_get_data(&data);

                if (a_x < 0)
                    a_x = -a_x;
                a_x = (a_x * 10000 + 5) >> 14; 

                usbcdc_putchar(div10(a_x)+0);

                print_string(div10(a_x)+0);
                print_string(mod10(a_x)+0);

                break;
            case 'y':
                transaction[0]=0xAA;
                transaction[1]=I2C_READ | I2C_RESTART;
                transaction[6]=I2C_READ | I2C_STOP;
                if(i2c0_do_transaction(0x19,3,transaction))
                    print_string("Requested 6B Accel Data \n\r");
                
                a_y = i2c0_get_data(&data);

                if (a_y < 0)
                    a_y = -a_y;
                a_y = (a_y * 10000 + 5) >> 14;

                printf("%d\n",div10(a_y));
                printf("%d\n",mod10(a_y));

                break;
            case 'z':
                transaction[0]=0xAC;
                transaction[1]=I2C_READ | I2C_RESTART;
                transaction[6]=I2C_READ | I2C_STOP;
                if(i2c0_do_transaction(0x19,3,transaction))
                    print_string("Requested 6B Accel Data \n\r");
                
                a_z = i2c0_get_data(&data);

                if (a_z < 0)
                    a_z = -a_z;
                a_z = (a_z * 10000 + 5) >> 14;

                printf("%d\n",div10(a_z));
                printf("%d\n",mod10(a_z));

                break;
            case 'p':
                print_hex(8,i2c0 -> ic_raw_intr_stat);
                print_string("\n\r");
                break;
            case 'c':
                transaction[0]=0x80 | 0x20;
                transaction[1]=0x17;
                transaction[2]=0x00; 
                transaction[3]=0x00;
                transaction[4]=0x88;
                transaction[5]=0x00;
                transaction[6]=0x00|I2C_STOP;

                if(i2c0_do_transaction(0x19,7,transaction))
                    print_string("Sent Config\n\r");
                else
                    print_string("Config failed\n\r");
                break;
            }
        }
    }

    return 0;
}