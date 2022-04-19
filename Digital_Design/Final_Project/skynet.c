// Ben Telfer and Prasanna Ranganathan
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
#define PWM_TOP 500

void lcd_display(int8_t x, int8_t y, int stage);
void turnright();

int main()
{
    long time = 0;
    long velocity_coefficient = 0;
    long velocity_coefficient_x = 0;
    long velocity_coefficient_y = 0;
    long velocity[] = {0, 500000,
                       450000,
                       171500,
                       150000,
                       140000,
                       135000,
                       125000,
                       120000,
                       115000,
                       110000,
                       107000,
                       105000,
                       103000,
                       102500,
                       101000,
                       100000,
                       97000,
                       95000,
                       94500,
                       94000,
                       93500,
                       93000,
                       92750,
                       92500,
                       92250,
                       92000,
                       91500,
                       91000,
                       90500,
                       90000};

    /* long velocity[1] = 500000;
    long velocity[2] = 450000;
    long velocity[3] = 171500;
    long velocity[4] = 150000;
    long velocity[5] = 140000;
    long velocity[6] = 135000;
    long velocity[7] = 125000;
    long velocity[8] = 120000;
    long velocity[9] = 115000;
    long velocity[10] = 110000;
    long velocity[11] = 107000;
    long velocity[12] = 105000;
    long velocity[13] = 103000;
    long velocity[14] = 102500;
    long velocity[15] = 101000;
    long velocity[16] = 100000;
    long velocity[17] = 97000;
    long velocity[18] = 95000;
    long velocity[19] = 94500;
    long velocity[20] = 94000;
    long velocity[21] = 93500;
    long velocity[22] = 93000;
    long velocity[23] = 92750;
    long velocity[24] = 92500;
    long velocity[25] = 92250;
    long velocity[26] = 92000;
    long velocity[27] = 91500;
    long velocity[28] = 91000;
    long velocity[29] = 90500;
    long velocity[30] = 90000; */
    unsigned int pwm_counter = 0;
    unsigned int duty_cycleL = 100;      // Duty cycle for left motor
    unsigned int duty_cycleR = 102;      // Duty cycle for right motor
    unsigned int rot_time = 12600;       // Controls rotation time when switching axis
    unsigned int aboutface_time = 20000; // Controls turning time?
    unsigned int last_left_button_state = (PINB & (1 << 1));
    unsigned int left_button_pressed = 0;
    unsigned int last_middle_button_state = (PINB & (1 << 4));
    unsigned int middle_button_pressed = 0;
    unsigned int last_right_button_state = (PINB & (1 << 5));
    unsigned int right_button_pressed = 0;
    unsigned int stage = 1; // 1 is choose x, 2 is choose y, 3 is move
    int8_t xcoord = 0;
    int8_t ycoord = 0;
    DDRD |= (1 << 5) | (1 << 6); // Left Motor
    DDRD |= (1 << 3);            // Right Motor
    DDRB |= (1 << 3);            // Right Motor
    DDRB &= ~(1 << 1);           // Configure left push-button input
    PORTB |= (1 << 1);           // enable pull-up resistor
    DDRB &= ~(1 << 4);           // Configure middle push-button input
    PORTB |= (1 << 4);           // enable pull-up resistor
    DDRB &= ~(1 << 5);           // Configure right push-button input
    PORTB |= (1 << 5);           // enable pull-up resistor
    initialize_LCD_driver();
    LCD_execute_command(TURN_ON_DISPLAY);

    while (1)
    {
        //===========================SELECTING COORDS===============================
        if (middle_button_pressed == 1)
        {
            stage++;
        }
        if (stage == 1)
        {
            if (left_button_pressed == 1)
            {
                xcoord--;
            }
            else if (right_button_pressed == 1)
            {
                xcoord++;
            }
        }
        else if (stage == 2)
        {
            if (left_button_pressed == 1)
            {
                ycoord--;
            }
            else if (right_button_pressed == 1)
            {
                ycoord++;
            }
        }
        if (stage != 0)
        {
            lcd_display(xcoord, ycoord, stage);
        }
        //===============================SELECTING APPROPRIATE VELOCITY RATIO=====
        for (int i = 0; i < 31; i++)
        {
            if (xcoord == i)
            {
                velocity_coefficient_x = velocity[i];
            }
            if (ycoord == i)
            {
                velocity_coefficient_y = velocity[i];
            }
        }
        //===============================MOVEMENT=================================
        //================================STAGE 3=================================
        if (stage == 3)
        {
            if (ycoord >= 0)
            {
                // move y
                time = 0;
                _delay_ms(2000);
                while (1)
                {
                    pwm_counter++; // PWM pwm_counter
                    if (pwm_counter >= PWM_TOP)
                    {
                        pwm_counter = 0;
                    }
                    if (pwm_counter < duty_cycleL)
                    {                       // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                        PORTD &= ~(1 << 5); // LEFT
                        PORTD |= (1 << 6);
                    } // LEFT //FORWARD
                    else
                    {
                        PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                    }
                    if (pwm_counter < duty_cycleR)
                    {
                        PORTD &= ~(1 << 3); // RIGHT
                        PORTB |= (1 << 3);
                    } // RIGHT //REVERSE => Turn right
                    else
                    {
                        PORTD &= ~((1 << 3)); // COAST MOTORS
                        PORTB &= ~(1 << 3);
                    }

                    // for below if statement
                    // changed from 100000 to the absolute value of the y coordinate times 100000
                    if (time == (velocity_coefficient_y / 30) * ycoord) // 100000) // this value is second*100000 //eg 5 sec = 500000
                    {
                        break;
                    }
                    time++;
                    _delay_us(10);
                }
                PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                PORTB |= (1 << 3);
            }
            else if (ycoord < 0)
            {
                // 180
                time = 0;
                _delay_ms(1000);
                while (1)
                {
                    pwm_counter++; // PWM pwm_counter
                    if (pwm_counter >= PWM_TOP)
                    {
                        pwm_counter = 0;
                    }
                    if (pwm_counter < duty_cycleL)
                    {                      // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                        PORTD |= (1 << 5); // LEFT
                        PORTD &= ~(1 << 6);
                    } // LEFT //FORWARD
                    else
                    {
                        PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                    }
                    if (pwm_counter < duty_cycleR)
                    {
                        PORTD &= ~(1 << 3); // RIGHT
                        PORTB |= (1 << 3);
                    } // RIGHT //REVERSE => Turn right
                    else
                    {
                        PORTD &= ~((1 << 3)); // COAST MOTORS
                        PORTB &= ~(1 << 3);
                    }
                    if (time == aboutface_time) // this value is second*100000 //eg 5 sec = 500000
                    {
                        break;
                    }
                    _delay_us(10);
                    time++;
                }
                PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                PORTB |= (1 << 3);
                // move y
                time = 0;
                _delay_ms(1000);
                while (1)
                {
                    pwm_counter++; // PWM pwm_counter
                    if (pwm_counter >= PWM_TOP)
                    {
                        pwm_counter = 0;
                    }
                    if (pwm_counter < duty_cycleL)
                    {                       // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                        PORTD &= ~(1 << 5); // LEFT
                        PORTD |= (1 << 6);
                    } // LEFT //FORWARD
                    else
                    {
                        PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                    }
                    if (pwm_counter < duty_cycleR)
                    {
                        PORTD &= ~(1 << 3); // RIGHT
                        PORTB |= (1 << 3);
                    } // RIGHT //REVERSE => Turn right
                    else
                    {
                        PORTD &= ~((1 << 3)); // COAST MOTORS
                        PORTB &= ~(1 << 3);
                    }
                    if (time == (velocity_coefficient_y / 30) * abs(ycoord)) // this value is second*100000 //eg 5 sec = 500000
                    {
                        break;
                    }
                    time++;
                    _delay_us(10);
                }
                PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                PORTB |= (1 << 3);
            }
        }
        //================================STAGE 4====================================
        if (stage == 4)
        {
            if (ycoord >= 0)
            {
                if (xcoord >= 0)
                { // 90 right
                    time = 0;
                    _delay_ms(1000);
                    while (1)
                    {
                        pwm_counter++; // PWM pwm_counter
                        if (pwm_counter >= PWM_TOP)
                        {
                            pwm_counter = 0;
                        }
                        if (pwm_counter < duty_cycleL)
                        {                       // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                            PORTD &= ~(1 << 5); // LEFT
                            PORTD |= (1 << 6);
                        } // LEFT //FORWARD
                        else
                        {
                            PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                        }
                        if (pwm_counter < duty_cycleR)
                        {
                            PORTD |= (1 << 3); // RIGHT
                            PORTB &= ~(1 << 3);
                        } // RIGHT //REVERSE => Turn right
                        else
                        {
                            PORTD &= ~((1 << 3)); // COAST MOTORS
                            PORTB &= ~(1 << 3);
                        }
                        if (time == rot_time) // this value is second*100000 //eg 5 sec = 500000
                        {
                            break;
                        }
                        time++;
                        _delay_us(10);
                    }
                    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                    PORTB |= (1 << 3);
                    stage++;
                }
                else if (xcoord < 0)
                { // 90 left
                    time = 0;
                    _delay_ms(1000);
                    while (1)
                    {
                        pwm_counter++; // PWM pwm_counter
                        if (pwm_counter >= PWM_TOP)
                        {
                            pwm_counter = 0;
                        }
                        if (pwm_counter < duty_cycleL)
                        {                      // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                            PORTD |= (1 << 5); // LEFT
                            PORTD &= ~(1 << 6);
                        } // LEFT //FORWARD
                        else
                        {
                            PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                        }
                        if (pwm_counter < duty_cycleR)
                        {
                            PORTD &= ~(1 << 3); // RIGHT
                            PORTB |= (1 << 3);
                        } // RIGHT //REVERSE => Turn right
                        else
                        {
                            PORTD &= ~((1 << 3)); // COAST MOTORS
                            PORTB &= ~(1 << 3);
                        }
                        if (time == rot_time) // this value is second*100000 //eg 5 sec = 500000
                        {
                            break;
                        }
                        time++;
                        _delay_us(10);
                    }
                    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                    PORTB |= (1 << 3);
                    stage++;
                }
            }
            else if (ycoord < 0)
            {
                if (xcoord >= 0)
                { // 90 left
                    time = 0;
                    _delay_ms(1000);
                    while (1)
                    {
                        pwm_counter++; // PWM pwm_counter
                        if (pwm_counter >= PWM_TOP)
                        {
                            pwm_counter = 0;
                        }
                        if (pwm_counter < duty_cycleL)
                        {                      // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                            PORTD |= (1 << 5); // LEFT
                            PORTD &= ~(1 << 6);
                        } // LEFT //FORWARD
                        else
                        {
                            PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                        }
                        if (pwm_counter < duty_cycleR)
                        {
                            PORTD &= ~(1 << 3); // RIGHT
                            PORTB |= (1 << 3);
                        } // RIGHT //REVERSE => Turn right
                        else
                        {
                            PORTD &= ~((1 << 3)); // COAST MOTORS
                            PORTB &= ~(1 << 3);
                        }
                        if (time == rot_time) // this value is second*100000 //eg 5 sec = 500000
                        {
                            break;
                        }
                        time++;
                        _delay_us(10);
                    }
                    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                    PORTB |= (1 << 3);
                    stage++;
                }
                else if (xcoord < 0)
                { // 90 right
                    time = 0;
                    _delay_ms(1000);
                    while (1)
                    {
                        pwm_counter++; // PWM pwm_counter
                        if (pwm_counter >= PWM_TOP)
                        {
                            pwm_counter = 0;
                        }
                        if (pwm_counter < duty_cycleL)
                        {                       // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                            PORTD &= ~(1 << 5); // LEFT
                            PORTD |= (1 << 6);
                        } // LEFT //FORWARD
                        else
                        {
                            PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                        }
                        if (pwm_counter < duty_cycleR)
                        {
                            PORTD |= (1 << 3); // RIGHT
                            PORTB &= ~(1 << 3);
                        } // RIGHT //REVERSE => Turn right
                        else
                        {
                            PORTD &= ~((1 << 3)); // COAST MOTORS
                            PORTB &= ~(1 << 3);
                        }
                        if (time == rot_time) // this value is second*100000 //eg 5 sec = 500000
                        {
                            break;
                        }
                        time++;
                        _delay_us(10);
                    }
                    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
                    PORTB |= (1 << 3);
                    stage++;
                }
            }
        }
        //=================================STAGE 5====================================
        if (stage == 5)
        { // move x
            time = 0;
            _delay_ms(1000);
            while (1)
            {
                pwm_counter++; // PWM pwm_counter
                if (pwm_counter >= PWM_TOP)
                {
                    pwm_counter = 0;
                }
                if (pwm_counter < duty_cycleL)
                {                       // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
                    PORTD &= ~(1 << 5); // LEFT
                    PORTD |= (1 << 6);
                } // LEFT //FORWARD
                else
                {
                    PORTD &= ~((1 << 5) | (1 << 6)); // COAST MOTORS
                }
                if (pwm_counter < duty_cycleR)
                {
                    PORTD &= ~(1 << 3); // RIGHT
                    PORTB |= (1 << 3);
                } // RIGHT //REVERSE => Turn right
                else
                {
                    PORTD &= ~((1 << 3)); // COAST MOTORS
                    PORTB &= ~(1 << 3);
                }
                if (time == (velocity_coefficient_x / 30) * abs(xcoord)) // this value is second*100000 //eg 5 sec = 500000
                {
                    break;
                }
                time++;
                _delay_us(10);
            }
            PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
            PORTB |= (1 << 3);
            stage++;
        }
        //=========================PULSERS====================================
        // LEFT BUTTON
        if ((PINB & (1 << 1)) != last_left_button_state)
        {
            if ((PINB & (1 << 1)) == 0)
            {
                left_button_pressed = 1;
            }
            last_left_button_state = (PINB & (1 << 1));
        }
        else
        {
            left_button_pressed = 0;
        }
        // MIDDLE BUTTON
        if ((PINB & (1 << 4)) != last_middle_button_state)
        {
            if ((PINB & (1 << 4)) == 0)
            {
                middle_button_pressed = 1;
            }
            last_middle_button_state = (PINB & (1 << 4));
        }
        else
        {
            middle_button_pressed = 0;
        }
        // RIGHT BUTTON
        if ((PINB & (1 << 5)) != last_right_button_state)
        {
            if ((PINB & (1 << 5)) == 0)
            {
                right_button_pressed = 1;
            }
            last_right_button_state = (PINB & (1 << 5));
        }
        else
        {
            right_button_pressed = 0;
        }
        //===========================DELAY==================================
        _delay_us(10);
    }
    return 0;
}

