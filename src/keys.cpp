/*
 * keys.c
 *
 *  Created on: Jan 15, 2021
 *      Author: nodog
 */

#include "../include/keys.h"

//NOTE: run the program at 6.8V

int key_lookup(int* pins, int* analog_vals) {
	int a0 = analog_vals[0];
	int a1 = analog_vals[1];

	//typical is 1015-1025

	if (a0 < 990) {
		//x is 900-905
		if (a0 > 902)
			return 'x';
		//3 is 884-890
		else if (a0 > 880)
			return '3';
		//s is about 865-875
		else if (a0 > 863)
			return 's';
		//w is 842-848
		else if (a0 > 840)
			return 'w';
		//z is 809-814
		else if (a0 > 795)
			return 'z';
		//2 is 758-765
		else if (a0 > 730)
			return '2';
		//a is 674-681
		else if (a0 > 650)
			return 'a';
		//q is 506-515
		else if (a0 > 480)
			return 'q';
		//1 should be around 1-15
		else
			return '1';
	}
	if (a1 < 990) {
		if (a1 > 898)
			return 'x';
		//3 is 884-890
		else if (a1 > 880)
			return '3';
		//s is about 865-875
		else if (a1 > 863)
			return '5';
		//w is 842-848
		else if (a1 > 838)
			return 'f';
		//z is 809-814
		else if (a1 > 795)
			return 'r';
		//2 is 758-765
		else if (a1 > 730)
			return 'c';
		//a is 674-681
		else if (a1 > 650)
			return '4';
		//q is 506-515
		else if (a1 > 480)
			return 'd';
		//1 should be around 1-15
		else
			return 'e';
	}


	//otherwise nothing is being pressed
	return 0;
}




