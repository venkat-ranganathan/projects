#include "lcd_driver.h"

int main()
{
    int x = 0;
    char xchar[6];

    itoa(x, xchar, 10);

    initialize_LCD_driver();
    LCD_execute_command(TURN_ON_DISPLAY);
    LCD_execute_command(CLEAR_DISPLAY);

    LCD_print_String(xchar);

    return 0;
}