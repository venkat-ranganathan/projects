int main(){

// 1) initialize LCD driver
initialize_LCD_driver();

// 2) turn on LCD after startup
LCD_execute_command(TURN_ON_DISPLAY);

// this is your primary main loop
while(1){
	// 8 char string to display character on lcd
	char char_res[8];

	// test variable to display value on lcd
	uint8_t pwm_duty_cycle = 18;

	// 3) clear lcd buffer for refresh new data
	LCD_execute_command(CLEAR_DISPLAY);

	// 4) display on botton line
	LCD_move_cursor_to_col_row(0,0);
	// 5) print char on lcd
	LCD_print_String("This is");

	// display on top line
	LCD_move_cursor_to_col_row(1,1);
	sprintf(char_res, "Num:%2d", pwm_duty_cycle);
	LCD_print_String(char_res);

	// 6) set properly delay as lcd refresh frequency
	_delay_ms(50);

}

return 0;

}
