/*
 * keys.h
 *
 *  Created on: Jan 15, 2021
 *      Author: nodog
 */

#ifndef INCLUDE_KEYS_H_
#define INCLUDE_KEYS_H_

typedef struct key {
	int id;
	char letter;
} key;

//number of analog pins we're using for key read-in
#define NUM_KEY_PINS 3



//look up a key based on analog values that have been read in
int key_lookup(int* pin, int* analog_vals);



#endif /* INCLUDE_KEYS_H_ */
