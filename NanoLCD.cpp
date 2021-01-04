#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "hypeglyphs.h"
#include "state_mach.h"
#include "welcome.h"

// initialize the library with the numbers of the interface pins
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


state curr_state = INIT;

//user requests
int req;



int main (void) {
	init();

	pinMode(LED_BUILTIN, OUTPUT);


	Serial.begin(9600);

	lcd.createChar(0, cr_glyph);

	//set up the LCD's number of columns and rows
	lcd.begin(16, 2);



	switch (curr_state) {
		case INIT:
			req = welcome_user(lcd);
			break;
	}


	return 0;
}



