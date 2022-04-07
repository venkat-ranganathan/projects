#define F_CPU 1000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

int main()
{
    DDRD = 0xFF;

    while(1)
    {
        PORTA = PINA;
        PORTB = PINB;
        PORTD = PINA | PINB;
    }

    return 0;
}

