#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "../include/hypeglyphs.h"
#include "../include/state_mach.h"
#include "../include/welcome.h"
#include <SPI.h>
#include <SD.h>
#include "../include/console.h"

// initialize the library with the numbers of the interface pins
const int rs = 4, en = 5, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


volatile state curr_state = INIT;

//user requests
int req;

File myFile;

int b1 = A0;
int buttonPin = 3;


void pin_ISR() {
	Serial.println("Interrupt");
	int buttonState = digitalRead(buttonPin);
	Serial.println(buttonState);
	if (buttonState) {
		Serial.println("setting to typing");
		curr_state = TYPING;
	}
}


int main (void) {
	init();


	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(buttonPin, INPUT);

	attachInterrupt(1, pin_ISR, CHANGE);


	Serial.begin(9600);


	//DBUG ANALOG READINGS

	while(1) {
		Serial.println(analogRead(A1));
		//Serial.println(digitalRead(buttonPin));
	}


	//make sure SD module initializes successfully, otherwise print error and hang
	if (!SD.begin(10)) {
		Serial.println("initialization failed!");
		while (1);
	}

	//open a test file for writing. note that only one file can be open at a time, so have to close this one before opening another.
	myFile = SD.open("test.txt", FILE_WRITE);


	//if the file opened okay, write to it:
	if (myFile) {
		Serial.print("Writing to test.txt...");
		myFile.println("This is a test file :)");
		myFile.println("testing 1, 2, 3.");


		for (int i = 0; i < 20; i++) {
			myFile.println(i);
		}


		//close the test file:
		myFile.close();
		Serial.println("done.");
	}


	else {
		// if the file didn't open, print an error:
		Serial.println("error opening test.txt");
	}



	lcd.createChar(0, cr_glyph);

	//set up the LCD's number of columns and rows
	lcd.begin(16, 2);


	while (1) {
		switch (curr_state) {
			case INIT:
				req = welcome_user(lcd);
				break;
			case TYPING:
				open_console(lcd);
				break;
		}
	}


	return 0;
}




