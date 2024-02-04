#include <stdint.h>
#include <stdio.h>

uint16_t div10(uint16_t x)
{
    return (x*0x199a)>>16;
}

uint16_t mod10(uint16_t x)
{
    return x-div10(x)*10;
}

int main()
{
    printf("%%d\n", div10(1994));
    printf("%%d\n", mod10(1994));

    return 0;
}