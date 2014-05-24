#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S2,     Light,          sensorCOLORFULL)
#pragma config(Motor,  mtr_S1_C1_1,     Left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Right,         tmotorTetrix, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma platform(NXT)

#include "JoystickDriver.c"

int RightEnc;
int LeftEnc;
int Volts;
int Time;

//Distance is every 2 feet (a foam square)
int distance = 0;
int speed = 75;
bool line = false;

task main()
{
ClearTimer(T1);
ClearTimer(T2);

motor[Right] = speed;
motor[Left] = speed;

AddToDatalog(speed, speed);

while(distance <= 6){
//Incriment distance
if(SensorValue(Light) == 5 && line == false){
	distance++;
	line = true;
}
if(SensorValue(Light) != 5 && line == true){
	line = false;
}

//Datalog every 0.1 secs
while(time1(T1) < 100){
}
AddToDatalog(RightEnc, nMotorEncoder(Right));
AddToDatalog(LeftEnc, nMotorEncoder(Left));
AddToDatalog(Time, time1(T2));
AddToDatalog(Volts, nAvgBatteryLevel);
AddToDatalog(distance, distance);
ClearTimer(T1);
}

SaveNxtDatalog();
}

/*
Datalog reference:
-speed
then repeated:
-Right encoder
-Left encoder
-Total time (in mills)
-Current battery voltage
-current distance (in incriments of 2 feet)
*/