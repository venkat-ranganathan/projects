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
