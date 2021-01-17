/*
 * console.c
 *
 *  Created on: Jan 15, 2021
 *      Author: nodog
 */
#include "../include/console.h"
#include "../include/keys.h"
#include "../include/arduino.h"
#include "../include/circ_buffer.hh"

#define BUFF_SIZE 10


int pins[3] = {0, 1, 2};
int analog_data[3] = {0, 0, 0};

//buffer to hold chars being typed on bottom line
char bottom_line[16] = {};

//keep track of how many chars have been typed on bottom line
int bottom_line_ctr = 0;

//keep track of whether the circ buff has been filled enough to call aggregate_last_n_entries
int buff_full_enough = 0;

//how full the circular buffers are
int read_ctr = 0;

//create new circular buffer for A0 data
circular_buffer a0_buff(BUFF_SIZE);
circular_buffer a1_buff(BUFF_SIZE);


//TODO: make lcd a global

void open_console(LiquidCrystal lcd) {

	key_processor(lcd);
}

void next_line(LiquidCrystal lcd) {
	lcd.clear();
	lcd.blink();
	lcd.print(bottom_line);
	lcd.setCursor(0, 1);
}

void put_data(int* data) {
	//put passed data into the circular buffers
	a0_buff.circular_buf_put(data[0]);
	a1_buff.circular_buf_put(data[1]);

	//increment current size of the buffer (could also use fxn from the circ_buffer API)
	//TODO: swap for API call so we don't need this var
	read_ctr++;
}

void clear_keypress_buffers() {
	//clear out the keypress buffer
	a0_buff.circular_buf_reset();
	a1_buff.circular_buf_reset();
	buff_full_enough = 0;
	read_ctr = 0;
}


void key_processor(LiquidCrystal lcd) {
	lcd.clear();
	lcd.setCursor(0, 1);
	lcd.blink();

	char key_to_print = '\0';

	//start in "up" state
	int state = 0;
	char currently_being_pressed = '\0';

	//keypress confirmer for A0 pin
	int locker0 = 0;
	int queued = 0;
	int res;


	while (1) {
		//get data from all analog pins
		analog_data[0] = analogRead(A0);
		analog_data[1] = analogRead(A1);
		analog_data[2] = analogRead(A2);

		//DBUG
		//Serial.println("put into buff...");
		//Serial.println(analog_data[0]);

		currently_being_pressed = (char)key_lookup(pins, analog_data);

		//key down state, wait for key up
		switch (state) {
			//the up state
			case 0:
				//if we notice a key is now being pressed
				if (currently_being_pressed) {
					//set to down state
					state = 1;

					//start aggregating the analog input to get more accurate reading
					put_data(analog_data);

					//capture this key in case we need to use it later
					key_to_print = currently_being_pressed;

					//make sure to clear out the ctr that confirms the key has been released
					locker0 = 0;
				}
				//if nothing is being pressed but a key press is waiting to be confirmed
				else if (queued) {
					//if we see that the key has been released for some cycles
					if (locker0 >= 100) {
						//we're finally ready to finalize and print the key.

						//if the buffer's full enough (the key was pressed down for many cycles), aggregate the data for accuracy
						if (buff_full_enough) {
							//perform the aggregation
							if ((res = (int)a0_buff.aggregate_last_n_entries(5)) >= 0 && res < 990) {
								//if the aggregation was successful (didn't return -1), accept it as the new value for the key press
								analog_data[0] = res;
							}
							else if ((res = (int)a1_buff.aggregate_last_n_entries(5)) >= 0 && res < 990) {
								//if the aggregation was successful (didn't return -1), accept it as the new value for the key press
								analog_data[1] = res;
							}


							//look up the key based on the new aggregated data from the key press
							key_to_print = (char)key_lookup(pins, analog_data);

							//DBUG
							//Serial.println((int)a0_buff.aggregate_last_n_entries(5));
							//Serial.print(',');
							//Serial.println((int)a1_buff.aggregate_last_n_entries(5));
							//Serial.println(res);
						}
						//otherwise key_to_print should contain the instantaneously-looked-up char

						//print out the key that was recorded
						lcd.print(key_to_print);

						clear_keypress_buffers();

						//add letter to the bottom line buffer
						bottom_line[bottom_line_ctr] = key_to_print;

						bottom_line_ctr++;

						//if bottom line has been filled, move to next line
						if (bottom_line_ctr==16) {
							bottom_line_ctr = 0;

							//TODO: maybe clear the bottom line buffer?

							next_line(lcd);
						}

						//clear the lock ctr
						locker0 = 0;

						//no letters to print anymore
						queued = 0;
					}

					//increment the up tracker
					locker0++;
				}
				break;
			//the down state
			case 1:
				//if we notice the key is now being released
				if (!currently_being_pressed) {
					//wait for at least 50 confirming 0 readings before printing the letter
					locker0++;

					//record that we need to print this letter
					queued = 1;

					//set state to up
					state = 0;
				}
				else {
					//if we're in the middle of a key press, keep recording the analog input for aggregation
					//put incoming analog data into the appropriate circular buffer
					put_data(analog_data);
				}
				break;
		}

		if (read_ctr == 5)
			buff_full_enough = 1;
	}
}


