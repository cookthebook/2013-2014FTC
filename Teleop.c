#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     RightLight,     sensorCOLORFULL)
#pragma config(Motor,  motorA,          Block,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     Left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Right,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Shoulder,      tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

float constant;
int spinSpeed;

task main()
{
	waitForStart();
while(true){
	getJoystickSettings(joystick);


	//Driving//
	if(!joy1Btn(07)){
		constant = 1;
		spinSpeed = 1;
	}else{
		constant = 3;
		spinSpeed = 20;
	}

	motor[Right] = abs(joystick.joy1_y1) > 10 ? (joystick.joy1_y1 * 75 / 128) / constant : 0;
	motor[Left] = abs(joystick.joy1_y2) > 10 ? (joystick.joy1_y2 * 75 / 128) / constant : 0;

	//Lift//
	if(joy1Btn(8)){
		motor[Shoulder] = -80;
	}

	if(joy1Btn(3)){
		motor[Shoulder] = 80;
	}

	if((!joy1Btn(8) && !joy1Btn(3)) || (joy1Btn(8) && joy1Btn(3))){
		motor[Shoulder] = 0;
	}


	//Spinner//
	if(joy1Btn(04)){
		motor[Spinner] = -100 / spinSpeed;
	}

	if(joy1Btn(02)){
		motor[Spinner] = 100 / spinSpeed;
	}

	if((!joy1Btn(04) && !joy1Btn(02)) || (joy1Btn(04) && joy1Btn(02))){
		motor[Spinner] = 0;
	}


	//Block Dropper//
	if(joystick.joy1_TopHat == 2){
		motor[Block] = 50;
	}

	if(joy1Btn(01)){
		motor[Block] = -50;
	}

	if((joystick.joy1_TopHat != 2 && !joy1Btn(01)) || (joystick.joy1_TopHat == 2 && joy1Btn(01))){
		motor[Block] = 0;
	}


	wait1Msec(50);
}
}
