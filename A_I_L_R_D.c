#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     RightLight,     sensorCOLORFULL)
#pragma config(Motor,  motorA,          Block,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     Left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Right,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Shoulder,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Spinner,       tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#include "JoystickDriver.c"

int normSpeed = 50;
int blockSpeed = 50;
int trans = 0;
int delay = 10000;

void placeBlock(const int forward){
	nMotorEncoder(Left) = 0;
	nMotorEncoder(Right) = 0;
	wait1Msec(50);

	motor[Right] = -normSpeed;
	motor[Left] = -normSpeed;
	while(abs(nMotorEncoder(Left)) < forward && SensorValue(IRSeeker) != 5){
	}

	if(SensorValue(IRSeeker) == 5){
		trans = 11;
	}
	else{
		while(abs(nMotorEncoder(Left)) < forward * 4 && SensorValue(IRSeeker) != 4){
		}
		if(SensorValue(IRSeeker) == 4){
			trans = 11;
		}

		if(abs(nMotorEncoder(Left)) >= forward * 4 && SensorValue(IRSeeker) != 4){
			trans = 9;
		}
	}
}



//Obstruction Code//
void OoutLowGoal(){
   if(SensorValue(RightLight) != 2 && SensorValue(RightLight) != 5){
      motor[Block] = 0;
      motor[Right] = normSpeed;
      motor[Left] = normSpeed;
   }

   if(SensorValue(RightLight) == 2 || SensorValue(RightLight) == 5){
      motor[Block] = 0;
      trans = 91;
   }
}



void Oturn(const int forward, const int turn){
	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;

	wait1Msec(50);

	motor[Right] = normSpeed;
	motor[Left] = normSpeed;

	while(abs(nMotorEncoder(Left)) < forward){
		nxtDisplayTextLine(1, "EncL=%d", nMotorEncoder[Right]);
    nxtDisplayTextLine(2, "EncL=%d", nMotorEncoder[Left]);
	}
	motor[Left] = 0;
	motor[Right] = 0;

	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;

	wait1Msec(50);

	motor[Right] = 0;
	motor[Left] = normSpeed;

	while(abs(nMotorEncoder(Left)) < turn){
	  nxtDisplayTextLine(1, "EncL=%d", nMotorEncoder[Right]);
    nxtDisplayTextLine(2, "EncL=%d", nMotorEncoder[Left]);
	}

	trans = 92;
}



void Ocenter(){
	if(SensorValue(RightLight) != 2 && SensorValue(RightLight) != 5){
		motor[Right] = normSpeed;
		motor[Left] = normSpeed;
	}

	if(SensorValue(RightLight) == 2 || SensorValue(RightLight) == 5){
		trans = 93;
	}
}



void OgetOnPlatform(const int turn, const int forward){
	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;

	wait1Msec(50);

	motor[Right] = -normSpeed;
	motor[Left] = 0;

	while(abs(nMotorEncoder(Right)) < turn){
	}
	motor[Right] = 0;
	motor[Left] = 0;

	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;
	wait1Msec(50);

	motor[Right] = normSpeed;
	motor[Left] = normSpeed;

	while(abs(nMotorEncoder(Right)) < forward){
	}

	motor[Right] = 0;
	motor[Left] = 0;
	wait1Msec(30000);
}


//Normal Code//


void retractStick(const int time){
	trans = 1;
	motor[Block] = blockSpeed;
	motor[Right] = 0;
	motor[Left] = 0;
	wait1Msec(time);

	motor[Block] = -blockSpeed;
	motor[Right] = 0;
	motor[Left] = 0;
	wait1Msec(time);
}



void outLowGoal(){
   if(SensorValue(RightLight) != 2 && SensorValue(RightLight) != 5){
      motor[Block] = 0;
      motor[Right] = -normSpeed;
      motor[Left] = -normSpeed;
   }

   if(SensorValue(RightLight) == 2 || SensorValue(RightLight) == 5){
      motor[Block] = 0;
      trans = 2;
   }
}



void turn(const int forward, const int turn){
	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;

	wait1Msec(50);

	motor[Right] = -normSpeed;
	motor[Left] = -normSpeed;

	while(abs(nMotorEncoder(Left)) < forward){
		nxtDisplayTextLine(1, "EncR=%d", nMotorEncoder[Right]);
    nxtDisplayTextLine(2, "EncL=%d", nMotorEncoder[Left]);
	}
	motor[Left] = 0;
	motor[Right] = 0;

	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;

	wait1Msec(50);

	motor[Right] = 0;
	motor[Left] = -normSpeed;

	while(abs(nMotorEncoder(Left)) < turn){
	  nxtDisplayTextLine(1, "EncL=%d", nMotorEncoder[Right]);
    nxtDisplayTextLine(2, "EncL=%d", nMotorEncoder[Left]);
	}

	trans = 3;
}



void center(){
	if(SensorValue(RightLight) != 2 && SensorValue(RightLight) != 5){
		motor[Right] = -normSpeed;
		motor[Left] = -normSpeed;
	}

	if(SensorValue(RightLight) == 2 || SensorValue(RightLight) == 5){
		trans = 4;
	}
}



void getOnPlatform(const int turn, const int forward){
	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;

	wait1Msec(50);

	motor[Right] = 0;
	motor[Left] = normSpeed;

	while(abs(nMotorEncoder(Left)) < turn){
	}
	motor[Right] = 0;
	motor[Left] = -normSpeed;

	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;
	wait1Msec(50);

	motor[Right] = normSpeed;
	motor[Left] = normSpeed;

	while(abs(nMotorEncoder(Left)) < forward){
	}

	motor[Right] = 0;
	motor[Left] = 0;
	wait1Msec(30000);
}


task main(){
	waitForStart();
	wait1Msec(delay);
	nMotorEncoder(Right) = 0;
	nMotorEncoder(Left) = 0;
	wait1Msec(50);
while(true){
   if(trans == 0) placeBlock(4032);//5040
   if(trans == 11) retractStick(500);
   if(trans == 1) outLowGoal();
   if(trans == 2) turn(500, 3500);//720, 3120
   if(trans == 3) center();
   if(trans == 4) getOnPlatform(2500, 4000);//2160, 5760

   //obstruction code//
   if(trans == 9) OoutLowGoal();
   if(trans == 91) Oturn(500, 3250);//720, 3120
   if(trans == 92) Ocenter();
   if(trans == 93) OgetOnPlatform(1800, 4500);//2160, 5760

}
}
