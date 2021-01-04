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
	/*
	Serial.begin(9600);

	//lcd.createChar(0, cr_glyph);

	//set up the LCD's number of columns and rows
	lcd.begin(16, 2);



	lcd.print("Hello");
	//lcd.setCursor(0, 1);
	//lcd.write(byte(0));
	//lcd.print(cright);

	//delay(200);


	for (int i = 0; i < 10; i++) {
		//Serial.println("Scrolling");
		lcd.scrollDisplayLeft();
		delay(150);
	}





	switch (curr_state) {
		case INIT:
			req = welcome_user(lcd);
			break;
	}*/






	// set up the LCD's number of columns and rows:
	  lcd.begin(16, 2);
	  //lcd.setCursor(0, 0);

	  // Print a message to the LCD.
	  lcd.print("Hello, world!");
	  delay(1000);


	  for (int i = 0; i < 10; i++) {
	  		//Serial.println("Scrolling");
	  		lcd.scrollDisplayLeft();
	  		delay(150);
	  	}





	return 0;
}




/*

void setup() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //lcd.setCursor(0, 0);

  // Print a message to the LCD.
  lcd.print("Hello, world!");
  delay(1000);


  for (int i = 0; i < 10; i++) {
  		//Serial.println("Scrolling");
  		lcd.scrollDisplayLeft();
  		delay(150);
  	}



}


void loop() {

  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // delay at the end of the full loop:
  delay(1000);

}*/



