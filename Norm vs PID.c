#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Right,         tmotorTetrix, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma platform(NXT)

#include "JoystickDriver.c"

int avgSpeed;
bool PID;
int speed = 75;
int time = 10000;

task main()
{
nMotorEncoder(Right) = 0;
nMotorEncoder(Left) = 0;
wait1Msec(50);
ClearTimer(T1);

PID = false;
motor[Right] = speed;
motor[Left] = -speed;
while(time1(T1) < time){
}
motor[Right] = 0;
motor[Left] = 0;

avgSpeed = (nMotorEncoder(Right) + abs(nMotorEncoder(Left))) / 20;
AddToDatalog(PID, PID);
AddToDatalog(avgSpeed, avgSpeed);

nMotorPIDSpeedCtrl[Right] = mtrSpeedReg;
nMotorPIDSpeedCtrl[Left] = mtrSpeedReg;
PID = true;

nMotorEncoder(Right) = 0;
nMotorEncoder(Left) = 0;
wait1Msec(50);

ClearTimer(T1);

motor[Right] = speed;
motor[Left] = -speed;
while(time1(T1) < speed){
}
motor[Right] = 0;
motor[Left] = 0;

avgSpeed = (nMotorEncoder(Right) + abs(nMotorEncoder(Left))) / 20;
AddToDatalog(PID, PID);
AddToDatalog(avgSpeed, avgSpeed);

SaveNxtDatalog();
}