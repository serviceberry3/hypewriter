/*
 * console.c
 *
 *  Created on: Jan 15, 2021
 *      Author: nodog
 */
#include "../include/console.h"
#include "../include/keys.h"
#include "../include/arduino.h"


int pins[3] = {0, 1, 2};
int analog_data[3] = {0, 0, 0};

//buffer to hold chars being typed on bottom line
char bottom_line[16] = {};

//keep track of how many chars have been typed on bottom line
int bottom_line_ctr = 0;


//TODO: make lcd a global

void open_console(LiquidCrystal lcd) {
	start_key_processor(lcd);
}

void next_line(LiquidCrystal lcd) {
	lcd.clear();
	lcd.blink();
	lcd.print(bottom_line);
	lcd.setCursor(0, 1);
}


void start_key_processor(LiquidCrystal lcd) {
	lcd.clear();
	lcd.setCursor(0, 1);
	lcd.blink();

	//start in "up" state
	int state = 0;
	char currently_being_pressed = '\0';

	//keypress confirmer for A0 pin
	int locker0 = 0;

	while (1) {
		//get data from all analog pins
		analog_data[0] = analogRead(A0);
		analog_data[1] = analogRead(A1);
		analog_data[2] = analogRead(A2);

		Serial.println(analog_data[0]);


		char key_to_print = (char)key_lookup(pins, analog_data);

		//key down state, wait for key up
		switch (state) {
			//the up state
			case 0:
				//if we notice a key is now being pressed
				if (key_to_print) {
					//set to down state and record key
					state = 1;
					currently_being_pressed = key_to_print;
				}
				break;
			//the down state
			case 1:
				//if we notice the key is now being released
				if (!key_to_print) {
					//wait for at least 50 confirming 0 readings before printing the letter
					locker0++;


					if (locker0 == 50) {
						state = 0;

						//print out the key that was recorded
						lcd.print(currently_being_pressed);

						//add letter to the bottom line buffer
						bottom_line[bottom_line_ctr] = currently_being_pressed;

						bottom_line_ctr++;

						//if bottom line has been filled, move to next line
						if (bottom_line_ctr==16) {
							bottom_line_ctr = 0;

							//TODO: maybe clear the bottom line buffer?


							next_line(lcd);
						}

						locker0 = 0;
					}
				}
				break;
		}
	}
}


