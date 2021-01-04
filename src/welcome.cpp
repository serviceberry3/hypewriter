/*
 * welcome.cpp
 *
 *  Created on: Jan 3, 2021
 *      Author: nodog
 */

#include "../include/welcome.h"

int welcome_user(LiquidCrystal lcd) {
	while (true) {
		//clear display at set cursor at (0, 0)
		lcd.clear();

		lcd.print(welcome);
		lcd.setCursor(0, 1);
		lcd.write(byte(0));
		lcd.print(cright);

		delay(3600);


		//check if scrolling is necessary
		if (strlen(welcome) > 16 || strlen(cright) + 1 > 16) {
			for (int i = 0; i < (int)strlen(welcome) - 16; i++) {
				//Serial.println("Scrolling");
				lcd.scrollDisplayLeft();
				delay(600);
			}
		}
		delay(400);
	}

	return 0;
}




