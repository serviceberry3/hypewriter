/*
 * keys.c
 *
 *  Created on: Jan 15, 2021
 *      Author: nodog
 */

#include "../include/keys.h"

int key_lookup(int* pins, int* analog_vals) {
	int a0 = analog_vals[0];

	if (a0 < 990) {
		if (a0 > 944)
			return 'c';
		else if (a0 > 934)
			return '4';
		else if (a0 > 927)
			return 'd';
		else if (a0 > 915)
			return 'e';
		else if (a0 > 900)
			return 'x';
		else if (a0 > 885)
			return '3';
		else if (a0 > 870)
			return 's';
		else if (a0 > 840)
			return 'w';
		else if (a0 > 800)
			return 'z';
		else if (a0 > 750)
			return '2';
		else if (a0 > 670)
			return 'a';
		else if (a0 > 500)
			return 'q';
		else
			return '1';
	}

	return 0;
}




