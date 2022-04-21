#pragma config(Sensor, in8,    light,          sensorReflection)
#pragma config(Sensor, dgtl1,  e_stop_touch,   sensorTouch)
#pragma config(Sensor, dgtl2,  sonar_in,       sensorSONAR_inch)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Emergency stop kill switch
task e_stop() {
	untilTouch(e_stop_touch);
	stopAllTasks();
}

bool isCloseToBox(int threshold) {
	return SensorValue[sonar_in] <= threshold;
}
bool isOffMat(int threshold) {

}
void stopMoving() {
	stopMotor(frontLeft);
	stopMotor(frontRight);
}

int sonar_threshold = 10;
task main()
{
	startTask(e_stop);
	startMotor(frontLeft);
	float test = SensorValue[light];
	while (true) {
		if (isCloseToBox(sonar_threshold)) {
			stopMoving();
		}
	}

}