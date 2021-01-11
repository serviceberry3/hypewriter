task main()
{
	//test sliding carriage one character

	//verify that prog is running
	nxtDisplayString(0, "Hello World!");

	//set motor on port A to move 20 clicks, turn it on at low speed, and wait
	nMotorEncoderTarget[motorA] = 20;
	motor[motorA] = 1;
	wait1Msec(100);

	//set motor on port B to move 20 clicks, turn it on at low speed, and wait
	nMotorEncoderTarget[motorB] = 20;
	motor[motorB] = -1;
	wait1Msec(100);
}