//==========================FUNCTIONS================================
void lcd_display(int8_t x, int8_t y, int stage)
{
    char char_x[8];
    char char_y[8];
    char char_s[8];
    LCD_execute_command(CLEAR_DISPLAY);
    LCD_move_cursor_to_col_row(0, 0);
    sprintf(char_x, "X:%2d", x);
    LCD_print_String(char_x); // Prints X Coord
    LCD_move_cursor_to_col_row(0, 1);
    sprintf(char_y, "Y:%2d", y);
    LCD_print_String(char_y); // Prints Y coord
    LCD_move_cursor_to_col_row(6, 1);
    sprintf(char_s, "%2d", stage);
    LCD_print_String(char_s); // Prints Y coord
    _delay_ms(50);
}

/*
//////////////////RIGHT TURN/////////////////
    _delay_ms(1000);
    while(1)
    {
        pwm_counter++; // PWM pwm_counter
        if (pwm_counter >= PWM_TOP) {
            pwm_counter = 0;
        }
        if (pwm_counter < duty_cycleL)
        {
            // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
            PORTD &= ~(1 << 5); //LEFT
            PORTD |= (1 << 6); //LEFT //FORWARD
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(pwm_counter < duty_cycleR)
        {
            PORTD |= (1 << 3); //RIGHT
            PORTB &= ~(1 << 3); //RIGHT //REVERSE => Turn right
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(time == 22000) // this value is second*100000 //eg 5 sec = 500000
        {
            break;
        }
        time++;
        _delay_us(10);
    }
    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
    PORTB |= (1 << 3);
    return;
}



//////////////////LEFT TURN/////////////////
    _delay_ms(1000);
    while(1)
    {
        pwm_counter++; // PWM pwm_counter
        if (pwm_counter >= PWM_TOP) {
            pwm_counter = 0;
        }
        if (pwm_counter < duty_cycleL)
        {
            // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
            PORTD |= (1 << 5); //LEFT
            PORTD &= ~(1 << 6); //LEFT //FORWARD
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(pwm_counter < duty_cycleR)
        {
            PORTD &= ~(1 << 3); //RIGHT
            PORTB |= (1 << 3); //RIGHT //REVERSE => Turn right
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(time == 22000) // this value is second*100000 //eg 5 sec = 500000
        {
            break;
        }
        time++;
        _delay_us(10);
    }
    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
    PORTB |= (1 << 3);
    return;
}





//////////////////180 TURN/////////////////
    _delay_ms(1000);
    while(1)
    {
        pwm_counter++; // PWM pwm_counter
        if (pwm_counter >= PWM_TOP) {
            pwm_counter = 0;
        }
        if (pwm_counter < duty_cycleL)
        {
            // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
            PORTD &= ~(1 << 5); //LEFT
            PORTD |= (1 << 6); //LEFT //FORWARD
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(pwm_counter < duty_cycleR)
        {
            PORTD |= (1 << 3); //RIGHT
            PORTB &= ~(1 << 3); //RIGHT //REVERSE => Turn right
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(time == 44000) // this value is second*100000 //eg 5 sec = 500000
        {
            break;
        }
        time++;
        _delay_us(10);
    }
    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
    PORTB |= (1 << 3);
    return;
}

//////////////////FORWARD/////////////////
    _delay_ms(1000);
    while(1)
    {
        pwm_counter++; // PWM pwm_counter
        if (pwm_counter >= PWM_TOP) {
            pwm_counter = 0;
        }
        if (pwm_counter < duty_cycleL)
        {
            // TURN ON MOTORS // CHANGE THIS DEPENDING ON TYPE OF MOVEMENT
            PORTD &= ~(1 << 5); //LEFT
            PORTD |= (1 << 6); //LEFT //FORWARD
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(pwm_counter < duty_cycleR)
        {
            PORTD &= ~(1 << 3); //RIGHT
            PORTB |= (1 << 3); //RIGHT //REVERSE => Turn right
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // COAST MOTORS
            PORTB &= ~(1 << 3);
        }
        if(time == 44000) // this value is second*100000 //eg 5 sec = 500000
        {
            break;
        }
        time++;
        _delay_us(10);
    }
    PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
    PORTB |= (1 << 3);
    return;
}

PORTD &= ~(1 << 5); //LEFT
PORTD |= (1 << 6); //LEFT //FORWARD
PORTD |= (1 << 3); //RIGHT
PORTB &= ~(1 << 3); //RIGHT //REVERSE => Turn right

PORTD |= (1 << 5); //LEFT
PORTD &= ~(1 << 6); //LEFT //REVERSE
PORTD &= ~(1 << 3); //RIGHT
PORTB |= (1 << 3); //RIGHT //FORWARD => Turn left

PORTD &= ~(1 << 5); //LEFT
PORTD |= (1 << 6); //LEFT //FORWARD
PORTD &= ~(1 << 3); //RIGHT
PORTB |= (1 << 3); //RIGHT //FORWARD => move forward

*/
