F_CPU = 20000000
MCU = atmega328p
CCOPTS= -g -Wall -Os -std=c99

default: compile

all: program

compile: lcd.c  
	avr-gcc  $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o lcd -g lcd.c lcd_driver.o
	    
hex: compile
	avr-strip lcd
	avr-objcopy -R .eeprom -O ihex lcd lcd.hex

program: hex
	avrdude -p m328p -c avrisp2 -P COM5 -U flash:w:lcd.hex

clean:
	rm lcd lcd.hex

PWM: pwm.c
	avr-gcc  $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o pwm -g pwm.c lcd_driver.o
	avr-strip pwm
	avr-objcopy -R .eeprom -O ihex pwm pwm.hex
	avrdude -c avrisp2 -P COM5 -p m328p -U flash:w:pwm.hex 
	rm pwm pwm.hex
	 
LCD: lcd.c
	avr-gcc  $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o lcd -g lcd.c lcd_driver.o
	avr-strip lcd
	avr-objcopy -R .eeprom -O ihex lcd lcd.hex
	avrdude -c avrisp2 -P COM5 -p m328p -U flash:w:lcd.hex 
	rm lcd lcd.hex
	
MOTOR: main.c
	avr-gcc  $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o main -g main.c lcd_driver.o
	avr-strip main
	avr-objcopy -R .eeprom -O ihex main main.hex
	avrdude -c avrisp2 -P COM5 -p m328p -U flash:w:main.hex 
	rm main main.hex
	